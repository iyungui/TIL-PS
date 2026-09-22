#include <bits/stdc++.h>

using namespace std;

string expression;
int nums[6];
bool used[6];
vector<char> ops;
vector<int> ids;
int ret = -2e9;

int calc(int a, int b, char op) {
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    return a * b;
}

// 해당 조합에서 식 계산
int solve() {
    int sum = nums[ids[0]]; // nums[0] 이 아니라, ids[0]임에 주의

    int len = ops.size();

    for(int i = 0; i < len; i++) {
        sum = calc(sum, nums[ids[i+1]], ops[i]);
    }

    return sum;
}

// 4^6
void combi(int idx) {
    if(idx == 6) {  // 모든 알파벳의 숫자를 다 결정한 경우
        ret = max(ret, solve());
        return;
    }

    // 나오지 않은 알파벳은 바로 다음 combi(idx+1) 호출
    if(!used[idx]) {
        combi(idx+1);
        return;
    }

    // idx 번째 알파벳에 i(1이상 4이하의 정수 중 하나)를 넣는다. 다음 combi(idx+1)를 호출한다
    for(int i = 1; i <= 4; i++) {
        nums[idx] = i;
        combi(idx+1);
    }
}

int main() {
    cin >> expression;

    for(char c : expression) {
        if(c >= 'a' && c <= 'f') {
            int idx = c - 'a';
            used[idx] = true;
            ids.push_back(idx);
        }
        else {
            ops.push_back(c);
        }
    }

    combi(0);

    cout << ret << '\n';
    return 0;
}
