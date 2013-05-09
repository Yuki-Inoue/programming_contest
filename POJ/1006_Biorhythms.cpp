#include <iostream>

// 23, 28, 33

const int triple_offset = 23 * 28 * 33;

int main(){
    int p1,p2,p3,d;
    int counter = 0;
    while (std::cin >> p1 >> p2 >> p3 >> d && p1 >= 0) {
        p1 %= 23;
        p2 %= 28;
        p2 -= 28;
        p3 %= 33;
        p3 -= 33;
        ++counter;
        int candidate = p1;
        while ((candidate - p2) % 28) {
            candidate += 23;
        }
        while ((candidate - p3) % 33) {
            candidate += 23 * 28;
        }
        const int answer =
        ((candidate - d - 1) + triple_offset) % triple_offset + 1;
        printf("Case %d: the next triple peak occurs in %d days.\n",
               counter, answer);
    }
}
