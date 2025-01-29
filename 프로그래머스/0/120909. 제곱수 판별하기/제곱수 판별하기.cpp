#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int temp = sqrt(n);
    return ((temp * temp == n) ? 1 : 2);
}