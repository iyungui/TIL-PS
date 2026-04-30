#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    sort(people.begin(), people.end());
    int l = 0, r = n - 1;
    while(l <= r) {
        int sum = people[l] + people[r];
        if(sum <= limit) {
            l++; r--; 
            answer++;   // 보트 추가
        }
        else {
            r--; answer++;
        }
    }
    return answer;
}