/*
크루스칼 알고리즘

1. 간선의 크기를 오름차순으로 정렬하고 제일 낮은 비용의 간선을 선택
2. 현재 선택한 간선이 정점u v를 연결하는 간선이라고 할 때, 만약 u, v가 같은 그룹이면 아무것도 하지않고 넘어감. u V가 다른 그룹이면 같은그룹으로 만들고 현재 선택한 간선을 mst에 추가
3. mst에 v-1개의 간선을 추가시켰다면 과정 종료. 그렇지 않다면 그 다음으로 비용이 작은 간선을 선택한 후 2번 과정 반복.

하나의 마을을 두 개로 나누면서, 유지비를 최소로하려면?
=> 이 문제는 mst를 구하고, 거기서 가장 비용이 큰 간선 하나만 제거하면 되는 문제
*/

#include<bits/stdc++.h>
using namespace std;

int p[100005];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;

    // union by rank
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}
tuple<int,int,int> edge[1000005];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) p[i] = -1;
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {c, a, b};
    }

    // 가중치 기준 오름차순 정렬
    sort(edge, edge + m);

    int ans = 0;
    int mc = 0;
    int cnt = 0;

    for(int i = 0; i < m; i++) {
        int w, u, v;
        tie(w, u, v) = edge[i];
        
        if(!is_diff_group(u, v)) continue;

        ans += w;
        // mc = max(v, mc);
        mc = w;
        cnt++;
        if(cnt == n-1) break;
    }
    cout << ans - mc << '\n';
    return 0;
}