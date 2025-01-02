#include <iostream>
#include <vector>
using namespace std;

int compute_min_refills(int n, int dist, int tank, vector<int> & stops) {
    int count = 0;
    int refill = 0;
    int current = 0;
    while(current < dist){
        while(refill < n && stops[refill] <= current + tank){
            refill++;
        }
        if(current == stops[refill-1]){
            return -1;
        }
        if(refill < n){
            current = stops[refill-1];
            count++;
        }
        else{
            current = dist;
        }
    }
    return count-1;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
    for (size_t i = 0; i < n; ++i){
        cin >> stops.at(i);
    }
    stops[n] = d;
    cout << compute_min_refills(n, d, m, stops) << "\n";

    return 0;
}
