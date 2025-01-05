#include <bits/stdc++.h>

using namespace std;

string str;
stack<char> s;
int n;
int mid, start;

bool pelindrome() {
    for(int i = 0; i <= mid; i++) {
        s.push(str[i]);
    }
    
    for(int i = start; i < n; i++) {
        if(s.top() == str[i]) {
            s.pop();
        }
    }
    
    if(s.empty()) return true;
    return false;
}

int main() {
    cin >> str;
    n = (int)str.size();
    mid = n / 2 - 1;
    
    if(n % 2 == 0) start = mid + 1;
    else start = mid + 2;
    
    if(pelindrome()) cout << 1;
    else cout << 0;
    
    return 0;
}
