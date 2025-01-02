#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    long long bucket_count;
    vector<list<string>> hash_table;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = (hash * multiplier + s[i]) % prime;
        return hash % bucket_count;
    }

public:
    explicit QueryProcessor(long long bucket_count): bucket_count(bucket_count), hash_table(bucket_count) {}

    Query readQuery() const{
        Query query;
        cin >> query.type;
        if (query.type != "check")
            cin >> query.s;
        else
            cin >> query.ind;
        return query;
    }

    void writeSearchResult(bool was_found) const {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        if (query.type == "check") {
            if(hash_table[query.ind].empty()){
                cout << "\n";
            }
            else{
                for(const string &str: hash_table[query.ind]){
                    cout << str << " ";
                }
                cout << "\n";
            }
        } 
        else {
            // vector<string>::iterator it = find(elems.begin(), elems.end(), query.s);
            // if (query.type == "find")
            //     writeSearchResult(it != elems.end());
            // else if (query.type == "add") {
            //     if (it == elems.end())
            //         elems.push_back(query.s);
            // } else if (query.type == "del") {
            //     if (it != elems.end())
            //         elems.erase(it);
            // }
            size_t bucket = hash_func(query.s);
            list<string> &chain = hash_table[bucket];
            auto it = find(chain.begin(), chain.end(), query.s);
            if(query.type == "find"){
                writeSearchResult(it != chain.end());
            } 
            else if (query.type == "add") {
                if (it == chain.end()) {
                    chain.push_front(query.s); // Insert at the beginning
                }
            } 
            else if (query.type == "del") {
                if (it != chain.end()) {
                    chain.erase(it);
                }
            }
        }
    }

    void processQueries() {
        long long n;
        cin >> n;
        for (size_t i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    long long bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
