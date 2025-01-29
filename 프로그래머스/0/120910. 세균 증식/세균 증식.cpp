#include <bits/stdc++.h>

using namespace std;

int solution(int n, int t) {
    // 풀이 1: 일반적인 방법
    // while(t--) n *= 2;
    // return n;
    
    // 풀이 2: pow 활용
    return n * pow(2, t);
}