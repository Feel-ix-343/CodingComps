#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool checkSorted (vector<string> names) {
    vector<string> namesSorted(names.size());
    copy(names.begin(), names.end(), namesSorted.begin());
    sort(namesSorted.begin(), namesSorted.end());
    if (names == namesSorted) return true;
    else return false;
}

int main () {
    int k; int n;
    cin >> k >> n;
    map<string, int> names;
    vector<string> namesList;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        namesList.push_back(name);
        names[name] = 0;
    }
    for (int i = 0; i < k; i++) {
        if (n > 2) {
            int points = 0;
            string firstName; cin >> firstName;
            vector<string> namesInOrder = {firstName};
            for (int x = 1; x < n; x++) {
                string name; cin >> name;
                vector<string> lastTwo = {namesInOrder.back(), name};
                if (checkSorted(lastTwo)) namesInOrder.push_back(name);
                else {
                    for_each(namesInOrder.begin(), namesInOrder.end(),
                             [&names, points](const string& x) -> void {names[x] += points;});
                    points++;
                    namesInOrder.clear();
                    namesInOrder.push_back(name);
                }
            }
            for_each(namesInOrder.begin(), namesInOrder.end(),
                     [&names, points](const string &x) -> void {names[x] += points;});
        } else if (n == 2) {
            vector<string> twoNames(2);
            cin >> twoNames[0] >> twoNames[1];
            if (!checkSorted(twoNames)) names[twoNames[1]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int jVal = names[namesList[j]];
            int iVal = names[namesList[i]];
            if (i == j) cout << 'B';
            else if (jVal < iVal) cout << '1';
            else if (jVal > iVal) cout << '0';
            else cout << '?';
        }
        cout << endl;
    }
}