#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> a = {1, 2, 3, 4, 5}; // 1번 수포자
    vector<int> b = {2, 1, 2, 3, 2, 4, 2, 5}; // 2번 수포자
    vector<int> c = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 3번 수포자
    
    vector<int> score(3);
    for(int i = 0; i < answers.size(); i++) {
        if(a[i % a.size()] == answers[i]) score[0]++;
        if(b[i % b.size()] == answers[i]) score[1]++;
        if(c[i % c.size()] == answers[i]) score[2]++;
    }
    int max_score = *max_element(score.begin(), score.end());
    vector<int> answer;
    for(int i = 0; i < 3; i++) {
        if(score[i] == max_score) answer.push_back(i + 1);
    }
    return answer;
}