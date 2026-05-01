#include <bits/stdc++.h>
using namespace std;

// computers 인접행렬 자체를 이용하여 바로 dfs
// 연결된 컴포넌트 개수 구하는 문제

bool visited[204];

void dfs(int cur, vector<vector<int>>& computers) {
    visited[cur] = 1;
    for(int i = 0; i < (int)computers[cur].size(); i++) {
        if(cur != i && computers[cur][i] == 1 && !visited[i]) {
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}