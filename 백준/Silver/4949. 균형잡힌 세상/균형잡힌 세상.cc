#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    while(true) {
        getline(cin, s);
        if(s == ".") break;  // 온점 하나만 있는 줄에서 종료
        
        stack<char> stk;
        bool isValid = true;
        
        for(char c : s) {
            if(c == '(' || c == '[') {
                stk.push(c);
            }
            else if(c == ')') {
                if(stk.empty() || stk.top() != '(') {
                    isValid = false;
                    break;
                }
                stk.pop();
            }
            else if(c == ']') {
                if(stk.empty() || stk.top() != '[') {
                    isValid = false;
                    break;
                }
                stk.pop();
            }
        }
        
        if(!stk.empty()) isValid = false;  // 스택에 괄호가 남아있으면 불균형
        cout << (isValid ? "yes" : "no") << '\n';
    }
    return 0;
}