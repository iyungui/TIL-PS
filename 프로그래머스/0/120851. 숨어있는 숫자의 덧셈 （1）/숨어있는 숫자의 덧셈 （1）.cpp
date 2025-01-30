#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(char c : my_string) {
        if(c < 65) answer += (c - '0');
    }
    return answer;
}