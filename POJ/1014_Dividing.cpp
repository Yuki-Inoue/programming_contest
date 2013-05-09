
#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> marbles(6);

const char *cant_be_divided = "Can't be divided.";
const char *can_be_divided = "Can be divided.";

std::istream &parse_marbles(){
    for (int i=0; i<6; ++i)
        std::cin >> marbles[i];
    return std::cin;
}

int main(){
    int counter = 0;
    while(parse_marbles() && accumulate(marbles.begin(), marbles.end(), 0)){
        printf("Collection #%d:\n", ++counter);

        int sum = 0;
        for (int i=0; i<6; ++i)
            sum += (i+1) * marbles[i];

        if (sum % 2) {
            puts(cant_be_divided);
            puts("");
            continue;
        }

        const int partial_sum = sum/2;
        std::vector<std::vector<int> > dp(7, std::vector<int>(partial_sum+1, -1));

        dp[0][0] = 0;
        for (int i=1; i<7; ++i) for(int j=0; j<=partial_sum; ++j)
            dp[i][j] =
            dp[i-1][j] >= 0 ? marbles[i-1] :
            j-i >= 0 ? dp[i][j-i] - 1:
            -1;

        puts(dp[6][partial_sum] >= 0 ? can_be_divided : cant_be_divided );
        puts("");
    }
}
