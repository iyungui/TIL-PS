#include <bits/stdc++.h>

using namespace std;

// 오른쪽으로 k번 shift
string shift(string s, int k) {
    int n = s.size();
    k %= n;
    return s.substr(n-k) + s.substr(0, n-k);
}

// run-length encoding
string run_encoding(string& s) {
    int cnt = 1;
    string ret = "";
    int n = s.size();
    if(n == 0) return ret;

    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            ret.push_back(s[i-1]);
            ret += to_string(cnt);
            cnt = 1;
        }
        else cnt++;
    }
    ret.push_back(s[n-1]);
    ret += to_string(cnt);

    return ret;
}

int main() {
    string A; cin >> A;

    // Please write your code here.
    int n = A.size();
    int min_len = n * 2 + 10;
    for(int i = 0; i < n; i++) {
        string shifted = shift(A, i);
        string encoded = run_encoding(shifted);
        min_len = min(min_len, (int)encoded.size());
    }

    cout << min_len << '\n';
    return 0;
}
