#include<bits/stdc++.h>
using namespace std;

int a[1004];    // 건물당 건설에 걸리는 시간
int result[1004]; // 각 건물의 완공시간을 저장

vector<int> adj[1004];
int deg[1004];

// 건물 w를 건설완료 하는데 드는 최소 시간
int solve() {
    int n, k;
    cin >> n >> k;
    memset(a, 0, sizeof(a));
    
    // 초기화 및 건물 건설시간 입력받기
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
        result[i] = 0;

        cin >> a[i];
    }

    while(k--) {
        int x, y;
        // 건물 순서
        cin >> x >> y;

        adj[x].push_back(y);
        deg[y]++;
    }
    int w;
    cin >> w;

    // w

    queue<int> q;
    // deg가 0인 정점들을 큐에 추가
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            q.push(i);
            // 선행 건물이 없으면 본인 시간이 곧 완공시간
            result[i] = a[i];
        }
    }

    while(q.size()) {
        int cur = q.front(); q.pop();

        for(int nxt : adj[cur]) {
            // nxt건물의 완공시간 = 이전까지의 시간과 현재 건물(cur)완공후 nxt지었을때 시간 중 최댓값
            result[nxt] = max(result[nxt], result[cur] + a[nxt]);
            deg[nxt]--;
            if(deg[nxt] == 0) q.push(nxt);
        }
    }
    return result[w];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        cout << solve() << '\n';
    }
    return 0;
}