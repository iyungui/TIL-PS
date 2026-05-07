#include <bits/stdc++.h>
using namespace std;

// 점수의 최댓값을 구하라
int max_score;
int N, M, K;
vector<int> turns;
// pos[해당 말 번호] = 해당 말의 위치
int pos[6];

// 2. 해당 조합에서, 점수 구하기.
int get_score(vector<int>& b) {
    int score = 0;
    memset(pos, 0, sizeof(pos));
    
    for(int i = 0; i < N; i++) {
        // b[i] 번째 말을 turns[i]만큼 M쪽으로 이동시킨다.
        // (이미 M칸에 도달한 말이라면 무시)
        if(pos[b[i]] >= M - 1) continue;

        pos[b[i]] += turns[i];
    }

    // 모든 말을 순회하여, M칸에 도달한 말의 개수를 구한다.
    for(int i = 1; i <= K; i++) {
        if(pos[i] >= M-1) score++;
    }
    return score;
}

// 1. 조합 구하기(1부터 K이하의 수 중에서, 숫자를 N번 선택하는 조합)
void go(vector<int>& b) {
    if((int)b.size() == N) {
        max_score = max(max_score, get_score(b));
        return;
    }
    for(int i = 1; i <= K; i++) {
        b.push_back(i);
        go(b);
        b.pop_back();
    }
}

int main() {
    cin >> N >> M >> K;
    for(int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        turns.push_back(tmp);
    }
    vector<int> b;
    go(b);
    cout << max_score << '\n';
    return 0;
}