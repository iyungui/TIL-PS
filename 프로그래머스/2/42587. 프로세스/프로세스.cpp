#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
    }
    
    int cnt = 0;
    
    while(q.size()) {
        auto cur = q.front();
        q.pop();
        bool flag = false;
        queue<pair<int, int>> temp = q;
        while(temp.size()) {
            if (temp.front().first > cur.first) {
                flag = true;
                break;
            }
            temp.pop();
        }
        if(flag) {
            q.push(cur);
        } else {
            cnt++;
            if(cur.second == location) { return cnt; }
        }
    }
    
    return cnt;
}