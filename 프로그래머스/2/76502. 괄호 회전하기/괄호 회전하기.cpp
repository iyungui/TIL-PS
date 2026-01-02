#include <bits/stdc++.h>

using namespace std;

bool valid(string s) {
    stack<char> stk;
    for(char c : s) {
        if(c == ']' || c == '}' || c == ')') {
            if(stk.empty()) return false;
            if(stk.top() == '[' && c == ']') stk.pop();
            else if(stk.top() == '{' && c == '}') stk.pop();
            else if(stk.top() == '(' && c == ')') stk.pop();
            else return false;
        }
        else {
            stk.push(c);
        }
    }
    return stk.empty();
}

int solution(string s) {
    int n = s.size();
    int answer = 0;
    // 사이즈가 홀수이면 0
    if(n % 2 == 1) return 0;
    
    for(int x = 0; x < n; x++) {
        if(valid(s)) answer++;
        s = s.substr(1) + s[0];
    }
    return answer;
}