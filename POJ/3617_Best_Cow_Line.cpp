#include <iostream>
#include <deque>
#include <string>

inline bool use_front(const std::deque<char> &deq){
    for (int i=0; i<deq.size()/2; ++i) {
        char fronter = deq[i];
        char backer = deq[deq.size()-i-1];
        if (fronter != backer)
            return fronter < backer;
    }
    return false;
}

int main(){
    int N;
    std::cin >> N;
    std::deque<char> cows(N);
    std::string new_cows;

    for (int i=0; i<N; ++i)
        std::cin >> cows[i];

    while (!cows.empty()) {
        if (use_front(cows)) {
            new_cows.push_back(cows.front());
            cows.pop_front();
        }
        else {
            new_cows.push_back(cows.back());
            cows.pop_back();
        }
    }

    for (int i=0; i<new_cows.size(); ++i) {
        std::cout << new_cows[i];
        if (!((i+1)%80))
            std::cout << std::endl;
    }

    if (new_cows.size()%80)
        std::cout << std::endl;

}
