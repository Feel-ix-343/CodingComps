#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream in("mowing.in");
  int n;
  in >> n;
  int x = 2000;
  int xpos = 0, ypos = 0;
  vector<pair<int, int>> positions;
  int timeCounter = 0;
  for (int i = 0; i < n; i++) {
    char direction;
    int count, xchanger = 0, ychanger = 0;
    in >> direction;
    in >> count;
    switch (direction) {
    case 'N':
      ychanger = 1;
      break;
    case 'E':
      xchanger = 1;
      break;
    case 'S':
      ychanger = -1;
      break;
    case 'W':
      xchanger = -1;
      break;
    }
    cout << "x: " << xchanger << " y: " << ychanger << endl;
    for (int t = 0; t < count;
         t++, timeCounter++, xpos += xchanger, ypos += ychanger) {
      auto it = find(positions.begin(), positions.end(), make_pair(xpos, ypos));
      if (it != positions.end()) {
        int index = it - positions.begin();
        x = min(x, timeCounter - index);
        // need to move the position to first
        positions.erase(it);
        positions.insert(positions.begin(), *it);
        cout << "HIT: " << timeCounter << " x: " << x << endl;
      }
      positions.push_back({xpos, ypos});
      cout << xpos << " " << ypos << endl;
    }
    xchanger = 0;
    ychanger = 0;
  }
  ofstream out("mowing.out");
  if (x == 2000)
    out << -1 << endl;
  else
    out << x << endl;
}
