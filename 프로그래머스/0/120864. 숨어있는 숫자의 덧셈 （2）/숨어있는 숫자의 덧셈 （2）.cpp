#include <bits/stdc++.h>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    string temp = "";
    
    for(char c : my_string) {
        if(c >= '0' && c <= '9') {
            temp += c;
        } else {
            if(atoi(temp.c_str())) {
                answer += stoi(temp);
                temp = "";
            }
        }
    }
    if(!temp.empty()) answer += stoi(temp);
    return answer;
}