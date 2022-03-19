#include <bits/stdc++.h>

using namespace std;

// int main() {
//     cout << 14 << endl;
//     cout << 16 << endl;
//     cout << -1 << endl;
//     cout << -1 << endl;
//     cout << -1 << endl;
// }

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i ++) {
        int n;
        cin >> n;
        vector<int> l(n);
        for (int j = 0; j < n; j++){
            cin >> l[j];
        }
        int bags = 0;
        while (count_if(l.begin(), l.end(), [](int i){return i < 0;}) == 0 && count(l.begin(), l.end(), l[0]) != l.size()) {
            int greatest = 0, index = 0, smallest = l[0];
            for (int c = 0; c < l.size(); c++) {
                if (l[c] > greatest) {
                    greatest = l[c];
                    index = c;
                }
                else if (l[c] < smallest) smallest = l[c];
            }
            if (l[index - 1] > l[index + 1]) {
                while (l[index] != l[index - 1]) {
                    l[index + 1]--;
                    l[index]--;
                    bags++;
                }
            }
            else if (l[index + 1] > l[index - 1]) {
                while (l[index] != l[index + 1]) {
                    l[index - 1]--;
                    l[index]--;
                    bags++;
                }
            }
            for (int c = 0; c < l.size(); c++) {
                if (l[c] > greatest) {
                    greatest = l[c];
                    index = c;
                }
                else if (l[c] < smallest) smallest = l[c];
            }
            for (int c = 0; c < l.size(); c++) {
                if (l[c] == l[c + 1]) {
                    l[c] -= l[c] - smallest;
                    l[c + 1] -= l[c] - smallest;
                    bags += l[c] - smallest;
                }
            }
        }
        if (count(l.begin(), l.end(), l[0]) != l.size()) bags = -1;
        cout << bags << endl;
    }
}