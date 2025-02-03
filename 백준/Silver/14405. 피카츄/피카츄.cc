#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int i = 0;
    while(i < s.length()) {
        // "pi"로 시작하는 경우
        if(i + 1 < s.length() && s.substr(i, 2) == "pi") {
            i += 2;
        }
        // "ka"로 시작하는 경우
        else if(i + 1 < s.length() && s.substr(i, 2) == "ka") {
            i += 2;
        }
        // "chu"로 시작하는 경우
        else if(i + 2 < s.length() && s.substr(i, 3) == "chu") {
            i += 3;
        }
        // 어떤 패턴도 매칭되지 않는 경우
        else {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";
    return 0;
}
