#include <bits/stdc++.h>

using namespace std;

int a[] = {1,2,3,4,5};
int b[] = {2,1,2,3,2,4,2,5};
int c[] = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    vector<int> scores(3);
    
    for(int i = 0; i < (int)answers.size(); i++) {
        if(a[i%5] == answers[i]) scores[0]++;
        if(b[i%8] == answers[i]) scores[1]++;
        if(c[i%10] == answers[i]) scores[2]++;
    }
    
    // 가장 높은 점수를 받은 사람 찾기
    // 가장 높은 점수 mx
    int mx = *max_element(scores.begin(), scores.end());
    vector<int> ret;
    for(int i = 0; i < 3; i++) {
        if(scores[i] == mx) ret.push_back(i + 1);
    }
    
    // 오름차순 정렬
    sort(ret.begin(), ret.end());
    return ret;
}