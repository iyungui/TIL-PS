#include <bits/stdc++.h>

using namespace std;

string expression;
vector<char> ops;
vector<int> chs;
bool used[6];
int nums[6];
int ret = -1e9;

int calc(int a, int b, char op) {
    if(op == '*') return a * b;
    if(op == '+') return a + b;
    return a - b;
}

int solve() {
    int sum = nums[chs[0]];
    int n = ops.size();
    for(int i = 0; i < n; i++) {
        sum = calc(sum, nums[chs[i+1]], ops[i]);
    }
    return sum;
}

void go(int idx) {
    if(idx == 6) {
        ret = max(ret, solve());
        return;
    }
    if(!used[idx]) {
        go(idx + 1);
        return;
    }
    for(int i = 1; i <= 4; i++) {
        nums[idx] = i;
        go(idx + 1);
    }
}

int main() {
    cin >> expression;

    // Please write your code here.
    for(char c : expression) {
        if(c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            used[idx] = true;
            chs.push_back(idx);
        }
        else ops.push_back(c);
    }

    go(0);

    cout << ret << '\n';

    return 0;
}
