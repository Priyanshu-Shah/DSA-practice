#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Preprocess the Burrows-Wheeler Transform bwt of some text
// and compute as a result:
//   * starts - for each character C in bwt, starts[C] is the first position 
//       of this character in the sorted array of 
//       all characters of the text.
//   * occ_count_before - for each character C in bwt and each position P in bwt,
//       occ_count_before[C][P] is the number of occurrences of character C in bwt
//       from position 0 to position P inclusive.
void PreprocessBWT(const string& bwt,  map<char, int>& starts, map<char, vector<int> >& occ_count_before) {
  int n = bwt.size();
  map<char,int> count;
  for(char c: bwt){
    if(occ_count_before.find(c) == occ_count_before.end()){
      occ_count_before[c] = vector<int>(n+1,0);
    }
  }

  for (int i = 0; i < n; ++i) {
    count[bwt[i]]++;
    for (auto& entry : occ_count_before) {
      entry.second[i + 1] = entry.second[i] + (bwt[i] == entry.first ? 1 : 0);
    }
  }

  int cumulative_count = 0;
  for (auto& entry : count) {
    starts[entry.first] = cumulative_count;
    cumulative_count += entry.second;
  }
}

// Compute the number of occurrences of string pattern in the text
// given only Burrows-Wheeler Transform bwt of the text and additional
// information we get from the preprocessing stage - starts and occ_counts_before.
int CountOccurrences(const string& pattern, const string& bwt, const map<char, int>& starts, const map<char, vector<int> >& occ_count_before) {
  int top = 0;
  int bottom = bwt.size() - 1;

  for (int i = pattern.size() - 1; i >= 0; --i) {
    char symbol = pattern[i];
    if (occ_count_before.find(symbol) != occ_count_before.end()) {
      top = starts.at(symbol) + occ_count_before.at(symbol)[top];
      bottom = starts.at(symbol) + occ_count_before.at(symbol)[bottom + 1] - 1;

      if (top > bottom) {
          return 0;
      }
    } 
    else {
      return 0;
    }
  }

  return bottom - top + 1;
}
     

int main() {
  string bwt;
  cin >> bwt;
  int pattern_count;
  cin >> pattern_count;
  // Start of each character in the sorted list of characters of bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, int> starts;
  // Occurrence counts for each character and each position in bwt,
  // see the description in the comment about function PreprocessBWT
  map<char, vector<int> > occ_count_before;
  // Preprocess the BWT once to get starts and occ_count_before.
  // For each pattern, we will then use these precomputed values and
  // spend only O(|pattern|) to find all occurrences of the pattern
  // in the text instead of O(|pattern| + |text|).
  PreprocessBWT(bwt, starts, occ_count_before);
  for (int pi = 0; pi < pattern_count; ++pi) {
    string pattern;
    cin >> pattern;
    int occ_count = CountOccurrences(pattern, bwt, starts, occ_count_before);
    cout << occ_count << " ";
  }
  cout << endl;
  return 0;
}
