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
    while (i < days.size()) {
        int count = 1;
        int deployDay = days[i];
        
        while(i + count < days.size() && days[i + count] <= deployDay) {
            count++;
        }
        
        answer.push_back(count);
        i += count;
    }
    
    return answer;
}