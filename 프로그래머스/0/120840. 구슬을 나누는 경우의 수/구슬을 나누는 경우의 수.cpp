#include <bits/stdc++.h>

using namespace std;

int combi(int start, vector<int> &v, int n, int r) {
    if(v.size() == r) {
        return 1;
    }
    int cnt = 0;

    for(int i = start + 1; i < n; i++) {
        v.push_back(i);
        cnt += combi(i, v, n, r);
        v.pop_back();
    }
    return cnt;
}

int solution(int balls, int share) {
    vector<int> v;
    return combi(-1, v, balls, share);
}