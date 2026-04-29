#include <bits/stdc++.h>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int num : numbers) v.push_back(to_string(num));
    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return a + b > b + a;
    });
    for(auto& num : v) answer += num;
    if(answer[0] == '0') return "0";
    return answer;
}