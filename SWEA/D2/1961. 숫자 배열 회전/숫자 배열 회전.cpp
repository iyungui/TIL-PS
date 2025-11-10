#include<bits/stdc++.h>
using namespace std;

int TC, n;
int a[10][10];
int r90[10][10], r180[10][10], r270[10][10];

int main() {
    ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
    cin >> TC;
    for(int t = 1; t <= TC; t++) {
        cin >> n;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                r90[j][n-1-i] = a[i][j];
                r180[n-1-i][n-1-j] = a[i][j];
                r270[n-1-j][i] = a[i][j];
            }
        }

        cout << "#" << t << '\n';
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << r90[i][j];
            }
            cout << " ";

            for(int j = 0; j < n; j++) {
                cout << r180[i][j];
            }
            cout << " ";

            for(int j = 0; j < n; j++) {
                cout << r270[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}