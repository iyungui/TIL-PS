#include <string>
#include <vector>

using namespace std;

string solution(string my_string) {
    string answer = "";
    bool visited[128] = {false};
    
    for(char c : my_string) {
        if(!visited[c]) {
            answer += c;
            visited[c] = true;
        }
    }
    return answer;
}