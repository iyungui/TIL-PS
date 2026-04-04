#include<bits/stdc++.h>
using namespace std;

int n, m;
int w[104][104];
int nxt[104][104];
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    // 자기자신으로 가는 비용 0
    // 나머지는 INF 로 초기화
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) w[i][j] = 0;
            else w[i][j] = INF;
        }
    }
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);
        nxt[a][b] = b;  // a에서 b로 가려면 b를 거쳐야 한다(a에서 바로 b로 가야한다)
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(w[i][j] > w[i][k] + w[k][j]) {
                    w[i][j] = w[i][k] + w[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(w[i][j] == INF) cout << 0 << " ";
            else cout << w[i][j] << " ";
        }
        cout << '\n';
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            // 자기자신으로 가는 경우 또는 길이 없는 경우에는 0출력
            if(w[i][j] == 0 || w[i][j] == INF) {
                cout << "0\n";
                continue;
            }
            vector<int> path;
            int st = i;
            while(st != j) {
                path.push_back(st);
                st = nxt[st][j];
            }
            path.push_back(j);

            cout << path.size() << ' ';
            for(auto x : path) cout << x << ' ';
            cout << '\n';
        }

    }

    return 0;
}