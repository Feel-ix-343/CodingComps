#include <bits/stdc++.h>
#include <iostream>

#define forn(n) for (int i = 0; i < n; i++)

using namespace std;

int main () {
    cout << "Enter n of tests: ";
    int n_of_tests;
    cin >> n_of_tests;
    forn(n_of_tests) {
        int n_of_vals;
        cin >> n_of_vals;
        deque<int> p(n_of_vals);
        forn(n_of_vals) cin >> p[i];
        int max = max_element(p.begin(), p.end())[0];
        if (max != p.front() && max != p.back()) cout << -1 << endl;
        else {
            deque<int> a;
            while(!p.empty()) {
                if (p.front() > p.back()) {
                    a.push_front(p.front());
                    p.pop_front();
                } else {
                    a.push_back(p.back());
                    p.pop_back();
                }
            }
            for_each(a.begin(), a.end(), [](int x) { cout << x << " "; });
            cout << endl;
        }
    }
}