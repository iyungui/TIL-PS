#include <bits/stdc++.h>
using namespace std;

string s, ret;

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool solve() {
    // 1. 모음이 하나 이상 있어야 한다
    int vowelCnt = 0;
    for(int i = 0; i < (int)s.size(); i++) {
        if(isVowel(s[i])) vowelCnt++;
    }
    if(vowelCnt == 0) return false;
    
    // 2. 모음이나 자음이 3개 연속으로 오면 안된다
    for(int i = 0; i < (int)s.size() - 2; i++) {
        bool v1 = isVowel(s[i]);
        bool v2 = isVowel(s[i + 1]);
        bool v3 = isVowel(s[i + 2]);
        
        // 모음 3개 연속
        if(v1 && v2 && v3) return false;
        // 자음 3개 연속
        if(!v1 && !v2 && !v3) return false;
    }
    
    // 3. 같은 글자가 연속으로 두번 오면 안됨 (ee, oo 제외)
    for(int i = 0; i < (int)s.size() - 1; i++) {
        if(s[i] == s[i + 1]) {
            if(s[i] != 'e' && s[i] != 'o') return false;
        }
    }
    
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
