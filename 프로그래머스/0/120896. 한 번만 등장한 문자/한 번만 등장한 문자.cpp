#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    map<char, int> mp;
    for(char c : s) {
        mp[c]++;
    }
    for(auto it : mp) {
        if(it.second == 1) {
            answer += it.first;
        }
    }
    return answer;
}