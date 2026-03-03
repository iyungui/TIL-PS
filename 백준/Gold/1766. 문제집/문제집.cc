// 위상 정렬 알고리즘

// 맨 처음 모든 간선을 읽으며 indegree 테이블을 채움
// indegree가 0인 정점들을 모두 큐에 넣음
// 큐에서 정점을 꺼내어 위상 정렬 결과에 추가
// 해당 정점으로부터 연결된 모든 정점의 indegree갑 1 감소. 이 때 indegree가 0이되면 그 정점을 큐에 추ㅏㄱ
// 큐가빌떄까지 3. 4번 과정 반복


// n개의 문제를 모두 풀어야함
// 먼저 푸는 것이 좋은 문제가 있다면 그걸 먼저 풀자
// 쉬운 문제 부터 풀어야함

// 위상정렬: 방향 그래프에서 간선으로 주어진 정점 간 선후관계를 위배하지 않도록 나열!하는 정렬.



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
    
    // 쉬운문제부터 풀 수 있도록. 정점의 번호가 작은 순으로 정렬되도록 하자.
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 1; i <= n; i++) {
        // indegree가 0인 정점들을 모두 큐에 푸시
        if(deg[i] == 0) pq.push(i);
    }

    while(pq.size()) {
        int cur = pq.top(); pq.pop();

        cout << cur << " ";
        
        for(int nxt : adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) {
                pq.push(nxt);
            }
        }
    }
    
    return 0;
}