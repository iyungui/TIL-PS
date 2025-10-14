#include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> hash_set;
    
    for(const string& phone: phone_book) {
        hash_set.insert(phone);
    }
    
    for (const string& phone: phone_book) {
        for(int i = 1; i < phone.size(); i++) {
            if(hash_set.find(phone.substr(0, i)) != hash_set.end()) {
                return false;
            }
        }
    }
    
    return true;
}