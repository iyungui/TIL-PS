#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> mp;
    
    for(const string& par : participant) {
        mp[par]++;
    }
    for(const string& com : completion) {
        mp[com]--;
    }
    for(const auto& it: mp) {
        if (it.second > 0) return it.first;
    }
    return "";
}