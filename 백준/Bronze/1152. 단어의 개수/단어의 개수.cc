#include <bits/stdc++.h>
using namespace std;

string s;
int cnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, s);
    
    for(int i = 1; i < s.size(); i++) {
        if(s[i-1] == ' ' && s[i] != ' ') cnt++;
    }
    if(!s.empty() && s[0] != ' ') cnt++;
    
    cout << cnt << '\n';
    return 0;
}