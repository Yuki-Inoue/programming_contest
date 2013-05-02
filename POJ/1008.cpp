#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

string HaabMonths[19] = {
    "pop",
    "no",
    "zip",
    "zotz",
    "tzec",
    "xul",
    "yoxkin",
    "mol",
    "chen",
    "yax",
    "zac",
    "ceh",
    "mac",
    "kankin",
    "muan",
    "pax",
    "koyab",
    "cumhu",
    "uayet"
};

const char *Tzolkin[20] = {
    "imix",
    "ik",
    "akbal",
    "kan",
    "chicchan",
    "cimi",
    "manik",
    "lamat",
    "muluk",
    "ok",
    "chuen",
    "eb",
    "ben",
    "ix",
    "mem",
    "cib",
    "caban",
    "eznab",
    "canac",
    "ahau"
};

int main(){
    int L;
    cin >> L;
    cout << L << endl;
    for (; L--; ) {
        int d,y;
        char buf[20];
        scanf(" %d. %s %d\n", &d, buf, &y);
        string m_str(buf);
        int m =
        find(HaabMonths, HaabMonths + 19, m_str)
        - HaabMonths;
        const int t = 365 * y + 20 * m + d;
        const int TzolkinYears = t / 260;
        const int TzolkinYDays = t % 260;
        printf("%d %s %d\n",
               TzolkinYDays % 13 + 1,
               Tzolkin[TzolkinYDays % 20],
               TzolkinYears);
    }
}
