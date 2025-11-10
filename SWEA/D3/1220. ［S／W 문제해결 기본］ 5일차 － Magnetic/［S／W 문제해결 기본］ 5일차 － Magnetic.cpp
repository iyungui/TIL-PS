#include<bits/stdc++.h>
using namespace std;

const int TC = 10;
int a[104][104];
int n;

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);

    for(int t = 1; t <= TC; t++) {
        memset(a, 0, sizeof(a));

        cin >> n;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        int cnt = 0;
        for(int col = 0; col < n; col++) {
            bool flag = false;
            for(int row = 0; row < n; row++) {
                if(a[row][col] == 1) flag = true;
                else if(flag && a[row][col] == 2) {
                    cnt++;
                    flag = false;
                }
            }
        }
        

        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}