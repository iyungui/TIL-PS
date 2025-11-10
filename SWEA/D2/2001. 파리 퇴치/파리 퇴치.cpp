#include<bits/stdc++.h>

using namespace std;

int T;
int N, M;
int a[20][20];
int psum[20][20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        memset(a, 0, sizeof(a));
        memset(psum, 0, sizeof(psum));

        cin >> N >> M;

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> a[i][j];
            }
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                psum[i][j] = a[i][j] + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
            }
        }

        int ret = 0;
        for(int i = M; i <= N; i++) {
            for(int j = M; j <= N; j++) {
                int sum = psum[i][j] - psum[i - M][j] - psum[i][j - M] + psum[i - M][j - M];
                ret = max(ret, sum);
            }
        } 

        cout << "#" << t << " " << ret << '\n';
    }

    return 0;
}