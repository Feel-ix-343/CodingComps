/*
ID: felixaz1
LANG: C++11
TASK: beads
*/
//need to change the username for real contests
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

#define forn(s, e) for(int i = s; i < e; i++)

int main () {
    ifstream in ("beads.in"); 
    ofstream out ("beads.out");

    int n; in >> n;
    string beads; in >> beads;
    beads += beads;
    int maxBeads, leftLength, rightLength;

    forn(1, n) {
        int index = i;
        rightLength = 0;
        leftLength = 0;
        bool isW = false;
        while (index >= 0 && (beads[index] == beads[i] || beads[index] == 'w' || beads[i] == 'w')) { 
            if (beads[index] != 'w' && beads[i] == 'w') {
                beads[i] = beads[index];
                isW = true;
                }
            leftLength++; 
            index--;
            }
        if (isW) beads[i] = 'w';
        isW = false;
        index = i + 1;
        while (index < n + i - leftLength + 1 && (beads[index] == beads[i + 1] || beads[index] == 'w' || beads[i + 1] == 'w')) { 
            if (beads[index] != 'w' && beads[i + 1] == 'w') {
                beads[i + 1] = beads[index];
                isW = true;
                }
            rightLength++; 
            index++;
            }
        if (isW) beads[i + 1] = 'w';
        int total = leftLength + rightLength;
        if (total > maxBeads) maxBeads = total;
    }

    out << maxBeads << endl;

    out.close();
    in.close();
}