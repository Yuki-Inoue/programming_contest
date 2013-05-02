#include <vector>
#include <functional>
#include <string>
#include <iostream>

using namespace std;

vector<string> dictionary(10000);

struct Compare : std::binary_function<const string &, const string &, bool> {
    bool operator()(const string &str1, const string &str2){
        return str1.size() < str2.size();
    }
};

bool match_by_insert(const string &shorter, const string &longer){
    bool inserted = false;
    for (int i=0; i<shorter.size(); ) {
        if (shorter[i] != longer[i+inserted]) {
            if (inserted) {
                return false;
            }
            inserted = true;
        }
        else
            ++i;
    }
    return true;
}

int replacing_distance(const string &str1, const string &str2){
    int count = 0;
    for (int i=0; i<str1.size(); ++i) {
        if (str1[i] != str2[i]) {
            ++count;
        }
    }
    return count;
}

bool check_match(const string &str1, const string &str2){
    if (str1.size() == str2.size()) {
        return replacing_distance(str1,str2) == 1;
    }
    if (str1.size() +1 == str2.size()) {
        return match_by_insert(str1,str2);
    }
    if (str1.size() == str2.size() + 1) {
        return match_by_insert(str2, str1);
    }
    return false;
}

int main(){
    int di = 0;
    string buf;
    while (true) {
        cin >> buf;
        if(buf == "#")
            break;
        dictionary[di++].swap(buf);
    }
    while (true) {
        cin >> buf;
        if (buf == "#")
            break;
        vector<int> candidates;
        bool exact = false;
        for (int i=0; i<di; ++i) {
            if (dictionary[i] == buf) {
                printf("%s is correct\n", buf.c_str());
                exact = true;
                break;
            }
            if(check_match(dictionary[i], buf)){
                candidates.push_back(i);
            }
        }
        if (!exact) {
            printf("%s:", buf.c_str());
            for (int i=0; i<candidates.size(); ++i) {
                printf(" %s", dictionary[candidates[i]].c_str());
            }
            printf("\n");
        }
    }
}
