#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    for(char c : my_string) {
        if(c >= 65 && c < 97) {
            answer += (c + 32);
        }
        else if(c >= 97) {
            answer += (c - 32);
        }
    }
    return answer;
}