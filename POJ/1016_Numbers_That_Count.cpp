#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> inventory(const string &str){
    vector<int> counts(10,0);
    for (int i=0; i<str.size(); ++i)
        counts[str[i]-'0']++;

    return counts;
}

string string_of_counts(const vector<int> &counts){
    string ret;
    for (int i=0; i<10; ++i)
        if (counts[i]) {
            ostringstream oss;
            oss << counts[i];
            ret += oss.str();
            ret.push_back(i+'0');
        }
    return ret;
}

int main(){
    string number0;
    while (cin >> number0 && number0[0] != '-') {
        typedef vector<vector<int> > History;
        typedef History::const_iterator Iterator;
        History numbers;

        vector<int> counts = inventory(number0);
        string inv_string = string_of_counts(counts);
        if (inv_string == number0) {
            printf("%s is self-inventorying\n", number0.c_str());
            continue;
        }

        numbers.push_back(counts);
        int i;
        for (i=1; i<15; ++i) {
            counts = inventory(inv_string);
            Iterator s = numbers.begin();
            Iterator t = numbers.end();
            Iterator it = find(s, t, counts);
            if (it != t) {
                if (it == t - 1)
                    printf("%s is self-inventorying after %d steps\n", number0.c_str(), i);
                else
                    printf("%s enters an inventory loop of length %d\n", number0.c_str(),
                           static_cast<int>(t - it));

                break;
            }
            numbers.push_back(counts);
            inv_string = string_of_counts(counts);
        }

        if (i==15) {
            printf("%s can not be classified after 15 iterations\n", number0.c_str());
        }
    }
}
