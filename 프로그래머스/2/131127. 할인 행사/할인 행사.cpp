#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> v;
    for(int i = 0; i < want.size(); i++) {
        v[want[i]] = number[i];
    }
    int n = discount.size();
    for(int i = 0; i <= n - 10; i++) {
        map<string, int> v2;
        for(int j = i; j < i + 10; j++) {
            v2[discount[j]]++;
        }
        if(v == v2) answer++;
    }
    return answer;
}