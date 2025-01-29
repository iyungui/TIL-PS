#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer;
    for(string s : strlist) {
        answer.push_back((int)s.size());
    }
    return answer;
}