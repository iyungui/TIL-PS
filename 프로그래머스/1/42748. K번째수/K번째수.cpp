#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> v : commands) {
        vector<int> temp;
        for(int j = v[0] - 1; j < v[1]; j++) {
            temp.push_back(array[j]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[v[2] - 1]);
    }
    return answer;
}