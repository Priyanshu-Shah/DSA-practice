#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string InverseBWT(const string& bwt) {
  int n = bwt.size();
  string text;
  text.resize(n);
  vector<int> count(256, 0);
  vector<int> rank(256, 0);
  vector<int> next(n, 0);

  // Count occurrences of each character in bwt
  for (int i = 0; i < n; ++i) {
    count[bwt[i]]++;
  }

  // Compute the starting position of each character in the sorted array
  int cumulative = 0;
  for (int i = 0; i < 256; ++i) {
    int temp = count[i];
    rank[i] = cumulative;
    cumulative += temp;
  }

  // Fill the 'next' array
  for (int i = 0; i < n; ++i) {
    int char_index = bwt[i];
    next[rank[char_index]++] = i;
  }

  int current_index = 0;
  for (int i = 0; i < n; ++i) {
    if (bwt[i] == '$') {
      current_index = i;
      break;
    }
  }

  // Reconstruct the text
  for (int i = n - 1; i >= 0; --i) {
    text[i] = bwt[current_index];
    current_index = next[current_index];
  }

  return text;
}

int main() {
  string bwt;
  cin >> bwt;
  cout << InverseBWT(bwt) << endl;
  return 0;
}
