#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; ++i) { // 제곱근까지만 탐색
        if (n % i == 0) {
            count += (i == n / i) ? 1 : 2; 
        }
    }
    return count;
}