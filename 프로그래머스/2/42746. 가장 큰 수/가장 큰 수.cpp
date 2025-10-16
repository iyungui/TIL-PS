#include <bits/stdc++.h>
using namespace std;

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    vector<string> a;
    for(const int& n: numbers) a.push_back(to_string(n));
    sort(a.begin(), a.end(), cmp);
    string answer = "";
    for(const string& s: a) {
        answer += s;
    }
    if(answer[0] == '0') return "0";
    
    return answer;
}