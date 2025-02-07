#include <bits/stdc++.h>
using namespace std;

int n, m, arr[104];
int a, b;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    for(int i = 1; i <= m; i++) {
        cin >> a >> b;
        swap(arr[a], arr[b]);
    }
    for(int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << '\n';
    return 0;
}
