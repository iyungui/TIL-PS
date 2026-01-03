#include<bits/stdc++.h>

using namespace std;

const int MX = 5004;
int n, k;
int pre[MX], nxt[MX];
vector<int> v;
int main() {
    cin >> n >> k;
    int len = 0;

    // 원형 연결리스트 생성
    for(int i = 1; i <= n; i++) {
        pre[i] = (i == 1) ? n : (i - 1);
        nxt[i] = (i == n) ? 1 : (i + 1);
        len++;
    }

    int i = 1;

    for(int cur = 1; len > 0; cur = nxt[cur]) {
        if(i == k) {
            pre[nxt[cur]] = pre[cur];
            nxt[pre[cur]] = nxt[cur];
            v.push_back(cur);
            i = 1; len--;
        }
        else i++;
    }
    cout << "<";
    for(int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if(i != v.size() - 1) cout << ", ";
    }
    cout << ">\n";
    return 0;
}