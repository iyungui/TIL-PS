#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    int mx, mn;
    if(sides[0] > sides[1]) {
        mx = sides[0];
        mn = sides[1];
    } else {
        mx = sides[1];
        mn = sides[0];
    }
    // mx 가 가장 긴 변인 경우
    // mn + x > mx
    for(int i = 1; i < mx; i++) {
        if(mn + i > mx) answer++;
    }
    
    // x가 가장 긴 변인 경우
    // mn + mx > x
    for(int i = 0; i < mn; i++) {
        answer++;
    }
    
    return answer;
}