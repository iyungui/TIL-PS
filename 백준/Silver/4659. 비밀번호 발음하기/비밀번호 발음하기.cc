#include <bits/stdc++.h>
using namespace std;

string s, ret;
int lcnt, vcnt; // 연속 모음, 연속 자음 cnt

bool isVowel(int c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool solve() {
    lcnt = vcnt = 0;
    bool is_include_v = 0;
    int prev = -1;
    
    for(int i = 0; i < s.size(); i++) {
        int idx = s[i];
        if(isVowel(idx)) {
            lcnt++;
            vcnt = 0;
            is_include_v = 1;
        }
        else {
            vcnt++;
            lcnt = 0;
        }
        if(vcnt == 3 || lcnt == 3) return false;
        if(i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')) return false;
        prev = idx;
    }
    if(!is_include_v) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true) {
        cin >> s;
        if(s == "end") break;
        ret += "<" + s + "> is ";
        
        if(solve()) ret += "acceptable.\n";
        else ret += "not acceptable.\n";
    }
    
    cout << ret;
    
    return 0;
}
