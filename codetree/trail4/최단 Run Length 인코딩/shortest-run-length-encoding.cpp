#include <bits/stdc++.h>

using namespace std;

string shift(string s, int k) {
    int n = s.size();
    return s.substr(n-k) + s.substr(0, n-k);
}

string encoding(string s) {
    string ret = "";
    int num = 1;
    int n = s.size();
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            ret.push_back(s[i-1]);
            ret += to_string(num);
            num = 1;
        }
        else num++;
    }
    ret.push_back(s[n-1]);
    ret += to_string(num);

    return ret;
}

int main() {
    string A; cin >> A;
    int n = A.size();
    int min_length = n * 2 + 10;
    
    for(int i = 0; i < n; i++) {
        string shifted = shift(A, i);
        string encoded = encoding(shifted);
        min_length = min(min_length, (int)encoded.size());
    }

    cout << min_length << '\n';
    
    return 0;
}
