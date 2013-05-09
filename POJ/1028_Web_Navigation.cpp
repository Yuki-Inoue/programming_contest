#include <iostream>
#include <vector>
#include <string>

using namespace std;

const string ignored = "Ignored";

int main(){
    vector<string> forward;
    forward.reserve(100);
    vector<string> back;
    back.reserve(100);

    string current = "http://www.acm.org/";
    string command;
    while (cin >> command && command != "QUIT") {
        if (command == "VISIT") {
            back.push_back("");
            back.back().swap(current);
            forward.clear();
            cin >> current;
            cout << current << endl;
        }
        else if (command == "FORWARD") {
            if (forward.empty()) {
                cout << ignored << endl;
                continue;
            }
            back.push_back("");
            back.back().swap(current);
            current.swap(forward.back());
            forward.pop_back();
            cout << current << endl;
        }
        else {
            if (back.empty()) {
                cout << ignored << endl;
                continue;
            }
            forward.push_back("");
            forward.back().swap(current);
            current.swap(back.back());
            back.pop_back();
            cout << current << endl;
        }
    }
}
