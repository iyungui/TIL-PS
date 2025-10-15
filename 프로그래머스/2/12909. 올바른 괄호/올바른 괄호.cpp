#include<bits/stdc++.h>

using namespace std;

bool solution(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push(s[i]);
        else if (stk.size() && s[i] == ')') stk.pop();
        else return false;
    }
    return stk.empty();
}