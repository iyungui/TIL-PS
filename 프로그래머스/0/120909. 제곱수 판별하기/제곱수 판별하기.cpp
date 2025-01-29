#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    for(int i = 0; i < n; i++) {
        if(i * i == n) return 1;
    }
    return 2;
}