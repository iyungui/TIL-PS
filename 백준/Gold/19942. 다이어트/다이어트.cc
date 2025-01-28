#include <bits/stdc++.h>

using namespace std;

int n, ret = INT_MAX;   // ret : 최소 비용
int mp, mf, ms, mv, sumP, sumF, sumS, sumV, sumC;
vector<int> num;    // 최소 비용 식재료 번호

struct A {
    int p, f, s, v, cost;
} a[16];

int main() {
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        int p, f, s, v, c;
        cin >> p >> f >> s >> v >> c;
        a[i] = {p, f, s, v, c};
    }
    
    // solution
    for(int i = 0; i < (1 << n); i++) {
        sumP = sumF = sumS = sumV = sumC = 0;
        vector<int> selected;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                sumP += a[j].p;
                sumF += a[j].f;
                sumS += a[j].s;
                sumV += a[j].v;
                sumC += a[j].cost;
                selected.push_back(j + 1);
            }
        }
        if(sumP >= mp && sumF >= mf && sumS >= ms && sumV >= mv) {
            if(ret > sumC) {
                ret = sumC;
                num.clear();
                num = selected;
            } else if(ret == sumC) {
                sort(num.begin(), num.end());
                sort(selected.begin(), selected.end());
                if(num > selected) {
                    num = selected;
                }
            }
        }
    }
    
    
    if(ret == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
        sort(num.begin(), num.end());
        for(int i : num) cout << i << " ";
        cout << '\n';
    }
    return 0;
}
