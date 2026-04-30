#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string ans = "";
    int cnt = 0;
    for(char num : number) {
        while(cnt < k && ans.size() && ans.back() < num) {
            cnt++;
            ans.pop_back();
        }
        ans.push_back(num);
    }
    while(cnt < k && ans.size()) {
        ans.pop_back();
        cnt++;
    }
    return ans;
}