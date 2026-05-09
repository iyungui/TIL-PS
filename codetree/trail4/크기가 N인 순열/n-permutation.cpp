#include <bits/stdc++.h>
using namespace std;

int n;
int chosen[10];
bool visited[10];
void go(int k) {
    if(k == n) {
        for(int i = 0; i < n; i++) cout << chosen[i] << " ";
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(visited[i]) continue;
        visited[i] = 1;
        chosen[k] = i;
        go(k+1);
        visited[i] = 0;
    }
}
int main() {
    cin >> n;
    go(0);
    return 0;
}