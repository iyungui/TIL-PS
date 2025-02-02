#include <string>
#include <vector>
#include <iostream>

using namespace std;

int f(int n) {
    if(n <= 1) return 1;
    return n * f(n - 1);
}

int solution(int n) {
    int answer = 0;
    for(int i = 0; i <= n; i++) {
        if(f(i) <= n) {
            answer = i;
        } else break;
    }
    return answer;
}