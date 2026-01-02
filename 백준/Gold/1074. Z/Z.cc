#include<bits/stdc++.h>
using namespace std;

int n, r, c;

int go(int n) {
    if(n == 0) return 0;
    
    int half = 1 << (n - 1); // 2^(n-1)
    int area = half * half;
    
    // 사분면 번호 계산 (0, 1, 2, 3)
    int quadrant = (r >= half) * 2 + (c >= half);
    
    // 상대 좌표로 변환
    if(r >= half) r -= half;
    if(c >= half) c -= half;
    
    return quadrant * area + go(n - 1);
}

int main() {
    cin >> n >> r >> c;
    cout << go(n) << '\n';
    return 0;
}