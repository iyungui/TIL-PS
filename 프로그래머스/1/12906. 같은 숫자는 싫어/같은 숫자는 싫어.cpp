#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    for(int a : arr) {
        if(answer.size() && answer.back() == a) continue;
        answer.push_back(a);
    }
    
    return answer;
}