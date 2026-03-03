#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
    ll x, y;
};

int main() {
    int N;
    cin >> N;
    
    vector<Point> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].x >> v[i].y;
    }

    ll s1 = 0, s2 = 0;
    
    for(int i = 0; i < N; i++) {
        int nxt = (i+1) % N;
        s1 += (v[i].x * v[nxt].y);
        s2 += (v[i].y * v[nxt].x);
    }
    
    ll ret = s1 - s2;
    if(ret < 0) ret = -ret;
    cout << fixed << setprecision(1) << (double)ret / 2.0 << '\n';
    return 0;
}