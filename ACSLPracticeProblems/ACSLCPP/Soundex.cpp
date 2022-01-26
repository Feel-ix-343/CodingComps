#include <bits/stdc++.h>

using namespace std;

#define FORN(n) for(int i = 0; i < (n); i++)

/*
 * Test input:
 * BENNY
 * CHESTERFIELD
 * MASCIONE
 * LOHWCROFT
 * DI CASHCANT
 */

char getCodedChar (char c) {
    map<string, char> code = {
        {"BFPV", '1'},
        {"CGJKQSXZ", '2'},
        {"DT", '3'},
        {"L", '4'},
        {"MN", '5'},
        {"R", '6'}
    };
    char returnVal = '0'; // Placeholder for a value to ignore
    for_each(code.begin(), code.end(), [c, code, &returnVal](pair<string, char> i) -> void {
        if (i.first.find(c) != -1) returnVal = i.second;
    });
    return returnVal; 
}

void solve (string test, string& out) {
    char previousCodedChar = getCodedChar(test[0]);
    /* For loop with 2 vars; Used to iterate through the out string while adjusting for problemset conditions in the
     test string */
    for (int i = 1, testIndex = 1; i < 4 && testIndex < test.length(); i++, testIndex++) {
        char coded = getCodedChar(test[testIndex]); // Gets the coded char
        char sepCheckChar = getCodedChar(test[testIndex - 2]); // Checking two chars back
        if (
                coded != '0' && // Ignoring unwanted characters
                (
                    coded != previousCodedChar && // Skipping duplicates
                    test[testIndex - 1] != 'H' && test[testIndex - 1] != 'W' || // Consonant Separators condition 2
                    testIndex >= 2 && (sepCheckChar == '0' || sepCheckChar != coded) && previousCodedChar == '0' // Consonant Separators condition 1
                )
            )
            out[i] = coded;
        else i--;
        previousCodedChar = coded;
    }
}

int main () {
    FORN(5) {
        string test;
        getline(cin, test);

        string out = string(1, test[0]) + "000";
        out = string(1, test[0]) + "000";

        string normTest = test; // For prefixes
        remove(normTest.begin(), normTest.end(), ' ');

        solve(normTest, out);
        cout << out;

        int prefixSepIndex = test.find(' '); // For prefixes
        if (prefixSepIndex != -1) {
            string testSpaced = test.substr(prefixSepIndex + 1, string::npos);
            out = string(1, testSpaced[0]) + "000";
            solve(testSpaced, out);
            cout << " and " << out;
        }

        cout << endl;
    }
}

