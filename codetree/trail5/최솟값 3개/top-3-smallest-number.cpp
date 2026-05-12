#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;
long long ret = 1LL;

int main() {
    cin >> n;
    while(n--) {
        int num; cin >> num;
        pq.push(num);
        if(pq.size() < 3) cout << -1 << '\n';
        else {
            ret = 1LL;
            vector<int> v;
            for(int i = 0; i < 3; i++) {
                int t = pq.top(); pq.pop();
                ret *= t;
                v.push_back(t);
            }
            cout << ret << '\n';
            for(int i : v) pq.push(i);
        }
    }
    return 0;
}