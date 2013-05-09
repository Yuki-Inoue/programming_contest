#include <iostream>
#include <utility>
#include <vector>

typedef std::pair<int, int> P;

P operator-(const P &p1, const P &p2) {
    return P(p1.first - p2.first, p1.second - p2.second);
}

std::pair<int, int> rotate(int rotN, const std::pair<int, int> &p){
    switch (rotN) {
        case 0:
            return p;
        case 1:
            return std::make_pair(-p.second, p.first);
        case 2:
            return std::make_pair(-p.first, -p.second);
        case 3:
            return std::make_pair(p.second, -p.first);
    }
    return std::pair<int, int>();
}

template <class Input1, class Input2>
bool same_polyline(int rotN, Input1 it1, Input1 itend1, Input2 it2, Input2 itend2) {
    P p1 = *it1++;
    P p2 = *it2++;
    while (it1 != itend1) {
        P next1 = *it1++;
        P next2 = *it2++;
        if(rotate(rotN, next1 - p1) != next2 - p2)
            return false;
        p1 = next1; p2 = next2;
    }
    return true;
}

void parseTemplateline(std::vector<P> &v){
    int m;
    std::cin >> m;
    for (int i=0; i<m; ++i) {
        int x,y;
        std::cin >> x >> y;
        v.push_back(std::make_pair(x, y));
    }
}

int main(){
    int n;
    while (std::cin >> n && n) {
        std::vector<P> template_line;
        parseTemplateline(template_line);
        for (int i=1; i<=n; ++i) {
            std::vector<P> candidate;
            parseTemplateline(candidate);
            for (int rotN=0; rotN<4; ++rotN) if ( same_polyline(rotN, template_line.begin(), template_line.end(), candidate.begin(), candidate.end()) || same_polyline(rotN, template_line.begin(), template_line.end(), candidate.rbegin(), candidate.rend()) ) {
                printf("%d\n", i);
                break;
            }
        }
        puts("+++++");
    }
}