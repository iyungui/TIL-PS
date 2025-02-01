#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int size = num_list.size() / n;  // 몇 개의 행이 필요한지 계산
    vector<vector<int>> answer(size, vector<int>(n));
    
    for(int i = 0; i < num_list.size(); i++) {
        answer[i/n][i%n] = num_list[i];
    }
    
    return answer;
}