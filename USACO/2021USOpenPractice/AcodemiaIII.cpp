#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main () {
    int r, c, friends = 0; cin >> r >> c;
    set<vector<pair<int, int>>> specialCowPairs;
    vector<string> a(r);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }
    auto nearbyCow = [&](int i, int j) -> bool {
        return i >= 0 && j >= 0 && i < r && j < c && a[i][j] == 'C';
    };
    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            if (a[x][y] == 'G') {
                vector<pair<int, int>> cowsV;
                int dx[] = {1, 0, -1, 0};
                int dy[] = {0, 1, 0, -1};
                for (int i = 0; i < 4; i++) {
                    int ii = dx[i] + x, jj = dy[i] + y;
                    if (nearbyCow(ii, jj)) cowsV.emplace_back(ii, jj);
                }
                if (cowsV.size() > 2) {
                    friends++;
                } else if (cowsV.size() == 2) {
                    sort(cowsV.begin(), cowsV.end());
                    specialCowPairs.insert(cowsV);
                }
            }
        }
    }
    cout << friends + specialCowPairs.size() << endl;
}