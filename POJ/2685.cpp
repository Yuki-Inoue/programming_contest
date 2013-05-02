#include <iostream>
#include <string>

using namespace std;

int parser(const string &mxci){
    int sum = 0;
    int prefix = 1;
    for (int i=0; i<mxci.size(); ++i) {
        switch (mxci[i]) {
            case 'm':
                sum += 1000*prefix;
                prefix = 1;
                break;
            case 'c':
                sum += 100 * prefix;
                prefix = 1;
                break;
            case 'x':
                sum += 10 * prefix;
                prefix = 1;
                break;
            case 'i':
                sum += prefix;
                prefix = 1;
                break;
            default:
                prefix = mxci[i] - '0';
                break;
        }
    }
    return sum;
}


void try_add(string &str, char c, int v){
    switch (v) {
        case 0:
            break;
        case 1:
            str.push_back(c);
            break;
        default:
            str.push_back(v+'0');
            str.push_back(c);
            break;
    }
}

string to_string(int n){
    string ret;
    try_add(ret, 'm', n/1000);
    n %= 1000;
    try_add(ret, 'c', n/100);
    n %= 100;
    try_add(ret, 'x', n/10);
    n %= 10;
    try_add(ret, 'i', n);
    return ret;
}

int main(){
    int n;
    for (cin >> n; n--; ) {
        string mxci1, mxci2;
        cin >> mxci1 >> mxci2;
        int i1 = parser(mxci1), i2 = parser(mxci2);
//        cerr << i1 << " " << i2 << endl;
        cout << to_string(parser(mxci1) + parser(mxci2)) << endl;
    }
}
