#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    // visited 이용 방법
    
//     string answer = "";
//     bool visited[128] = {false};
    
//     for(char c : my_string) {
//         if(!visited[c]) {
//             answer += c;
//             visited[c] = true;
//         }
//     }
    
    // string.find 이용 방법 (추천)
    string answer = "";
    for(char c : my_string) {
        if(answer.find(c) == string::npos) {
            answer += c;
        }
    }
    return answer;
}