#include <iostream>
#include <utility>
#include <vector>
#include <string>

using namespace std;


int main(){
    int n;
    while (cin >> n && n) {
        vector<int> perm(n);
        for (int i=0; i<n; ++i) {
            cin >> perm[i];
            --perm[i];
        }

        vector<vector<int> *> subperms;
        vector<pair<int,int> > key(n);
        {
            vector<bool> used(n,false);
            for (int i=0; i<n; ++i) {
                int current = i;
                vector<int> *candidates = new vector<int>;
                while (!used[current]) {
                    used[current] = true;
                    key[current].first = subperms.size();
                    key[current].second = candidates->size();
                    candidates->push_back(current);
                    current = perm[current];
                }
                if (candidates->empty()) {
                    delete candidates;
                }
                else {
                    subperms.push_back(candidates);
                }
            }
        }

        int k;
        while (cin >> k && k) {
            cin.get();
            string message;
            getline(cin, message);
            string encripted(n, ' ');
            for (int i=0; i<message.size(); ++i) {
                vector<int> *subperm = subperms[key[i].first];
                int dst = subperm->
                at((key[i].second + k) % subperm->size());
                encripted[dst] = message[i];
            }
            cout << encripted << endl;
        }
        cout << endl;

        // end operations
        for (int i=0; i<subperms.size(); ++i) {
            delete subperms[i];
        }
    }
}
