#include<bits/stdc++.h>

using namespace std;

const int T = 10;
int n;
map<int, int> mp;
vector<int> adj[104];
int visited[104];
int num, l, r;
char ch;
string line;

string inorder(int num) {
    string ret = "";
    if(!visited[num]) {
        if(adj[num].size() == 2) {
            ret += inorder(adj[num][0]);
            visited[num] = 1;
            ret += mp[num];
            ret += inorder(adj[num][1]);
        }
        else if(adj[num].size() == 1) {
            ret += inorder(adj[num][0]);
            visited[num] = 1;
            ret += mp[num];
        }
        else {
            visited[num] = 1;
            ret += mp[num];
        }
    }
    return ret;
}

int main () {
    for(int t = 1; t <= T; t++) {
        cin >> n;
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(visited, 0, sizeof(visited));
        for(int i = 0; i < n; i++) {
            cin >> num >> ch;
            mp[num] = ch;

            getline(cin, line);
            stringstream ss(line);

            if(ss >> l) {
                adj[num].push_back(l);
                if(ss >> r) adj[num].push_back(r);
            }
        }
        cout << "#" << t << " " << inorder(1) << '\n';
    }
    return 0;
}