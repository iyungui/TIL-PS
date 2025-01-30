#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(char i : my_string) {
        if(i >= '0' && i <= '9') answer += (i - '0');
    }
    return answer;
}