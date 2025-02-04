#include <bits/stdc++.h>

using namespace std;

string s;
bool flag;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")) i++;
        else if(i < s.size() - 2 && s.substr(i, 3) == "chu") i += 2;
        else {
            flag = 1;
            break;
        }
    }
    cout << ((flag == 1) ? "NO" : "YES") << '\n';
    return 0;
}
