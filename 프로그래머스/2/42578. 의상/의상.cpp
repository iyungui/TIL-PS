#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> mp;
    for(const vector<string>& c : clothes) {
        mp[c[1]]++;
    }
    int ret = 1;
    for(const auto& it: mp) {
        ret *= it.second + 1;
    }
    return ret - 1;
}