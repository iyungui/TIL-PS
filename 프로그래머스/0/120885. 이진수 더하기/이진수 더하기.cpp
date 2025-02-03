#include <bits/stdc++.h>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    int a = 0;
    int b = 0;
    reverse(bin1.begin(), bin1.end());
    reverse(bin2.begin(), bin2.end());
    int value = 1;
    for(int i = 0; i < bin1.size(); i++) {
        a += ((bin1[i] - '0') * value);
        value *= 2;
    }
    value = 1;
    for(int i = 0; i < bin2.size(); i++) {
        b += ((bin2[i] - '0') * value);
        value *= 2;
    }
    int n = a + b;
    if(n == 0) return "0";
    
    while(n > 0) {
        answer = (n % 2 ? '1' : '0') + answer;
        n /= 2;
    }
    return answer;
}