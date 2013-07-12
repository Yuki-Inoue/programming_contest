#include <iostream>
#include <vector>
#include <utility>
#include <climits>
#include <algorithm>

using namespace std;

typedef vector<pair<long, int> > FuelStops;

int main(){
    int N;
    cin >> N;

    FuelStops fuel_stops(N);
    while (N--) {
        cin
        >> fuel_stops[N].first
        >> fuel_stops[N].second;
    }
    sort(fuel_stops.begin(), fuel_stops.end());

    long L, P;
    cin >> L >> P;

    int stopped = 0;
    while (L > P) {
        FuelStops::iterator itmax, it =
        lower_bound
        (fuel_stops.begin(), fuel_stops.end(),
         make_pair(L-P, INT_MIN));

        if (it == fuel_stops.end()) {
            stopped = -1;
            break;
        }

        for (itmax = it; it != fuel_stops.end(); ++it)
            if (itmax->second < it->second)
                itmax = it;
        P += itmax->second;
        fuel_stops.erase(itmax);
        ++stopped;
    }

    cout << stopped << endl;
}
