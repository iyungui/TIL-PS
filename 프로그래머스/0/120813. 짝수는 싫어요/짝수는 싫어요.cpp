#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int i = 1;
    while(i <= n) {
        if(i % 2 == 1) answer.push_back(i);
        i++;
    }
    
    return answer;
}