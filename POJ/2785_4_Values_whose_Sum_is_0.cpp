#include <cstdio>
#include <vector>
#include <algorithm>

int main(){
    int n;
    scanf(" %d", &n);
    std::vector<long> lists[4];
    for (int i=0; i<4; ++i) {
        lists[i].reserve(n);
    }
    for (int i=0; i<n; ++i) {
        for (int i=0; i<4; ++i) {
            long e;
            scanf(" %ld", &e);
            lists[i].push_back(e);
        }
    }

    std::vector<long> sums[2];
    for (int i=0; i<2; ++i) {
        sums[i].reserve((long)n*n);
        for (int j=0; j<n; ++j)
            for (int k=0; k<n; ++k)
                sums[i].push_back(lists[2*i][j]+lists[2*i+1][k]);
        sort(sums[i].begin(), sums[i].end());
    }

    std::vector<long>::const_iterator it1, it2;
    std::vector<long>::const_reverse_iterator rit1, rit2;

    it1 = sums[0].begin();
    rit1 = sums[1].rbegin();
    long long count = 0;
    while (it1 != sums[0].end() && rit1 != sums[1].rend()) {
        long sum = *it1 + *rit1;
        if (sum > 0)
            ++rit1;
        else if (sum < 0){
            ++it1;
        }
        else {
            it2 = it1; rit2 = rit1;
            while (++it1 != sums[0].end() && !(*it1 + *rit1));
            while (++rit1 != sums[1].rend() && !(*it2 + *rit1));
            count += (it1 - it2) * (rit1 - rit2);
        }
    }
    printf("%lld\n", count);
}
