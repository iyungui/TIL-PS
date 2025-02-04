#include <bits/stdc++.h>

using namespace std;

int n, d[200004], ret;
string s;
stack<int> stk;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            stk.push(i);
        }
        else if(stk.size()) {
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
        
    }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        if(d[i]) {
            cnt++;
        } else {
            ret = max(ret, cnt);
            cnt = 0;
        }
    }
    
    ret = max(ret, cnt);
    cout << ret << '\n';
    return 0;
}
