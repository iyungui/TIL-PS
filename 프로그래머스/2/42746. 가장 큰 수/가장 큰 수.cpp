#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> a;
    for(int num : numbers) {
        a.push_back(to_string(num));
    }
    sort(a.begin(), a.end(), cmp);
    
    string answer = "";
    
    for(string c : a) {
        answer += c;
    }
    if(answer[0] == '0') return "0";
    
    return answer;
}