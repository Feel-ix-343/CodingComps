#include <bits/stdc++.h>

using namespace std;

int getCodedChar (char c) { switch(c) {
    case 'C': case 'G': case 'J': case 'K': case 'Q': case 'S': case 'X': case 'Z':
        return 2;
    case 'B': case 'F': case 'P': case 'V':
        return 1;
    case 'D': case 'T':
        return 3;
    case 'L':
        return 4;
    case 'M': case 'N':
        return 5;
    case 'R':
        return 6;
    default:
        return 0;
    }
}

int main () {
    int names = 1;
    for (int i = 0; i < names; i++) {
        string name;
        getline(cin, name);
        string out = "" + name[0];
        for_each(name.begin() + 1, name.end(), [&out](char c){
            out += getCodedChar(c);
        });
        out.erase('0');
        cout << out << endl;
    }
}