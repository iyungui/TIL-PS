#include <bits/stdc++.h>
using namespace std;

int n;
int a[104];

void go(int s, int e) {
    vector<int> tmp;
    for(int i = 0; i < n; i++) {
        if(i < s || i > e) {
            tmp.push_back(a[i]);
        }
    }
    n = tmp.size();
    for(int i = 0; i < n; i++) {
        a[i] = tmp[i];
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int s, e;
    cin >> s >> e;
    go(s-1, e-1);
    cin >> s >> e;
    go(s-1, e-1);

    cout << n << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i] << '\n';
    }
    return 0;
}