#include <string>
#include <vector>

using namespace std;

string solution(int age) {
    string answer = "";
    string temp = to_string(age);
    for(char c : temp) {
        answer += (c - '0' + 'a');
    }
    return answer;
}