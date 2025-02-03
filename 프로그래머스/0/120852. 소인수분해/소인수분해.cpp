#include <string>
#include <vector>
#include <set>

using namespace std;


vector<int> solution(int n) {
    set<int> factors;  // 중복을 제거하기 위해 set 사용
    
    // 2부터 시작하여 나눌 수 있을 때까지 나누기
    for(int i = 2; i * i <= n; i++) {
        while(n % i == 0) {
            factors.insert(i);
            n /= i;
        }
    }
    
    // 남은 수가 1보다 크면 그 수도 소인수
    if(n > 1) {
        factors.insert(n);
    }
    
    // set을 vector로 변환 (자동으로 오름차순 정렬됨)
    return vector<int>(factors.begin(), factors.end());
}