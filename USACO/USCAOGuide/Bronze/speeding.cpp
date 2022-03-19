#include <bits/stdc++.h>

using namespace std;

int evalSpeed(int rSpd, int bSpd, int maxSpeedOver) {
    return max(maxSpeedOver, bSpd - rSpd);
}

int main() {
    ifstream in("speeding.in");
    ofstream out("speeding.out");
    int N, M;
    in >> N >> M;

    vector<pair<int, int>> r(N), b(M);
    for (int i = 0; i < N; i++) in >> r[i].first >> r[i].second;
    for (int i = 0; i < M; i++) in >> b[i].first >> b[i].second;

    int maxSpeedOver = 0;
    while (!r.empty()) {
        if (r[0].first < b[0].first) {
            maxSpeedOver = evalSpeed(r[0].second, b[0].second, maxSpeedOver);
            b[0].first -= r[0].first;
            r.erase(r.begin());
        } else if (r[0].first == b[0].first) {
            maxSpeedOver = evalSpeed(r[0].second, b[0].second, maxSpeedOver);
            r.erase(r.begin());
            b.erase(b.begin());
        } else {
            maxSpeedOver = evalSpeed(r[0].second, b[0].second, maxSpeedOver);
            r[0].first -= b[0].first;
            b.erase(b.begin());
        }
    }
    out << maxSpeedOver << endl;
}


