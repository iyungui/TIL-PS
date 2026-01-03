#include<bits/stdc++.h>
using namespace std;

int n, k;
const int MX = 5004;
int nxt[MX], pre[MX];
vector<int> v;
int len = 0;
int main() {
    cin >> n >> k;

    // 원형 연결 리스트 생성
    // 맨 처음 노드와 마지막 노드가 서로를 가리키도록 지정
    for(int i = 1; i <= n; i++) {
        pre[i] = (i == 1) ? n : i - 1;
        nxt[i] = (i == n) ? 1 : i + 1;
        len++;
    }

    int i = 1;
    // 연결 리스트를 순회하며 순열 생성
    for(int cur = 1; len != 0; cur = nxt[cur]) {
        if(i == k) {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            v.push_back(cur);
            i = 1;
            --len;
        } else ++i;
    }

    cout << "<";
    for(size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if(i != v.size() -1) cout << ", ";
    }
    cout << ">\n";

    return 0;
}