#include <algorithm>
#include <cassert>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int const Letters = 4;
int const NA = -1;

typedef map<char, int> edges; 
typedef vector<edges> trie;

struct Node{
	int next[Letters];
	Node(){
		fill(next, next + Letters, NA);
	}
  bool isLeaf () const{
	  return (next[0] == NA && next[1] == NA && next[2] == NA && next[3] == NA);
	}
};

int letterToIndex (char letter){
	switch (letter){
		case 'A': return 0; break;
		case 'C': return 1; break;
		case 'G': return 2; break;
		case 'T': return 3; break;
		default: assert (false); return -1;
	}
}

vector <int> solve (const string& text, int n, const vector <string>& patterns){
	vector <int> result;
  trie t;
  t.push_back(edges());

  for(string pattern : patterns){
	pattern += '$';
    int starting_node = 0;
    for(char c: pattern){
      if(t[starting_node].find(c) != t[starting_node].end()){ //Because the find method returns either the iterator of found key, or it return itrator of element past the last element (accessed by end() method)
        starting_node = t[starting_node][c]; //If already present then next node is the index at that symbols stored map
      }
      else{
        t[starting_node].insert({c,t.size()});
        starting_node = t.size();
        t.push_back(edges());
      }
    }
  }

  for(int i=0; i<text.length(); i++){
    int starting_node = 0;
    int j = i;
    while(j<text.length()){
      char c = text[j];
      if(t[starting_node].find(c) != t[starting_node].end()){
        starting_node = t[starting_node][c];
        if(t[starting_node].find('$') != t[starting_node].end()){ //meaning the pattern has been found
          result.push_back(i);
          break;
        }
        j++;
      }
      else{
        break;
      }
    }
  }


	return result;
}

int main(){
	string t;
	cin >> t;
	int n;
	cin >> n;

	vector <string> patterns (n);
	for(int i = 0; i < n; i++){
		cin >> patterns[i];
	}

	vector <int> ans;
	ans = solve (t, n, patterns);

	for (int i = 0; i < (int) ans.size (); i++){
		cout << ans[i];
		if (i + 1 < (int) ans.size ()){
			cout << " ";
		}
		else{
			cout << endl;
		}
	}
	return 0;
}
