#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000;

int n, m, q;
int arr[MAX_N];
unordered_map<int, int> mp;
int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]]++;
    }

    for (int i = 0; i < m; i++) {
        cin >> q;
        cout << mp[q] << " ";
    }

    // Please write your code here.

    return 0;
}
