#include<bits/stdc++.h>

using namespace std;

int T, t, temp;
int a[104];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    while(T--) {
        cin >> t;
        memset(a, 0, sizeof(a));
        for(int i = 0; i < 1000; i++) {
            cin >> temp;
            a[temp]++;
        }
        
        int maxCnt = -1;
        int num = -1;

        for(int i = 0; i <= 100; i++) {
            if(maxCnt <= a[i]) {
                maxCnt = a[i];
                num = i;
            }
        }

        cout << "#" << t << " " << num << '\n';
    }

    return 0;
}