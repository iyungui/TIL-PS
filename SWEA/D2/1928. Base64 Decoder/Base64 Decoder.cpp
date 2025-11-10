#include<bits/stdc++.h>

using namespace std;

int T;

// 표를 보고 Base64문자를 0-63 사이의 숫자로 변환하는 함수
int charToValue(char c) {
    if(c >= 'A' && c <= 'Z') return c - 'A';
    else if(c >= 'a' && c <= 'z') return 26 + (c - 'a');
    else if(c >= '0' && c <= '9') return 52 + (c - '0');
    else if(c == '+') return 62;
    else if(c == '/') return 63;
    return 0;
}

string decodeBase64(string encoded) {
    string result = "";

    // 4글자씩 처리
    for(int i = 0; i < encoded.length(); i += 4) {
        int v1 = charToValue(encoded[i]);
        int v2 = charToValue(encoded[i+1]);
        int v3 = charToValue(encoded[i+2]);
        int v4 = charToValue(encoded[i+3]);

        int byte1 = (v1 << 2) | (v2 >> 4);
        int byte2 = ((v2 & 0x0F) << 4) | (v3 >> 2);
        int byte3 = ((v3 & 0x03) << 6) | v4;

        result += (char)byte1;
        result += (char)byte2;
        result += (char)byte3;
    }
    return result;
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        string encoded;
        cin >> encoded;

        string decoded = decodeBase64(encoded);

        cout << "#" << t << " " << decoded << '\n';
    }
    return 0;
}