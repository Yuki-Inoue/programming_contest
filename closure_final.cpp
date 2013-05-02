/*
 given a lisp like expression yet some parentheses don't match.
 find the parenthesis-matching longest substring's non-space length.
 e.g.
 [](abc {] aoij())
 -> 6
 (((abc)))
 --> 9


 INPUT: T: int, li : lines of the code.
 T
 l1
 l2
 ...
 lT
 */



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

/*
 consider all that every separator
 is interleaved by string,
 possibly of 0 length.
 */


inline bool pmatch(char p1, char p2){
    switch (p1) {
        case '(':
            return p2 == ')';
        case '{':
            return p2 == '}';
        case '[':
            return p2 == ']';
        default:
            assert (false);
            break;
    }
    return false;
}

void clear_stack (int &max_length, vector<int> &valid_strings, vector<char> &separators){
    separators.clear();
    for (vector<int>::const_iterator it = valid_strings.begin(); it != valid_strings.end(); ++it) {
        max_length = max(max_length, *it);
    }
    valid_strings.clear();
    valid_strings.push_back(0);
}

int solve(const string &code){
    int max_length = 0;
    vector<int> valid_strings;
    vector<char> separators;
    valid_strings.push_back(0);
    for (string::const_iterator it = code.begin(); it!=code.end(); ++it) {
        switch (*it) {
            case ' ':
                break;
            case '[':
            case '(':
            case '{':
                separators.push_back(*it);
                valid_strings.push_back(0);
                break;
            case ']':
            case ')':
            case '}':
                if(!separators.empty() && pmatch(separators.back(),*it)) {
                    separators.pop_back();
                    int inner_string = valid_strings.back();
                    valid_strings.pop_back();
                    valid_strings.back() += inner_string + 2;
                }
                else
                    clear_stack(max_length, valid_strings, separators);
                break;
            default:
                valid_strings.back() += 1;
                break;
        }
    }
    clear_stack(max_length, valid_strings, separators);
    return max_length;
}

int main(){
    int T;
    cin >> T;
    string dummy;
    getline(cin, dummy); // remove the tailing \n
    for (; T--; ) {
        string code;
        getline(cin, code);
        cout << solve(code) << endl;
    }
}
