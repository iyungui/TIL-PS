#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int cnt = 0;
    cnt = (int)n / 7;
    if(n % 7 > 0) cnt++;
    return cnt;
}