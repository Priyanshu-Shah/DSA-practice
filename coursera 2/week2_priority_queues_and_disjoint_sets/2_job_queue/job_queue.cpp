#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Thread{
  long long next_free_time;
  int index;
  // custom comparator operator because when we push a Thread element to pq, it will try to heapify it by checking a greater than condition, so for struct Thread, we will have to define what operator > means
  bool operator>(const Thread &other) const {
        if (next_free_time == other.next_free_time)
            return index > other.index;
        return next_free_time > other.next_free_time;
    }
};

class JobQueue {
 private:
  int num_workers_;
  vector<int> jobs_;
  vector<int> assigned_workers_;
  vector<long long> start_times_;

  void WriteResponse() const {
    for (int i = 0; i < jobs_.size(); ++i) {
      cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
    }
  }

  void ReadData() {
    int m;
    cin >> num_workers_ >> m;
    jobs_.resize(m);
    for(int i = 0; i < m; ++i)
      cin >> jobs_[i];
  }

  void AssignJobs() {
    // TODO: replace this code with a faster algorithm.
    assigned_workers_.resize(jobs_.size());
    start_times_.resize(jobs_.size());
    //vector<long long> next_free_time(num_workers_, 0);
    // for (int i = 0; i < jobs_.size(); ++i) {
    //   int duration = jobs_[i];
    //   int next_worker = 0;
    //   for (int j = 0; j < num_workers_; ++j) {
    //     if (next_free_time[j] < next_free_time[next_worker])
    //       next_worker = j;
    //   }
    //   assigned_workers_[i] = next_worker;
    //   start_times_[i] = next_free_time[next_worker];
    //   next_free_time[next_worker] += duration;
    // }

    //generating a minHeap pq of elements of struct Thread  
    priority_queue<Thread, vector<Thread>, greater<Thread>> pq;

    for(int i =0; i<num_workers_; i++){
      pq.push({0,i});
    }

    for(int i = 0; i<jobs_.size(); i++){
      Thread current = pq.top();
      pq.pop();
      assigned_workers_[i] = current.index;
      start_times_[i] = current.next_free_time;
      current.next_free_time += jobs_[i];
      pq.push(current);
    }
  }

 public:
  void Solve() {
    ReadData();
    AssignJobs();
    WriteResponse();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  JobQueue job_queue;
  job_queue.Solve();
  return 0;
}
