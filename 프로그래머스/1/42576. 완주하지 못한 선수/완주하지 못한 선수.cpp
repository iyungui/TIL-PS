#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> hash_map;
    
    for (const string& name: participant) {
        hash_map[name]++;
    }
    
    for (const string& name: completion) {
        hash_map[name]--;
    }
    
    for (const auto& pair: hash_map) {
        if (pair.second > 0) {
            return pair.first;
        }
    }
    return "";
}