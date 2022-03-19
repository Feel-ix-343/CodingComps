#include <bits/stdc++.h>

using namespace std;

int main (){
    int n;
    cin >> n;
    string cows;
    cin >> cows;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long lhs = 0, rhs = 0;
        if (i > 0 && cows[i - 1] != cows[i]) { // Check if there are any to the left
            lhs++;
            for (int j = i - 2; j >= 0 && cows[j] != cows[i]; j--) lhs++; // Count the rest of them
        }
        if (i + 1 < n && cows[i + 1] != cows[i]) { // Check if any to the right
            rhs++;
            for (int j = i + 2; j < n && cows[j] != cows[i]; j++) rhs++; // Count how many
        }
        // if distance to G is > 1, there are rhs + 1 lonely photos; (rhs - 1) * (lhs + 1)
        // If the distance is 1; rhs >= 1, then 1 + rhs - 1; rhs
        // If distance is 0; rhs >= 2: then 1 + rhs - 2; rhs - 1
        if (lhs >= 1 && rhs >= 1 || lhs >= 2 && rhs == 0 || rhs >= 2 && lhs == 0) {
            //cout << lhs << " " << rhs << endl;`
            if (lhs > 1) ans += (long long)((lhs - 1) * (rhs + 1));
            if (rhs >= 1 && lhs > 0) ans += (long long)rhs;
            if (rhs >= 2) ans += (long long)(rhs - 1);
        }
    }
    cout << ans << '\n';
}