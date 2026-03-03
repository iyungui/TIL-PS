#include<bits/stdc++.h>
using namespace std;

vector<int> p(10005, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return 0;    // union을 수행하지 못한 경우(이미 같은 그룹인 경우)
    if(p[u] == p[v]) p[u]--;   // 랭크가 같은 경우 랭크를 1 증가시킴
    if(p[u] < p[v]) p[v] = u;   // v를 u의 자식으로 만든다
    else p[u] = v; // u를 v의 자식으로 만든다 (둘 중에 높이가 더 작은 쪽의 자식으로)
    return 1;   // 다른 그룹인 경우, union을 수행한경우
}

int v, e;
tuple<int,int,int> edge[100005];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);

    int cnt = 0;
    int ans = 0;    // 다른 그룹이라면, ans 에 cost를 더할 것임. 
    
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }
    cout << ans << '\n';
    return 0;
}