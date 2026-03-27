#include<bits/stdc++.h>
using namespace std;

deque<int> v[4];

int get_score() {
    int sum = 0;
    for(int i = 0; i < 4; i++) {
        if(v[i][0] == 1) sum += (1 << i);
    }
    return sum;
}

void rotate(int num, int dir) {
    if(dir == 1) {
        v[num].push_front(v[num].back());
        v[num].pop_back();
    }
    else {
        v[num].push_back(v[num].front());
        v[num].pop_front();
    }
}

vector<pair<int, int>> solve(int num, int dir) {
    vector<pair<int, int>> r;
    r.push_back({num, dir});

    // left
    int tmp = dir;
    for(int i = num; i >= 1; i--) {
        if(v[i][6] != v[i-1][2]) {
            tmp = -tmp;
            r.push_back({i-1, tmp});
        }
        else break;
    }
    // right
    tmp = dir;
    for(int i = num; i < 3; i++) {
        if(v[i][2] != v[i+1][6]) {
            tmp = -tmp;
            r.push_back({i+1, tmp}); 
        }
        else break;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 4; i++) {
        string s; cin >> s;
        for(int j = 0; j < 8; j++) v[i].push_back((int)(s[j] - '0'));
    }

    int k; cin >> k;

    while(k--) {
        int num, dir; 
        cin >> num >> dir; num--;
        vector<pair<int, int>> r = solve(num, dir);

        for(int i = 0; i < (int)r.size(); i++) {
            rotate(r[i].first, r[i].second);
        }
    }
    cout << get_score() << '\n';

    return 0;
}