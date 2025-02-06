#include <bits/stdc++.h>
using namespace std;

int a, b;
int main() {
    cin >> a >> b;
    if(a > 0 && b > 0) cout << 1;
    else if(a > 0 && b < 0) cout << 4;
    else if(a < 0 && b > 0) cout << 2;
    else cout << 3;
    return 0;
}
