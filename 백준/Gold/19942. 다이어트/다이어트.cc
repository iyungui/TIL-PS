#include<bits/stdc++.h>

using namespace std;

int n, mp,mf,ms,mv;
struct A {
    int p,f,s,v,cost;
} a[16];
int min_cost = INT_MAX;
vector<int> ret;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    int p,f,s,v,c;
    for(int i = 0; i < n; i++) {
        cin >> p >> f >> s >> v >> c;
        a[i] = {p, f, s, v, c};
    }
    for(int i = 0; i < (1 << n); i++) {
        vector<int> selected;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                selected.push_back(j + 1);
            }
        }
        p = f = s = v = c = 0;
        for(int idx : selected) {
            p += a[idx - 1].p;
            f += a[idx - 1].f;
            s += a[idx - 1].s;
            v += a[idx - 1].v;
            c += a[idx - 1].cost;
        }
        if(p >= mp && f >= mf && s >= ms && v >= mv) {
            if(min_cost > c) {
                ret = selected;
                min_cost = c;
            } else if(min_cost == c) {
                if(ret > selected) {
                    ret = selected;
                }
            }
        }
    }
    if(min_cost == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }
    
    cout << min_cost << '\n';
    
    for(int i : ret) {
        cout << i << " ";
    }
    return 0;
}