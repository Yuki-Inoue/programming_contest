#include <iostream>
#include <vector>

int main(){
    int T;
    for (std::cin >> T; T--; ) {
        int n;
        std::cin >> n;
        // stack is for, counting the #
        // of )s in the current opening.
        typedef std::vector<int> Stack;
        // consider that at beginning ( is inserted.
        Stack stack(1,0);
        int current_pindex = 0;
        for (int i=0; i<n; ++i) {
            /*
            for (int j=0; j<stack.size(); ++j) {
                std::cerr << stack[j] << " ";
            }
            std::cerr << std::endl;
             */

            int p;
            std::cin >> p;
            const int new_lparens
            = p - current_pindex;
            current_pindex = p;

            for (int k=0; k<new_lparens; ++k) {
                stack.push_back(0);
            }
            ++stack.back();

            std::cout << stack.back()
            << (i<n-1 ? " " : "\n");

            stack[stack.size()-2] += stack.back();
            stack.pop_back();
        }
    }
    std::cout << std::flush;
}
