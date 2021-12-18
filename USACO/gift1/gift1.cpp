/*
ID: felixaz1
LANG: C++11
TASK: gift1
*/

#include <fstream>
#include <bits/stdc++.h>

using namespace std;

#define forn(s, e) for(int i = s; i < e; i++)

int main () {
    ifstream in("gift1.in");
    ofstream out("gift1.out");

    int n_of_names; in >> n_of_names;
    map<string, int> people;
    vector<string> order;
    string person;
    forn(0, n_of_names) { in >> person; people[person] = 0; order.push_back(person); }
    forn(0, n_of_names) {
        in >> person;
        int money, n_of_people;
        in >> money >> n_of_people;
        string reciever;
        forn(0, n_of_people) {
            in >> reciever;
            people[reciever] += money / n_of_people;
        }
        if (n_of_people != 0) people[person] -= money - (money % n_of_people);
    }
    for_each(order.begin(), order.end(), [&out, &people](string s) {out << s << " " << people[s] << endl; } );

}