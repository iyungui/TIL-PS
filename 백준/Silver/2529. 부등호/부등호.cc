#include <bits/stdc++.h>

using namespace std;
int n, visited[10];
char a[20];
vector<string> v;

bool good(char x, char y, char op) {
    if(x < y && op == '<') return true;
    if(x > y && op == '>') return true;
    return false;
}

void go(int idx, string num) {
    if(idx == n + 1) {
        v.push_back(num);
        return;
    }
    for(int i = 0; i <= 9; i++) {
        if(idx == 0 || (visited[i] == 0 && good(num[idx - 1], i + '0', a[idx - 1]))) {
            visited[i] = 1;
            go(idx + 1, num + to_string(i));
            visited[i] = 0;
        }
    }
    return;
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    go(0, "");
    sort(v.begin(), v.end());
    cout << v[v.size() - 1] << '\n' << v[0] << '\n';
    return 0;
}
