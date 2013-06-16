#include <iostream>
#include <vector>

using namespace std;

vector<int> available_stamps;

struct Issue {
    vector<int> values;
    int sum;
    int different;
    bool operator<(const Issue &other) const {
        return different < other.different ||
        (different == other.different &&
         (values.size() > other.values.size() ||
          (values.size() == other.values.size() &&
           (values.back() < other.values.back()))));
    }
    void clear(){
        values.clear();
        sum = different = 0;
    }
};

Issue candidate;
Issue best;
bool tied;
int aim;


void check_candidate(){
    if (candidate.sum != aim) return;
    if (best < candidate) {
        best = candidate;
        tied = false;
    }
    else if (!(candidate < best))
        tied = true;
}


void unused_loop(int);

void used_loop(int i){
    int original_size = (int)candidate.values.size();
    int original_sum = candidate.sum;
    while (candidate.values.size() < 4) {
        unused_loop(i+1);
        candidate.values.push_back(available_stamps[i]);
        candidate.sum += available_stamps[i];
        check_candidate();
    }
    candidate.sum = original_sum;
    candidate.values.resize(original_size);
}

void unused_loop(int i){
    if (i >= available_stamps.size()) return;

    unused_loop(i+1);

    candidate.values.push_back(available_stamps[i]);
    candidate.sum += available_stamps[i];
    candidate.different++;

    check_candidate();
    used_loop(i);

    candidate.sum -= available_stamps[i];
    candidate.different--;
    candidate.values.pop_back();
}

vector<int> parse_line(istream &is){
    int n;
    vector<int> ret;
    while (is >> n && n)
        ret.push_back(n);
    return ret;
}

int main(){
    while (cin) {
        available_stamps = parse_line(cin);
        vector<int> customers = parse_line(cin);

        for (int i=0; i<customers.size(); ++i) {
            aim = customers[i];
            candidate.clear();
            best.clear();

            unused_loop(0);

            if (best.values.empty()) {
                printf("%d ---- none\n", customers[i]);
                continue;
            }

            printf("%d (%d):", customers[i], best.different);
            if (tied) {
                printf(" tie\n");
                continue;
            }

            for (int j=0; j<best.values.size(); ++j)
                printf(" %d", best.values[j]);

            puts("");
        }
    }
}
