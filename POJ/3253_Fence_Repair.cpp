#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> planks(N);
    for (int i=0; i<N; ++i)
        cin >> planks[i];

    greater<long long> greater_comp;

    make_heap(planks.begin(), planks.end(), greater_comp);

    long long sum = 0;
    while (planks.size() > 1) {
        pop_heap(planks.begin(), planks.end(), greater_comp);
        pop_heap(planks.begin(), planks.end()-1, greater_comp);
        planks[planks.size()-2] += planks.back();
        planks.pop_back();
        sum += planks.back();
        push_heap(planks.begin(), planks.end(), greater_comp);
    }

    cout << sum << endl;
}
