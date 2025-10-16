#include <bits/stdc++.h>

using namespace std;

string solution(string number, int k) {
    string stk = "";
    int remain = k;
    
    for(const char& digit: number) {
        while(stk.size() && remain > 0 && stk.back() < digit) {
            stk.pop_back();
            remain--;
        }
        stk.push_back(digit);
    }
    
    while(remain > 0) {
        stk.pop_back();
        remain--;
    }
    return stk;
}