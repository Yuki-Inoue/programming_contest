#include <iostream>
#include <vector>
#include <string>

using namespace std;

string found;

long char_to_int(char c){
    string::size_type pos = found.find(c);
    if (pos == string::npos) {
        found.push_back(c);
        return found.size() - 1;
    }
    return pos;
}


int main(){
    int N,NC;
    cin >> N >> NC;


    long key = 0;
    for (int i=1; i<N; ++i) {
        char c; cin >> c;
        key *= NC;
        key += char_to_int(c);
    }

    long modder = 1;
    for (long i=1; i<N; ++i)
        modder *= NC;

    char c;
    vector<bool> substrs(modder*NC, false);
    long count = 0;
    while (cin >> c) {
        key *= NC;
        key += char_to_int(c);

        if (!substrs[key]) {
            substrs[key] = true;
            ++count;
        }

        key %= modder;
    }

    cout << count << endl;
}
