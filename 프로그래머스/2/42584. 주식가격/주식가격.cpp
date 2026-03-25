#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> stk;
    for(int i = 0; i < n; i++) {
        while(stk.size() && prices[stk.top()] > prices[i]) {
            int t = stk.top();
            answer[t] = i - t;
            stk.pop();
        }
        stk.push(i);
    }
    while(stk.size()) {
        int t = stk.top(); stk.pop();
        answer[t] = n - 1 - t;
    }
    
    return answer;
}
/*
스택에 인덱스를 넣는다
0 1 2 3 4
3을 넣을 때, p[2]보다 p[3]이 더 작으므로, p[3]은 1
*/