/*
ID: felixaz1
LANG: C++11
TASK: friday
*/
//need to change the username for real contests
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

#define forn(s, e) for(int i = s; i < e; i++)

void daysCalc(int day, int &dayOfWeek, vector<int> &days) {
    if (day == 13) days[dayOfWeek]++;
    dayOfWeek = (dayOfWeek + 1) % 7;
}

int main () {
    ifstream in ("friday.in"); ofstream out ("friday.out");
    vector<int> days = {0, 0, 0, 0, 0, 0, 0};
    int dayOfWeek = 2, dayCounter = 1, monthCounter = 1, yearCounter = 1900;
    int thirty[] = {4, 6, 9, 11};
    int n = 0; 
    in >> n;
    for (int i = 1900; i < 1900 + n; i++) {
        for (int x = 1; x < 13; x++) {
            if (count(begin(thirty), end(thirty), x) > 0) {
                for (int z = 1; z < 31; z++) {
                    daysCalc(z, dayOfWeek, days);
                }
            } else if (x == 2) {
                if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
                    for (int z = 1; z < 30; z++) {
                        daysCalc(z, dayOfWeek, days);
                    }
                } else {
                    for (int z = 1; z < 29; z++) {
                        daysCalc(z, dayOfWeek, days);
                    }
                }
            } else {
                for (int z = 1; z < 32; z++) {
                        daysCalc(z, dayOfWeek, days);
                }
            }
        }
    }
    for_each(days.begin(), days.end() - 1, [&out](int day) {out << day << " ";} );
    out << days.back() << endl;
    out.close();
    in.close();
}