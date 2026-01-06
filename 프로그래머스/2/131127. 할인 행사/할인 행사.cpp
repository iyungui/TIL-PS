#include <bits/stdc++.h>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int n = (int)want.size();
    int answer = 0;
    map<string, int> mp;
    for(int i = 0; i < n; i++) {
        mp[want[i]] += number[i];
    }
    
    for(int i = 0; i <= discount.size() - 10; i++) {
        map<string, int> mp2;
        for(int j = i; j < i+10; j++) {
            mp2[discount[j]]++;
        }
        if(mp == mp2) answer++;
    }
    
    return answer;
}