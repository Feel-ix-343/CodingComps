#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main() {
    int n_of_inputs;
    cin >> n_of_inputs;
    array<long long, 2> people;
    for (int i = 0; i < n_of_inputs; i++) {
        cin >> people[0] >> people[1];
        sort(people.begin(), people.end());
        reverse(people.begin(), people.end());
        if (people[1] * 3 <= people[0]) {
            cout << people[1] << endl;
        } else if (people[0] - people[1] < 2) {
            cout << people[1] / 2 << endl;
        } else {
            long long x = (people[1] - people[0]) / -2;
            people[1] -= x;
            cout << x + people[1] / 2 << endl;
        }
    }
    return 0;
}