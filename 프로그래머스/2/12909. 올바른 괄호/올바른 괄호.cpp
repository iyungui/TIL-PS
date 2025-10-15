#include<bits/stdc++.h>

using namespace std;

bool solution(string s) {
    int n = 0;
    for(int i = 0; i <s.size(); i++) {
        if (s[i] == '(') n++;
        else if (--n < 0) return false;
    }
    return n == 0;
}