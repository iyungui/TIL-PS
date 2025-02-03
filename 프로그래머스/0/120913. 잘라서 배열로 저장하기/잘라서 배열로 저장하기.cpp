#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string temp;
    int cnt = 0;
    for(int i = 0; i < my_str.size(); i++) {
        cnt++;
        temp += my_str[i];
        if(cnt == n) {
            answer.push_back(temp);
            temp = "";
            cnt = 0;
        }
    }
    if(!temp.empty()) {
        answer.push_back(temp);
    }
    return answer;
}