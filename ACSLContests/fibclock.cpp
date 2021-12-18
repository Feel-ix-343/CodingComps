#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int str[] = {1, 2, 3, 4};
    transform(begin(str), end(str), begin(str), [](int x) {return x * 2;});
    for_each(begin(str), end(str), [](int x) {cout << x << endl;});
}