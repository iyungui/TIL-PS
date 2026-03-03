#include<bits/stdc++.h>

using namespace std;


// 더 큰 값이 나오면 뒤에 붙여서 길이를 늘리고
// 더 작은 값이 나오면 기존 수열의 어딘가를 더 작은 값으로 갈아 끼워서,
// 나중에 더 긴 수열이 만들어질 수 있는 기회 남기기
int a[1000004];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // LIS를 저장할 벡터 v
    vector<int> v;
    v.push_back(a[0]);
    
    // 수열의 숫자를 하나씩 확인
    for(int i = 1; i < n; i++) {
        // 만약 현재 숫자 x가 v의 마지막 원소보다 크다면? v의 뒤에 x를 추가
        if(a[i] > v.back()) v.push_back(a[i]);

        else if(a[i] < v.back()) {
            // v안에서 x보다 크거나 같은 첫번째 원소(lower_bound)를 찾아 그 자리를 x로 교체
            auto it = lower_bound(v.begin(), v.end(), a[i]);

            // 찾은 위치의 값을 직접 수정(이터레이터 사용 O(1))
            *it = a[i];
        }
    }
    cout << v.size() << '\n';
    return 0;
}