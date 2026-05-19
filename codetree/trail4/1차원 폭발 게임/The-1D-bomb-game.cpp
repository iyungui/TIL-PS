#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        a.push_back(num);
    }

    if(m == 1) {
        cout << 0 << '\n';
        return 0;
    }

    while(1) {
        bool bomb = false;  // 이번 루프에서 폭발이 일어났는지 여부
        n = a.size();
        if(n == 0) break;

        vector<bool> is_bomb(n, false); // 터질 위치를 표시할 배열

        int start_idx = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] != a[i-1]) {
                int len = i - start_idx;
                // 연속된 길이가 m 이상이면 폭발 표시
                if(len >= m) {
                    for(int j = start_idx; j < i; j++) {
                        is_bomb[j] = true;
                    }
                    bomb = true;
                }
                start_idx = i;  // 새로운 숫자 시작점 갱신
            }
        }

        // 루프가 끝난 후 마지막으로 연속된 구간 검사
        if(n - start_idx >= m) {
            bomb = true;
            for(int j = start_idx; j < n; j++) {
                is_bomb[j] = true;
            }
        }

        // 폭발이 단 한 번도 일어나지 않았다면 루프 탈출
        if(!bomb) break;

        // 중력 작용: 터지지 않은 폭탄만 모아서 새로 구성
        vector<int> tmp;
        for(int i = 0; i < n; i++) {
            if(!is_bomb[i]) tmp.push_back(a[i]);
        }
        a = tmp;
    }

    cout << n << '\n';

    for(int num : a) cout << num << '\n';

    return 0;
}