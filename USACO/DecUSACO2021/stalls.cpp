/*
ID: felixzeller
LANG: C++11
TASK: _____
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define forn(s, e) for(int i = s; i < e; i++)

int main () {
    int stals;
    cin >> stals;
    vector<int> p(stals);
    vector<int> t(stals);
    forn(0, stals) { cin >> p[i]; }
    forn(0, stals) { cin >> t[i]; }
    int totalMoves = 0;
    int frontIndex = 0;
    int frontDiff = 0, backDiff = 0;
    int backIndex = stals - 1;
    while (p != t) {
        for (int i = frontIndex; t[i] == p[i]; i++) {
            frontIndex++;
        }
        for (int i = backIndex; t[i] == p[i]; i--) {
            backIndex--;
        }
        frontDiff = p[frontIndex] - t[frontIndex];
        backDiff = p[backIndex] - t[backIndex];
        if (abs(frontDiff) <= abs(backDiff)) {
            for_each(t.begin() + frontIndex, t.begin() + backIndex + 1, [frontDiff](int &x) {x += frontDiff;});
            totalMoves += abs(frontDiff);
        } else {
            for_each(t.begin() + frontIndex, t.begin() + backIndex + 1, [backDiff](int &x) {x += backDiff;});
            totalMoves += abs(backDiff);
        }
    }
    cout << totalMoves << endl;
}