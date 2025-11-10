#include<bits/stdc++.h>
using namespace std;

int TC;
int N, K;
int a[19][19];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    cin >> TC;
    for(int t = 1; t <= TC; t++) {
        cin >> N >> K;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> a[i][j];
            }
        }

        int ret = 0;
        for(int i = 0; i < N; i++) {
            int cnt = 0, cnt2 = 0;
            for(int j = 0; j < N; j++) {
                if(a[i][j] == 1) {
                    cnt++;
                    if(cnt == K && (j == N - 1 || (j < N - 1 && a[i][j + 1] == 0))) {
                        ret++;
                        cnt = 0;
                    }
                } else if(a[i][j] == 0) {
                    cnt = 0;
                }

                if(a[j][i] == 1) {
                    cnt2++;
                    if(cnt2 == K && (j == N - 1 || (j < N - 1 && a[j + 1][i] == 0))) {
                        ret++;
                        cnt2 = 0;
                    }
                } else if(a[j][i] == 0) {
                    cnt2 = 0;
                }
            }
        }
        cout << "#" << t << " " << ret << '\n';
    }
    return 0;
}