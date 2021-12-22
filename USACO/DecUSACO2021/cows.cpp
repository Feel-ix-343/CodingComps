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
    int n_of_cows;
    cin >> n_of_cows;
    char cows[n_of_cows];
    cin >> cows;
    
    int discarded = 0;

    for(int i = 3; i < n_of_cows + 1; i++) {
        for (int x = 0; x < n_of_cows - i + 1; x++) {
            int g = 0, h = 0;
            for (int j = x; j < x + i; j++) {
                if (cows[j] == 'G') g++;
                else h++;
            }
            if (g == 1 || h == 1) discarded++;
        }
        if (i == 3 && discarded == n_of_cows - 2) {
            break;
        } else if (i == 3 && discarded == 0) {
            break;
        }
    }

    cout << discarded << endl;
}