#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 1;
    int t_slice = slice;
    while(t_slice < n) {
        t_slice += slice;
        answer++;
    }
    return answer;
}