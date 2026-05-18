#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end(), greater<int>());
    int answer = 0;
    for(int i = 0; i < n; i++) {
        if(citations[i] >= i+1) answer = i+1;
        else break;
    }
    return answer;
}