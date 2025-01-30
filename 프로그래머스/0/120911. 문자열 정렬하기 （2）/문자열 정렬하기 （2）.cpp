#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char c : my_string) {
        if(c < 97 && c >= 65) {
            answer += (c + 32);
        } else if(c >= 97) {
            answer += c;
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}