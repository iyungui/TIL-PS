#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> days, ret;
    int n = speeds.size();
    for(int i = 0; i < n; i++) {
        int remain = 100 - progresses[i];
        int d = (remain + speeds[i] - 1) / speeds[i];
        days.push_back(d);
    }
    
    int mn = days[0];
    int cnt = 1;
    for(int i = 1; i < n; i++) {
        if(mn >= days[i]) cnt++;
        else {
            ret.push_back(cnt);
            cnt = 1;
            mn = days[i];
        }
    }
    ret.push_back(cnt);
    return ret;
}