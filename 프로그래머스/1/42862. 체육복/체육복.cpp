#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> st(n+1, 1);
    for(int l : lost) st[l]--;
    for(int r : reserve) st[r]++;
    for(int i = 1; i <= n; i++) {
        if(st[i] == 0) {
            if(st[i-1] == 2) {
                st[i-1]--; st[i]++;
            }
            else if(st[i+1] == 2) {
                st[i+1]--; st[i]++;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(st[i] >= 1) answer++;
    }
    return answer;
}