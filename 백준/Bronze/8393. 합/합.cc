#include <bits/stdc++.h>
using namespace std;

int n;

int go(int a) {
    if(a == n) {
        return n;
    }
    return a + go(a + 1);
}

int main() {
    cin >> n;
    cout << go(1) << '\n';
    return 0;
}
