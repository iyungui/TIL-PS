#include<bits/stdc++.h>

using namespace std;

int p[500005];
int find(int x) {
    if(p[x] == x) return x; // 자기 자신이면 (초기상태) 바로 반환
    return p[x] = find(p[x]);   // 부모 찾기(재귀)
}

bool uni(int u, int v) {
    u = find(u);    // u, v 각 부모 찾고
    v = find(v);
    if(u == v) return 1;    // 부모가 같다면 (이미 같은 그룹이라면) 사이클 발생
    p[u] = v;   // u의 부모로 v를
    return 0;// 다른 그룹이므로 0반환
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) p[i] = i;    // 초기상태: 자기 자신이 부모
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;

        // 만약 사이클이 발생했다면
        if(uni(u, v)) {
            cout << i << '\n';
            return 0;
        }
    }
    cout << 0 << '\n';
    return 0;
}