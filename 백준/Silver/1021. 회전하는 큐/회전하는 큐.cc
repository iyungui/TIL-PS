#include<bits/stdc++.h>
using namespace std;

int n, m, t, l, r, ret;
deque<int> dq;
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    while(m--) {
        cin >> t;
        for(int i = 0; i < (int)dq.size(); i++) {
            if(dq[i] == t) {
                l = i;
                r = dq.size() - i;
                break;
            }
        }

        if(l <= r) {
            while(dq.front() != t) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            while(dq.front() != t) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
        dq.pop_front();
        ret += (l <= r) ? l : r;
    }
    cout << ret << '\n';
    return 0;
}