#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[1000004];
ll tree[4000004];
int n, m, k;

// 1. 트리 초기화 (node: 현재 노드 번호, start~end: 담당 범위)
ll init(int node, int start, int end) {
    if (start == end) return tree[node] = a[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// 2. 값 수정 (index: 바꿀 위치, diff: 차이값)
void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

// 3. 구간 합 (left~right: 구하고자 하는 범위)
ll sum(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    init(1,1, n);
    for(int i = 0; i < m + k; i++) {
        ll t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        if(t1 == 1) {
            ll diff = t3 - a[t2];
            a[t2] = t3;
            update(1, 1, n, (int)t2, diff);
        }
        else {
            cout << sum(1, 1, n, (int)t2, (int)t3) << '\n';
        }
    }
}