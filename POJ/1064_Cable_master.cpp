#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

struct Entry {
    long centimeters;
    int division;
    explicit Entry (long c, int d=1) : centimeters(c), division(d) {}
    bool operator<(const Entry &other) const {
        return
        (long long) centimeters * other.division
        < (long long) other.centimeters * division;
    }
    Entry next_entry() const {
        return Entry(centimeters, division+1);
    }
    long divided_centimeters() const {
        return centimeters / division;
    }
};

int main(){
    int N, K;
    scanf(" %d %d", &N, &K);

    priority_queue<Entry> queue;
    for (int i=0; i<N; ++i) {
        long meter; int centi;
        scanf(" %ld.%d", &meter, &centi);
        queue.push(Entry(100*meter + centi));
    }

    while (--K) {
        queue.push(queue.top().next_entry());
        queue.pop();
    }

    long answer_centi = queue.top().divided_centimeters();
    printf("%ld.%02ld\n", answer_centi/100, answer_centi%100);
}
