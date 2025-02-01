#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n) {
    int s = (int)num_list.size() / n;
    vector<vector<int>> answer(s, vector<int>(n));
    for(int i = 0; i < num_list.size(); i++) {
        answer[i / n][i % n] = num_list[i];
    }
    return answer;
}