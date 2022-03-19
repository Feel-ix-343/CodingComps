#include <bits/stdc++.h>

using namespace std;

int count (vector<int> x, vector<int> y) {
    int arr[4];
    for (int i = 0; i < x.size(); i++){
        arr[i] = count_if(y.begin(), y.end(), [i, x](int j){return x[i] > j;});
    }
    int sum = 0;
    for (int i : arr) sum += i;
    return sum;
}

int main() {
    int tests;
    cin >> tests;
    for (int i = 0; i < tests; i++) {
        vector<int> a(4), b(4);
        for (int i = 0; i < 4; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < 4; i++) {
            cin >> b[i];
        }
        if (count(b, a) > count(a, b)) {
            vector<int> tst = a;
            a = b;
            b = tst;
        }
        bool done = false;
        for (int i = 1; i < 11 && !done; i++) {
            for (int j = i; j < 11 && !done; j++) {
                for (int k = j; k < 11 && !done; k++) {
                    for (int h = k; h < 11 && !done; h++) {
                        vector<int> x = {i, j, k, h};
                        if (count(b, x) > count(x, b) && count(a, x) < count(x, a)) {
                            cout << "yes" << '\n';
                            done = true;
                        }
                    }
                }
            }
        }
        if (!done) cout << "no" << '\n';
    }
}
