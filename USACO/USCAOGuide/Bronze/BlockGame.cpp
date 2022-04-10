#include <algorithm>
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
  map<char, int> m;
  for (int i = 0; i < 26; i++)
    m.insert({(char)(97 + i), 0});

  ifstream in("blocks.in");
  ofstream out("blocks.out");

  int n;
  in >> n;
  for (int i = 0; i < n; i++) {
    string w1, w2;
    in >> w1;
    in >> w2;
    for (pair<char, int> const &p : m) {
      m[p.first] += max(count(w1.begin(), w1.end(), p.first),
                        count(w2.begin(), w2.end(), p.first));
    }
  }
  for_each(begin(m), end(m),
           [&out](auto const &p) { out << p.second << endl; });
}
