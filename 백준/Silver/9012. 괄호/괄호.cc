#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool check(string s) {
    stack<char> stk;
    for(char c : s) {
        if(c == '(') stk.push(c);
        else if(c == ')') {
            if(stk.empty()) return false;
            else if(stk.size() && stk.top() == '(') stk.pop();
        }
    }
    
    return stk.empty();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    
    while(n--) {
        cin >> s;
        if(check(s)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
