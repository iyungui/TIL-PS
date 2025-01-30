#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b % a, a);
}
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int solution(int n) {
    // int answer = 0;
    // for(int i = 1; i <= n; i++) {
    //     if((i * 6) % n == 0) {
    //         answer = i;
    //         break;
    //     }
    // }
    // return answer;
    
    // 최대공약수 gcd 사용
    return lcm(6, n) / 6;
}