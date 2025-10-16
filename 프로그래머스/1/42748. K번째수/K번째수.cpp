#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (vector<int> com: commands) {
        int i = com[0] - 1;
        int j = com[1] - 1;
        vector<int> temp;
        for(int k = i; k <= j; k++) {
            temp.push_back(array[k]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[com[2] - 1]);
    }
    return answer;
}