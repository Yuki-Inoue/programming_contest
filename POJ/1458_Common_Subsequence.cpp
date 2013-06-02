#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    string str1, str2;
    while (cin >> str1 >> str2) {
        vector<vector<int> > dp(str1.size()+1, vector<int>(str2.size()+1,0));
        for (int i=1; i<=str1.size(); ++i)
            for (int j=1; j<=str2.size(); ++j)
                dp[i][j] =
                max((str1[i-1] == str2[j-1]) + dp[i-1][j-1],
                    max(dp[i-1][j], dp[i][j-1]));
        cout << dp[str1.size()][str2.size()] << endl;
    }
}
