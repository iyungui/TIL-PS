#include <bits/stdc++.h>
using namespace std;

const int MX = 250001;
string dat[MX];
int pre[MX], nxt[MX], unused = 0;

int insert_node(string s) {
    dat[unused] = s;
    pre[unused] = -1;
    nxt[unused] = -1;
    return unused++;
}

void print_status(int cur) {
    // 이전 노드 출력
    if(pre[cur] == -1) cout << "(Null) ";
    else cout << dat[pre[cur]] << " ";

    // 현재 노드 출력
    cout << dat[cur] << " ";

    // 다음 노드 출력
    if(nxt[cur] == -1) cout << "(Null)";
    else cout << dat[nxt[cur]];

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s_init;
    cin >> s_init;
    int cur = insert_node(s_init);

    int n;
    cin >> n;
    while(n--) {
        int op; cin >> op;
        if(op == 1) {
            string s_val; cin >> s_val;
            int newNode = insert_node(s_val);
            
            nxt[newNode] = cur;
            pre[newNode] = pre[cur];

            if(pre[cur] != -1) nxt[pre[cur]] = newNode;
            pre[cur] = newNode;
        }
        else if(op == 2) {
            string s_val; cin >> s_val;
            int newNode = insert_node(s_val);

            pre[newNode] = cur;
            nxt[newNode] = nxt[cur];

            if(nxt[cur] != -1) pre[nxt[cur]] = newNode;
            nxt[cur] = newNode;
        }
        else if(op == 3) {
            if(pre[cur] != -1) cur = pre[cur];
        }
        else if(op == 4) {
            if(nxt[cur] != -1) cur = nxt[cur];
        }
        print_status(cur);
    }
    return 0;
}