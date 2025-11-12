#include<bits/stdc++.h>

using namespace std;

const int T = 10;
const int n = 8;
int m;  // 찾아야 하는 회문의 길이
string a[10];

int main() {
    for(int t = 1; t <= T; t++) {
        cin >> m;
        for(int i = 0; i < n; i++) cin >> a[i];

        int ret = 0;
        for(int i = 0; i < n; i++) {
            // 가로
            for(int j = 0; j <= n - m; j++) {
                string str = a[i].substr(j, m);
                string temp = str;
                reverse(str.begin(), str.end());
                if(str == temp) ret++;
            }
            for(int j = 0; j <= n - m; j++) {
                string str = "";
                for(int k = j; k < j + m; k++) {
                    str += a[k][i];
                }
                string temp = str;
                reverse(str.begin(), str.end());
                if(str == temp) ret++;
            }
        }
        cout << "#" << t << " " << ret << '\n';
    }

    return 0;
}