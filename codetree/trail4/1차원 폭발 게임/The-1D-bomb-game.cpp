#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

vector<int> chk() {
    vector<int> v;
    int cnt = 1;
    for(int i = 1; i < (int)a.size(); i++) {
        if(a[i] != a[i-1]) {
            // 터져야 하는 폭탄들
            if(cnt < m) {
                int j = i-1;
                int tmp = 0;
                while(tmp < cnt) {
                    v.push_back(j--);
                    tmp++;
                }
            }
            cnt = 1;
        }
        else cnt++;
    }
    if(cnt < m) {
        int j = (int)a.size()-1;
        int tmp = 0;
        while(tmp < cnt) {
            v.push_back(j--);
            tmp++;
        }
    }
    return v;
}

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
        int t = a.size();
        if(t == 0) break;

        vector<bool> is_bomb(t, false); // 터질 위치를 표시할 배열

        int start_idx = 0;
        for(int i = 1; i < t; i++) {
            if(a[i] != a[i-1]) {
                int len = i - start_idx;
                if(len >= m) {
                    bomb = true;
                    // 연속된 길이가 m 이상이면 폭발 표시
                    for(int j = start_idx; j < i; j++) {
                        is_bomb[j] = true;
                    }
                }
                start_idx = i;  // 새로운 숫자 시작점 갱신
            }
        }

        // 루프가 끝난 후 마지막으로 연속된 구간 검사
        if(t - start_idx >= m) {
            bomb = true;
            for(int j = start_idx; j < t; j++) {
                is_bomb[j] = true;
            }
        }

        // 폭발이 단 한 번도 일어나지 않았다면 루프 탈출
        if(!bomb) break;

        // 중력 작용: 터지지 않은 폭탄만 모아서 새로 구성
        vector<int> tmp;
        for(int i = 0; i < t; i++) {
            if(!is_bomb[i]) tmp.push_back(a[i]);
        }
        a = tmp;
    }

    cout << (int)a.size() << '\n';

    for(int i : a) cout << i << '\n';

    return 0;
}