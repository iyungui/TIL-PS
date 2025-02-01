#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    while(n) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                cnt++;
            }
        }
        if(cnt >= 3) {
            cout << n << " ";
            answer++;
        }
        n--;
    }
    return answer;
}