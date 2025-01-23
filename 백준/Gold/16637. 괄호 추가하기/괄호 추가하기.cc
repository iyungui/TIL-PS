
#include <bits/stdc++.h>

using namespace std;
int n, ret = INT_MIN;
vector<char> oper_str;
vector<int> num;
string s;

int oper(char op, int a, int b) {
    if(op == '+') return a + b;
    else if(op == '-') return a - b;
    else return a * b;
}

void go(int here, int _num) {
    if(here == num.size() - 1) {
        ret = max(ret, _num);
        return;
    }
    // 괄호 o
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    // 괄호 x
    if(here + 2 <= num.size() - 1) {
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    }
    go(0, num[0]);
    cout << ret << '\n';
    return 0;
}
