#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int n, m;
vector<pp> adj[1004];
int parent[1004];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int A, B; cin >> A >> B;

    vector<int> dist(n+1, 1e9);
    dist[A] = 0;

    priority_queue<pp, vector<pp>, greater<pp>> pq;
    pq.push({0, A});

    while(!pq.empty()) {
        auto [curDist, curNode] = pq.top(); pq.pop();

        if(curDist > dist[curNode]) continue;

        for(auto& [nxtNode, nxtDist] : adj[curNode]) {
            int newDist = dist[curNode] + nxtDist;
            if(newDist < dist[nxtNode]) {
                parent[nxtNode] = curNode;  // nxtNode의 이전정점은 curNode이다. 라고 기록 
                dist[nxtNode] = newDist;
                pq.push({newDist, nxtNode});
            }
        }
    }

    cout << dist[B] << '\n';

    int cur = parent[B];
    vector<int> path;
    path.push_back(B);

    while(cur != A) {
        path.push_back(cur);
        cur = parent[cur];
    }
    path.push_back(A);

    reverse(path.begin(), path.end());

    for(int p : path) cout << p << " ";
    return 0;
}