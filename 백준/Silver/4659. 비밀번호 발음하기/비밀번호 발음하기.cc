#include <bits/stdc++.h>

using namespace std;

string s, ret;
int lcnt, rcnt;

bool isVowel(int idx) {
    return idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while(true) {
        cin >> s;
        if(s == "end") break;
        lcnt = rcnt = 0;
        bool flag = 0;
        bool is_include_v = 0;
        char prev = -1;
        for(int i = 0; i < s.size(); i++) {
            if(isVowel(s[i])) lcnt++, rcnt = 0, is_include_v = 1;
            else rcnt++, lcnt = 0;
            if(i >= 1 && (prev == s[i]) && (prev != 'e' && prev != 'o')) flag = 1;
            if(lcnt == 3 || rcnt == 3) flag = 1;
            prev = s[i];
        }
        if(!is_include_v) flag = 1;
        if(flag) cout << "<" << s << "> is not acceptable.\n";
        else cout << "<" << s << "> is acceptable.\n";
        
    }
    
    
    return 0;
}
