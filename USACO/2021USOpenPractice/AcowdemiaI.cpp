#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main () {
    int n; int l; cin >> n >> l;
    vector<int> c(n); for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    int hindex;

    for (int h = n; h > 0; h--) {
        if (h - c[n - h] > 1) continue;
        else if (h <= c[n - h]) {
            hindex = h;
            break;
        } else {
            int consecutive = 1;
            while (c[n - h + consecutive] == c[n - h]) consecutive++;
            if (consecutive <= l) {
                hindex = h;
                break;
            } 
        }
    }
    cout << hindex << endl;
}