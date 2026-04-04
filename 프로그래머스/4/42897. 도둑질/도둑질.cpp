#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> money) {
    int n = money.size();
    if(n == 3) return *max_element(money.begin(), money.end());
    
    vector<int> d1(n, 0);
    d1[0] = money[0];
    d1[1] = d1[0];
    
    for(int i = 2; i < n - 1; i++) {
        d1[i] = max(d1[i-1], d1[i-2] + money[i]);
    }
    
    vector<int> d2(n, 0);
    d2[0] = 0;
    d2[1] = money[1];
    for(int i = 2; i < n; i++) {
        d2[i] = max(d2[i-1], d2[i-2] + money[i]);
    }
    return max(d1[n-2], d2[n-1]);
}