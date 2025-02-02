#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> emergency) {
    vector<int> answer(emergency.size());
    vector<int> temp = emergency;
    sort(temp.begin(), temp.end(), greater<int>());
    for(int i = 0; i < emergency.size(); i++) {
        auto it = find(temp.begin(), temp.end(), emergency[i]);
        answer[i] = it - temp.begin() + 1;
    }
    return answer;
}