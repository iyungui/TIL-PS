#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> mp;
    for(const auto& c : completion) mp[c]++;
    for(const auto& p : participant) {
        if(mp.find(p) == mp.end()) return p;
        mp[p]--;
        if(mp[p] == 0) mp.erase(p);
    }
    return "";
}