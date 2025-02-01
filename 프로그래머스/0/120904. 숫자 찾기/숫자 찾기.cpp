#include <string>
#include <vector>

using namespace std;

int solution(int num, int k) {
    int answer = 0;
    string temp = to_string(num);
    for(int i = 0; i < temp.size(); i++) {
        if((int)(temp[i] - '0') == k) {
            answer = i + 1;
            break;
        }
    }
    if(answer == 0) answer = -1;
    return answer;
}