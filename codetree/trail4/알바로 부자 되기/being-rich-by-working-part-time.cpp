#include <bits/stdc++.h>
using namespace std;

int n;
struct Info {
    int s, e, p;
};

vector<Info> infos;

int d[1004];
int ret;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int s, e, p; cin >> s >> e >> p;
        infos.push_back({s, e, p});
    }
    for(int i = 0; i < n; i++) {
        d[i] = infos[i].p;
        for(int j = 0; j < i; j++) {
            if(infos[i].s > infos[j].e) {
                d[i] = max(d[i], d[j] + infos[i].p);
            }
        }
        ret = max(ret, d[i]);
    }
    
    cout << ret << '\n';
    return 0;
}