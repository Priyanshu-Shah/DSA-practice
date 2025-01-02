// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;
// typedef unsigned long long ull;

// struct Data {
//     string pattern, text;
// };

// Data read_input() {
//     Data data;
//     cin >> data.pattern >> data.text;
//     return data;
// }

// void print_occurrences(const vector<int>& output) {
//     for (size_t i = 0; i < output.size(); ++i)
//         cout << output[i] << " ";
//     cout << "\n";
// }

// vector<int> get_occurrences(const Data& input) {
//     const string& s = input.pattern, t = input.text;
//     vector<int> ans;
//     // for (size_t i = 0; i + s.size() <= t.size(); ++i)
//     //     if (t.substr(i, s.size()) == s)
//     //         ans.push_back(i);
//     // return ans;
//     int h=1;
//     int hash_pattern = 0;
//     int hash_text = 0;
//     for(int i=0; i<s.size() - 1 ;i++){
//         h = (h*263)%1000000007;
//     }
//     for(int i=0; i<s.size(); i++){
//         hash_pattern = (263*hash_pattern + s[i])%1000000007;
//         hash_text = (263*hash_text + t[i])%1000000007;
//     }

//     for (int i = 0; i <= t.size() - s.size(); ++i) {
//         // Check if hashes match
//         if (hash_pattern == hash_text) {
//             // Check character by character to avoid collisions
//             bool match = true;
//             for (int j = 0; j < s.size(); ++j) {
//                 if (t[i + j] != s[j]) {
//                     match = false;
//                     break;
//                 }
//             }
//             if (match)
//                 ans.push_back(i);
//         }

//         // Update hash_text for the next substring
//         if (i < t.size() - s.size()) {
//             hash_text = (263 * (hash_text - t[i] * h) + t[i + s.size()]) % 1000000007;
//             if (hash_text < 0)
//                 hash_text += 1000000007;
//         }
//     }

//     return ans;
// }


// int main() {
//     ios_base::sync_with_stdio(false);
//     print_occurrences(get_occurrences(read_input()));
//     return 0;
// }

#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef unsigned long long ull;

struct Data {
    string pattern, text;
};

Data read_input() {
    Data data;
    cin >> data.pattern >> data.text;
    return data;
}

void print_occurrences(const vector<int>& output) {
    for (size_t i = 0; i < output.size(); ++i)
        cout << output[i] << " ";
    cout << "\n";
}

vector<int> get_occurrences(const Data& input) {
    const string& s = input.pattern, t = input.text;
    vector<int> ans;

    int prime = 1000000007;
    int multiplier = 263;

    int pattern_length = s.size();
    int text_length = t.size();

    // Calculate initial hash values for pattern and the first substring of text
    int hash_pattern = 0;
    int hash_text = 0;
    int h = 1;

    // Calculate h as multiplier^(pattern_length - 1) % prime
    for (int i = 0; i < pattern_length - 1; ++i)
        h = (h * multiplier) % prime;

    // Calculate the initial hash values for pattern and the first substring of text
    for (int i = 0; i < pattern_length; ++i) {
        hash_pattern = (multiplier * hash_pattern + s[i]) % prime;
        hash_text = (multiplier * hash_text + t[i]) % prime;
    }

    // Slide over the text to find matches using Rabin-Karp algorithm
    for (int i = 0; i <= text_length - pattern_length; ++i) {
        // Check if hashes match before doing character-by-character comparison
        if (hash_pattern == hash_text) {
            bool match = true;
            for (int j = 0; j < pattern_length; ++j) {
                if (t[i + j] != s[j]) {
                    match = false;
                    break;
                }
            }
            if (match)
                ans.push_back(i);
        }

        // Update hash_text for the next substring using rolling hash technique
        if (i < text_length - pattern_length) {
            hash_text = (multiplier * (hash_text - t[i] * h) + t[i + pattern_length]) % prime;
            if (hash_text < 0)
                hash_text += prime;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    print_occurrences(get_occurrences(read_input()));
    return 0;
}
