// Implementing what they call divide conquering,
// of a domain and points.

#include <complex>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

const double sqrt2 = sqrt(2.0);

typedef complex<double> P;

vector<P> points;

int count_points(const P &center, double r){
    int c = 0;
    for (int i=0; i<points.size(); ++i)
        if (norm(points[i]-center) < r*r)
            ++c;
    return c;
}

struct Box {
    int upper_bound;
    double width;
    P bottom_left;
public:
    Box(int ub, double w, const P &bl) : upper_bound(ub), width(w), bottom_left(bl) {}
    bool operator<(const Box &other)const{
        return this->upper_bound < other.upper_bound;
    }
};

vector<Box> heap;
int max_num;

void add_heap_a_box(double width, const P &bottom_left){
    const P center = bottom_left + P(width/2, width/2);
    max_num = max(max_num, count_points(center, 1.0));

    int upper_bound = count_points(center, sqrt2*(width/2)+1.0);
    if (upper_bound <= max_num) return;

    heap.push_back(Box(upper_bound, width, bottom_left));
    push_heap(heap.begin(), heap.end());
}


int main(){
    int n;
    while (cin >> n && n) {
        points.clear();
        for (int i=0; i<n; ++i) {
            double x,y;
            cin >> x >> y;
            points.push_back(P(x,y));
        }

        heap.clear();
        max_num = 0;

        add_heap_a_box(10.0, P(0.0,0.0));

        while (!heap.empty() && heap.front().upper_bound > max_num) {
            const double next_w = heap.front().width / 2;
            const P bottom_left = heap.front().bottom_left;
            pop_heap(heap.begin(), heap.end()); heap.pop_back();

            add_heap_a_box(next_w, bottom_left);
            add_heap_a_box(next_w, bottom_left + P(0.0, next_w));
            add_heap_a_box(next_w, bottom_left + P(next_w, 0.0));
            add_heap_a_box(next_w, bottom_left + P(next_w, next_w));
        }
        cout << max_num << endl;
    }
}
