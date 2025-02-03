#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    for(int i : array) {
        string temp = to_string(i);
        for(char c : temp) {
            if(c == '7') answer++;
        }
    }
    return answer;
}