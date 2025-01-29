#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int mx = 0;
    int sum = 0, cnt = 0;
    for(int i : sides) mx = max(mx, i);
    for(int i : sides) {
        if(i == mx) continue;
        sum += i;
        cnt++;
    }
    if(cnt == 0) sum += (mx * 3);
    if(cnt == 1) sum += mx;
    if(sum > mx) answer = 1;
    else answer = 2;
    
    return answer;
}