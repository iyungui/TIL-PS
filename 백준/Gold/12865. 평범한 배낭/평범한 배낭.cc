#include<bits/stdc++.h>
using namespace std;

int N, K;

// d[i][k]: i번째 물건까지 고려, 무게 합이 k일 때, 최대가치
int d[104][100004];
int w[102], v[102];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            // i번째 물건을 배낭에 담지 않는 경우, 이전까지의 최적해를 그대로 가져오기
            d[i][j] = d[i-1][j];

            // i번째 물건을 배낭에 담는 경우
            // i번째 물건을 넣기 전 무게 합의 최적해 d[i-1][j-w[i]] 에 , 현재 물건의 가치를 더한 것과 비교
            if(j-w[i] >= 0) d[i][j] = max(d[i][j], v[i] + d[i-1][j-w[i]]);
        }
    }
    cout << d[N][K] << '\n';

    return 0;
}