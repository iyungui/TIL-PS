#include<bits/stdc++.h>

using namespace std;

int T;
string s;

int go(char ch) {
    if(ch >= 'A' && ch <= 'Z') return ch - 'A';
    if(ch >= 'a' && ch <= 'z') return 26 + (ch - 'a');
    if(ch >= '0' && ch <= '9') return 52 + (ch - '0');
    if(ch == '+') return 62;
    if(ch == '/') return 63;
    return 0;
}

string decodeBase64() {
    string result = "";
    for(int i = 0; i < s.size(); i += 4) {
        int v1 = go(s[i]);
        int v2 = go(s[i+1]);
        int v3 = go(s[i+2]);
        int v4 = go(s[i+3]);

        int b1 = (v1 << 2) | (v2 >> 4);
        int b2 = ((v2 & 0x0F) << 4) | (v3 >> 2);
        int b3 = ((v3 & 0x03) << 6) | v4;

        result += string{char(b1), char(b2), char(b3)};
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    for(int t = 1; t <= T; t++) {
        cin >> s;
        cout << "#" << t << " " << decodeBase64() << "\n";
    }
}