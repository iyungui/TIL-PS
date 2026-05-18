#include <bits/stdc++.h>
using namespace std;

// K를 어떻게 설정할것인가
// K가 클수록 만들 수 있는 분배 수는 작아지고
// K가 작을 수록 분배 수는 커진다

int n, m;
vector<int> nums;

// K 크기로 N개의 정수를 분배했을 때 몇 개의 덩어리가 나오는지 반환하는 함수
int get_cnt(int k) {
    int cnt = 0;

    for(int num : nums) {
        cnt += num / k;
    }

    return cnt;
}

int main() {
    cin >> n >> m;
    nums.resize(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int low = 1;
    int high = 100001;

    int max_k = 0;
    while(low <= high) {
        int k = (low+high) / 2;

        // 분배 수가 m 이상이면, 더 큰 k로 시도
        if(get_cnt(k) >= m) {
            max_k = max(max_k, k);
            low = k+1;
        }

        // 분배 수가 m 미만이면, 더 작은 k로 시도
        else high = k-1;
    }
    cout << max_k << '\n';
    return 0;
}