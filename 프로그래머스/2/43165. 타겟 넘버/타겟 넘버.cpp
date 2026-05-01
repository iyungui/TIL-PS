#include <bits/stdc++.h>

using namespace std;

// 2^20
int cnt;

void dfs(int idx, int sum, vector<int>& numbers, int target) {
    if(idx == (int)numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    dfs(idx + 1, sum + numbers[idx], numbers, target);
    dfs(idx + 1, sum - numbers[idx], numbers, target);
}

int solution(vector<int> numbers, int target) {
    cnt = 0;
    dfs(0, 0, numbers, target);
    return cnt;
}