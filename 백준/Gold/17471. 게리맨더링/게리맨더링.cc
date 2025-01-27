#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int a[14], visited[14], temp, b[14];

int ret = INT_MAX;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
// 구역 색칠.(0 또는 1) -> 만약 구역이 connected components 덩어리가 딱 2개면.
// 그 때 componets 안의 인구수 합계. 그 최소값을 출력. connected components가 2개가 아닌 경우가 없다면. -1

vector<int> adj[14];

pair<int, int> go(int here, int color) {
    visited[here] = 1;
    pair<int, int> p = {1, a[here]};    // 노드 개수, 합
    for(int there : adj[here]) {
        if(b[there] == color && visited[there] == 0) {
            pair<int, int> _temp = go(there, color);
            p.first += _temp.first;
            p.second += _temp.second;
        }
    }
    return p;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> cnt;
        for(int j = 0; j < cnt; j++) {
            cin >> temp;
            adj[i].push_back(temp);
            //
            adj[temp].push_back(i);
        }
    }
    
//    for(int i = 1; i <= n; i++) {
//        cout << i << ": ";
//        for(int j : adj[i]) cout << j << " ";
//        cout << '\n';
//    }
    
    for(int i = 1; i < (1 << n) - 1; i++) {
        memset(visited, 0, sizeof(visited));
        memset(b, 0, sizeof(b));
        int idx1 = -1, idx2 = -1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                b[j + 1] = 1;
                idx1 = j + 1;
            } else idx2 = j + 1;
        }
        pair<int, int> comp1 = go(idx1, 1);
        pair<int, int> comp2 = go(idx2, 0);
        if(comp1.first + comp2.first == n) {
            ret = min(ret, abs(comp1.second - comp2.second));
        }
    }
    
    if(ret == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ret << '\n';
    }
    
    return 0;
}


//사과 딸기 포도 배
//
//for(int i = 0; i < (1 << n); i++) {
//    string ret = "";
//    for(int j = 0; j < n - 1; j++) {
//        if(i & (1 << j)) ret += (a[j] + " ");
//    }
//    cout << ret << '\n';
//}
