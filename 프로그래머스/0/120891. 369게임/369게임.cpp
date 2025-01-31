#include <string>
#include <vector>

using namespace std;

int solution(int order) {
    int answer = 0;
    string temp = to_string(order);
    for(char i : temp) {
        if(i == '3' || i == '6' || i == '9') answer++;
    }
    return answer;
}