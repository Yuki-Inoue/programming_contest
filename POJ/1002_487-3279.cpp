#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int alpha_to_int(char c){
    switch (c) {
        case 'A':
        case 'B':
        case 'C':
            return 2;
        case 'D':
        case 'E':
        case 'F':
            return 3;
        case 'G':
        case 'H':
        case 'I':
            return 4;
        case 'J':
        case 'K':
        case 'L':
            return 5;
        case 'M':
        case 'N':
        case 'O':
            return 6;
        case 'P':
        case 'R':
        case 'S':
            return 7;
        case 'T':
        case 'U':
        case 'V':
            return 8;
        case 'W':
        case 'X':
        case 'Y':
            return 9;
    }
}

int main(){
    int L;
    map<string,int> counts;
    for (cin >> L; L--; ) {
        string line;
        cin >> line;
        string key;
        for (int i=0; i<line.size(); ++i) {
            if (line[i] == '-') {
                continue;
            }
            if ('0' <= line[i] && line[i] <= '9') {
                key.push_back(line[i]);
            }
            else {
                key.push_back(alpha_to_int(line[i])+'0');
            }
        }
        counts[key]++;
    }
    map<string,int>::iterator it;
    bool printed = false;
    for (it = counts.begin(); it!=counts.end(); ++it) {
        if (it->second > 1) {
            printed = true;
            string str = it->first;
            str.insert(3,"-");
            cout << str << " " << it->second << endl;
        }
    }
    if (!printed) {
        cout << "No duplicates." << endl;
    }
}
