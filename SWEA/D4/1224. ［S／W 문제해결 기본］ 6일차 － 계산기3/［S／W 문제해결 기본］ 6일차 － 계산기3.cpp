#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int T = 10;
int n;
string s;

int priority(char op) {
    if(op == '*') return 2;
    if(op == '+') return 1;
    return 0; 
}

string toPostfix(string s) {
    stack<char> stk;
    string result = "";

    for(char c : s) {
        if(isdigit(c)) result += c;
        else if(c == '(') stk.push(c);
        else if(c == ')') {
            while(stk.size() && stk.top() != '(') {
                result += stk.top();
                stk.pop();
            }
            stk.pop();
        }
        else {
            while(stk.size() && priority(stk.top()) >= priority(c)) {
                result += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(stk.size()) {
        result += stk.top(); stk.pop();
    }
    return result;
}

ll cal(string s) {
    stack<ll> stk;

    for(char c : s) {
        if(isdigit(c)) stk.push(c - '0');

        else {
            ll b = stk.top(); stk.pop();
            ll a = stk.top(); stk.pop();

            if(c == '+') stk.push(a + b);
            else if(c == '*') stk.push(a * b);
        }
    }
    return stk.top();
}

int main() {
    for(int t = 1; t <= T; t++) {
        cin >> n >> s;

        string postfix = toPostfix(s);

        ll ret = cal(postfix);
        cout << "#" << t << " " << ret << '\n';
    }
}