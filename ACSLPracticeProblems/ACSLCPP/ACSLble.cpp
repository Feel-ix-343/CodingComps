#include <bits/stdc++.h>

using namespace std;

int isVowel (char c) {
    string vowels = "AEIOU";
    if (c == ' ') return 3;
    else if (c == 'Y') return 2;
    else return vowels.find(c) != -1;
}

int getSpecials(string str) {
    int count = 0;
    vector<string> pairs = {"IO", "AO", "EO", "IA", "II", "UA", "UE"};
    for (string pair : pairs) {
        for (int i = 0; i < str.length() - 1; i++) {
            if (str.substr(i, 2) == pair) count++;
        }
    }
    return count;
}

int solve(string str) {
    int blocks = 0, isType = -1, wasType = isVowel(str[0]);
    str += ' '; // To offset the forloop, it looks back for change
    for (int i = 0; i < str.length(); i++) {
        isType = isVowel(str[i]);
        if (isType == 2) { // If its 'y'
            if (str[i - 1] == ' ' ||  // Beginning of word
                (i == str.length() || str[i + 1] == ' ') && isVowel(str[i - 1]) != 0 || // End of word and letter before is vowel
                (isVowel(str[i - 1]) != 0 && isVowel(str[i + 1]) != 0)) // Middle of word and not preceded and followed by consonant
                isType = 0; // Then y is a conant
            else isType = 1; // If false, y is vowel
        }
        if (str[i] == ' ') {
            if (str[i - 1] != 'E' || (str[i - 1] == 'E' && isVowel(str[i - 2]) != 0)) blocks++;
        } else if (isType != wasType && wasType != 3) blocks++;
        wasType = isType;
    }
    return blocks + getSpecials(str);
}

int main() {
    vector<string> str(5);
    for (int i = 0; i < 5; i++) {
        getline(cin, str[i]);
    }
    std::for_each(str.begin(), str.end(), [](string s) {cout << solve(s) << endl;});
}


/*
 * TORONTO
 * IS IT TRUE THAT LAOS IS A COUNTRY IN ASIA
 * AEOLUS IS GOD OF THE WINDS
 * MARCY WORKS AT A KIOSK THAT SELLS ALLOYS
 * YELLOW KRYPTONITE IS ACTUALLY VERY SAFE FOR SUPERMAN
 */