#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string s;

bool isGoodWord(string s) {
    stack<char> stk;
    
    for(char c : s) {
        if(stk.empty()) {
            stk.push(c);
        } else {
            if(stk.top() == c) {
                stk.pop();
            } else {
                stk.push(c);
            }
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
        if(isGoodWord(s)) cnt++;
    }
    
    cout << cnt;
    return 0;
}
