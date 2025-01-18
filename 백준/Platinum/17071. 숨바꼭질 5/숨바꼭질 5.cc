#include <bits/stdc++.h>
using namespace std;

// 최대 좌표값 설정
const int max_n = 500000;

// visited[2][max_n + 4]: 수빈이의 방문 가능 위치를 저장하는 2차원 배열
// [0][위치]: 짝수 시간에 방문 가능한 위치
// [1][위치]: 홀수 시간에 방문 가능한 위치

int visited[2][max_n + 4];

int a;  // 수빈이의 시작 위치
int b;  // 동생의 시작 위치
int ok; // 만남 여부를 체크하는 플래그 (1: 만남, 0: 못 만남)
int turn = 1;   // 현재 진행 중인 시간(초), 그리고 b에 붙는 가속도(1부터 시작)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> a >> b;
    
    if(a == b) {
        cout << 0 << '\n';
        return 0;
    }
    
    queue<int> q;
    visited[0][a] = 1;      // 수빈이의 시작위치 방문 처리
    q.push(a);
    
    // bfs
    while(q.size()) {
        // 동생은 현재의 turn 만큼 더 이동
        b += turn;
        
        if(b > max_n) break;
        
        // 현재 시간(홀/짝)에 동생의 위치에 수빈이가 도달할 수 있는지(다시 말하면, 홀/짝에 수빈이가 동생위치에 방문했는지 체크
        if(visited[turn % 2][b]) {
            ok = true;
            break;
        }
        
        // 현재 턴에서 처리해야 할 위치의 수를 저장
        // (턴을 분리하여 처리하기 위해 큐 크기를 할당)
        // 처음에 q에는 a. 그 다음 턴에는 a + 1, a - 1, a * 2 총 3개....
        int qSize = (int)q.size();
        
        // 현재 턴에서 갈 수 있는 모든 위치 처리
        for(int i = 0; i < qSize; i++) {
            // 현재 위치를 큐에서 꺼냄
            int x = q.front(); q.pop();
            
            // 현재 위치에서 수빈이가 갈 수 있는 세 가지 경우 처리
            for(int nx : {x + 1, x - 1, x * 2}) {
                // 범위 벗어나거나 이미 같은 홀짝 시간에 방문했다면 스킵
                if(nx < 0 || nx > max_n || visited[turn % 2][nx]) continue;
                
                // 새로운 위치의 방문 시간 기록 (turn + 1)은 그 다음 시간(홀->짝 or 짝->홀)
                // 이전 턴의 방문 횟수에 1을 더함 (최단거리 즉 방문 시간)
                visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
                
                // 만약 nx가 동생의 현재 위치에 도달했다면 찾은 것
                if(nx == b) {
                    ok = 1;
                    break;
                }
                
                // 다음 턴에서 처리하기 위해 새로운 위치를 큐에 추가.
                q.push(nx);
            }
            if(ok) break;
        }
        if(ok) break;
        turn++;
    }
    
    if(ok) cout << turn << '\n';
    else cout << -1 << '\n';
    
    return 0;
}
