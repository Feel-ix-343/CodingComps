#include <bits/stdc++.h>

using namespace std;

int isVowel (char c) {
    if (c == 'Y') return 2;
    else return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int getSpecialOccurances(string str) {

}

int solve(string str) {
    int blocks = 0, isType = -1, wasType = isVowel(str[0]);
    str += ' ';
    for (int i = 0; i < str.length(); i++) {
        isType = isVowel(str[i]);
        if (isType == 2) {
            if (
                    str[i - 1] == ' ' ||
                    (i == str.length() || str[i + 1] == ' ') && isVowel(str[i - 1]) == 0 ||
                    (isVowel(str[i - 1]) != 0 || isVowel(str[i + 1] != 0))
                ) isType = 0;
            else isType = 1;
        }
        if (str[i] == ' ') {
            if (str[i - 1] != 'E') blocks++;
            continue;
        } else if (isType != wasType) blocks++;
        wasType = isType;
    }
    return blocks;
}

int main() {
    string str = "AEOLUS IS GOD OF THE WINDS";
    cout << solve(str) << endl;
}
