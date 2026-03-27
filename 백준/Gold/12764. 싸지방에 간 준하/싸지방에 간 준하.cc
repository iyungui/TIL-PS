// 비어있는 자리 중, 번호가 가장 작은 자리에 앉기
//

#include<bits/stdc++.h>

using namespace std;

// 각 자리별 사용횟수를 저장할 배열
int cnt[100004];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    // 종료시간이 가장 빠른 것이 top에 옴 (종료시간, 자리번호)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

    // 현재 비어있는 자리번호들 관리하는 우선순위 큐
    // 번호가 가장 작은 것이 top에 옴
    priority_queue<int, vector<int>, greater<int>> empty_pq;

    int num = 0;    // 컴퓨터 자리 번호

    for(auto& p : a) {
        while(pq.size() && pq.top().first <= p.first) {
            empty_pq.push(pq.top().second);
            pq.pop();
        }

        int tmp;

        // 비어있는 자리가 있다면 가장 작은 번호 자리에 넣기
        if(empty_pq.size()) {
            tmp = empty_pq.top();
            empty_pq.pop();
        }
        // 비어있는 자리가 없다면 새로운 자리를 만듦
        else {
            tmp = ++num;
        }

        // 선택된 자리에 현재 사용자 배치
        cnt[tmp]++;
        pq.push({p.second, tmp});
    }

    cout << num << '\n';
    for(int i = 1; i <= num; i++) {
        cout << cnt[i] << " ";
    }
    cout << '\n';
    return 0;
}