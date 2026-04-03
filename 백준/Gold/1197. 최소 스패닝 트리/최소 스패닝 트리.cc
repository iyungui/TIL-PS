#include<bits/stdc++.h>
using namespace std;

/*
1. 간선을 크기 오름차순으로 정렬하고 제일 낮은 비용 간선을 선택
2. 현재 선택한 간선이 u, v 연결하는 간선이면. 만약 u,v가 같은그룹이면 continue. 다른그룹이면 union. 현재 선택한 간선을 mst에 추가
3. mst에 v-1개 간선추가라면 종료. 그렇지 않다면 비용이 작은간선 선택 후 2번과정반복
*/
vector<int> p(10004, -1);
tuple<int, int, int> edge[100004];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int v, e; cin >> v >> e;
    for(int i = 0; i < e; i++) {
        int a, b, cost; cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);
    int cnt = 0, ans = 0;
    for(int i = 0; i < e; i++) {
        int a, b, cost;
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v-1) break;
    }cout << ans << '\n';
    return 0;
}