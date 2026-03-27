#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int t = 1;
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        while(stk.size() && stk.top() == t) {
            stk.pop();
            t++;
        }
        if(num == t) t++;
        else {
            if(stk.size() && stk.top() < num) {
                cout << "Sad\n";
                return 0;
            }
            else stk.push(num);
        }
    }
    while(stk.size()) {
        if(stk.size() && stk.top() == t) {t++; stk.pop(); }
        else {
            cout << "Sad\n";
            return 0;
        }
    }
    cout << "Nice\n";
    return 0;
}