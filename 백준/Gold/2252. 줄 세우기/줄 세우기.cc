// 1. 맨 처음 모든 간선을 읽으며 indegree 테이블을 채움
// 2. indegree 가 0인 정점들을 모두 큐에 넣음
// 3. 큐에서 정점을 꺼내어 위상 정렬 결과에 추가
// 4. 해당 정점으로부터 연결된 모든 정점의 indegree 값을 1 감소시키고 이 때
// indegree가 0이 되었다면 그 정점을 큐에 추가
// 5. 큐가 빌 때까지 3,4번 과정을 반복


#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[32004];
int deg[32004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) q.push(i);
    }

    while(q.size()) {
        int cur = q.front(); q.pop();
        cout << cur << " ";
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    return 0;
}