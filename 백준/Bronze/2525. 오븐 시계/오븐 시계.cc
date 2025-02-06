#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int main() {
    cin >> a >> b >> c;
    a += (c / 60);
    b += (c % 60);
    int temp = (b / 60);
    a += temp;
    cout << a % 24 << " ";
    cout << b % 60 << '\n';
    return 0;
}
