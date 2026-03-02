#include<bits/stdc++.h>
using namespace std;


// n: 물품의 수, k: 베낭의 무게 
int n, k;
// 물건의 무게와 가치
int w[100004], v[100004];

// d[i][j] = i번째 물건까지 고려, 무게 합이 j인 물건들 가치의 최대합
int d[104][100004];

int main() {
    ios::sync_with_stdio(0);    cin.tie(0);

    cin >> n >> k;
    
    for(int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++) {
            if(i-1 >= 0) d[i][j] = d[i-1][j];   // i번째 물건 선택 하지 않는경우
            
            // i번째 물건 선택하는 경우
            if(j - w[i] >= 0) {
                if(i-1 >= 0) d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);
                // 첫번째물건인 경우
                else d[i][j] = v[i];
            }
        }
    }
    cout << d[n-1][k] << '\n';
    return 0;
}