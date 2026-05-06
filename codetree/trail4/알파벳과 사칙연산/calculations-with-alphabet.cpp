#include <bits/stdc++.h>
using namespace std;

int nums[6];    // a~f
vector<char> ops;
vector<int> chs;
int ret = -1e9;
bool visited[6];

int calc(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

int solve() {
    int n = ops.size();
    int sum = nums[chs[0]]; // 첫번째 숫자
    for(int i = 0; i < n; i++) {
        sum = calc(sum, nums[chs[i+1]], ops[i]);
    }
    return sum;
}

void go(int idx) {
    if(idx == 6) {  // 모든 알파벳 경우를 다 본 경우(6의 4승)
        ret = max(solve(), ret);
        return;
    }
    // 가지치기
    if(!visited[idx]) { // 없는 알파벳이라면 바로 다음 idx로 가기
        go(idx + 1);
        return;
    }
    for(int i = 1; i <= 4; i++) {
        nums[idx] = i;
        go(idx + 1);
    }
}


int main() {
    // 식 입력받고, 알파벳벡터와 연산자 벡터로 분리
    string s; cin >> s;
    for(char c : s) {
        if(c >= 'a' && c <= 'f') {
            int idx = c - 'a';
            visited[idx] = 1;
            chs.push_back(idx);
        }
        else ops.push_back(c);
    }

    go(0);

    cout << ret << '\n';
    return 0;
}