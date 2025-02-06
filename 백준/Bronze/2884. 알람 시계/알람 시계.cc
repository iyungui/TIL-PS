#include <bits/stdc++.h>
using namespace std;

int h, m;
int main() {
    cin >> h >> m;
    if(m - 45 >= 0) {
        m -= 45;
    } else {
        if(h - 1 >= 0) {    // 3시 20분 -> 2시 35분
            h--;
            m += 15;
        } else {    // 0시 20분 -> 11시 35분
            h = 23;
            m += 15;
        }
        
    }
    cout << h << " " << m << '\n';
    return 0;
}
