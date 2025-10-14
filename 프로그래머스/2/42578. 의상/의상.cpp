#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    
    for(vector<string> cloth: clothes) {
        string type = cloth[1];
        mp[type] += 1;
    }
    
    for (auto& pair: mp) {
        answer *= (pair.second + 1);
    }
    return answer - 1;
}