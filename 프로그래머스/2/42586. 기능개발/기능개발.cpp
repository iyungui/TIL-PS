#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    
    for(int i = 0; i < progresses.size(); i++) {
        int remaining = 100 - progresses[i];
        int day = (remaining + speeds[i] - 1) / speeds[i];
        days.push_back(day);
    }
    int i = 0;
    while(i < days.size()) {
        int cnt = 1;
        int deploy = days[i];
        while (i + cnt < days.size() && days[i + cnt] <= deploy) {
            cnt++;
        }
        answer.push_back(cnt);
        i += cnt;
    }
    return answer;
}