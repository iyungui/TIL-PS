#include <bits/stdc++.h>
using namespace std;

string solution(string rsp) {
    string answer = "";
    unordered_map<char, char> mp;
    mp['0'] = '5';
    mp['2'] = '0';
    mp['5'] = '2';
    for(char c : rsp) {
        answer += mp[c];
    }
    return answer;
}