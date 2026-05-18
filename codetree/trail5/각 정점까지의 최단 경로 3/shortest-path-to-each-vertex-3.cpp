#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[104][104];    // graph[a][b] = w: 정점a에서 정점b로 가는, 가중치가 w인 간선이 존재한다.
int dist[104];
bool visited[104];

int main() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = w;
    }

    // 거리 배열을 최대값으로 초기화
    memset(dist, 0x3f3f3f3f, sizeof(dist));

    // 시작정점은 거리가 0
    dist[1] = 0;
    // 다익스트라는 우선순위 큐 + 인접리스트를 사용하여 O(E log V)로 구현하는 것이 일반적이지만
    // 여기서는 정점의 수가 최대 100으로 작기에, 인접행렬과 for 반복문을 통해 O(V^2)으로 간단히 풀어보자
 
    for(int i = 1; i <= n; i++) {
        // 아직 방문하지 않은 정점 중, dist 값이 가장 작은 정점 찾기
        int min_idx = -1;
        
        for(int j = 1; j <= n; j++) {
            if(visited[j]) continue;

            if(min_idx == -1 || dist[min_idx] > dist[j]) min_idx = j;
        }
        // 최솟값에 해당하는 정점에 방문 표시
        visited[min_idx] = true;

        // 그리고 해당 정점에 연결된 간선들을 보며, 최단거리값 갱신
        for(int j = 1; j <= n; j++) {
            if(graph[min_idx][j] == 0) continue;
            dist[j] = min(dist[j], dist[min_idx] + graph[min_idx][j]);
        }
    }

    // 1번 정점에서 다른 모든 정점으로 가는 최단 경로를 출력
    for(int i = 2; i <= n; i++) {
        if(dist[i] == 0x3f3f3f3f) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
    return 0;
}