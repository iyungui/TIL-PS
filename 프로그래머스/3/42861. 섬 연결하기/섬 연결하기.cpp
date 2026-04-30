#include <bits/stdc++.h>

using namespace std;

int p[104];

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return 0;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return 1;
}

int solution(int n, vector<vector<int>> costs) {
    memset(p, -1, sizeof(p));
    int answer = 0;
    vector<tuple<int, int, int>> edge;
    int e = costs.size();
    for(int i = 0; i < e; i++) {
        edge.push_back({costs[i][2], costs[i][0], costs[i][1]});
    }
    sort(edge.begin(), edge.end());
    int cnt = 0;
    for(int i = 0; i < e; i++) {
        auto [c, a, b] = edge[i];
        if(!is_diff_group(a, b)) continue;
        answer += c;
        cnt++;
        if(cnt == n - 1) break;
    }
    return answer;
}