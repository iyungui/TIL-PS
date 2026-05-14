#include <bits/stdc++.h>
using namespace std;

int n, q;

struct Group {
    int x, y, z;
};
Group psum[100004];

int main() {
    cin >> n >> q;
    psum[0] = {0, 0, 0};
    for(int i = 1; i <= n; i++) {
        int num; cin >> num;
        psum[i] = psum[i-1];
        if(num == 1) psum[i].x++;
        else if(num == 2) psum[i].y++;
        else psum[i].z++;
    }
    while(q--) {
        int a, b; cin >> a >> b;
        int x = psum[b].x - psum[a-1].x;
        int y = psum[b].y - psum[a-1].y;
        int z = psum[b].z - psum[a-1].z;
        cout << x << " " << y << " " << z << '\n';
    }
    return 0;
}