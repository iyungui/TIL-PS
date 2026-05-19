#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> nums;
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        nums.push_back(num);
    }

    // 모든 숫자들이 폭발하므로 0 출력
    if(m == 1) {
        cout << 0 << '\n';
        return 0;
    }

    while(1) {
        // 폭발이 일어났는지 여부
        bool bomb = false;

        // 배열 크기 업데이트
        n = nums.size();

        vector<bool> is_bomb(n, false); // 폭발이 일어나는 위치인지 여부

        int st = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] != nums[i-1]) {
                int len = i - st;
                // 폭탄이 터지는 경우(st부터 i 직전 까지(i는 새로운 숫자이므로 터지지x))
                if(len >= m) {
                    bomb = true;
                    for(int j = st; j < i; j++) {
                        is_bomb[j] = true;  // 나중에 한번에 터져야 하므로 true로 표시만   
                    }
                }
                st = i;     // 새로운 숫자가 나타난 곳으로 시작점 갱신
            }
        }
        // 마지막 숫자에 대한 처리
        if(n - st >= m) {
            bomb = true;
            for(int j = st; j < n; j++) {
                is_bomb[j] = true;
            }
        }

        // 폭발이 한번도 일어나지 않았으면 종료
        if(!bomb) break;

        // is_bomb이 false인 곳만 다음 배열에 넣기
        vector<int> tmp;
        for(int i = 0; i < n; i++) {
            if(!is_bomb[i]) tmp.push_back(nums[i]);
        }

        // 배열 업데이트 (바꾸기)
        nums = tmp;
    }

    
    cout << n << '\n';
    for(int num : nums) cout << num << '\n';
    return 0;
}