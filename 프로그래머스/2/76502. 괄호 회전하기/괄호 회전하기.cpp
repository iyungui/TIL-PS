#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = (int)s.size();
    for(int x = 0; x < n; x++) {
        stack<char> stk;
        bool isValid = true;
        for(int i = 0; i < n; i++) {
            char c = s[(i + x) % n];
            if(c == '[' || c == '{' || c == '(') stk.push(c);
            else {
                if(stk.empty()) {
                    isValid = false;
                    break;
                } else {
                    if(c == ']' && stk.top() == '[') stk.pop();
                    else if(c == '}' && stk.top() == '{') stk.pop();
                    else if(c == ')' && stk.top() == '(') stk.pop();
                }
            }
        }
        if(isValid && stk.empty()) answer++;
    }
    return answer;
}