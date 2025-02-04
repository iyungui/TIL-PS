#include <bits/stdc++.h>

using namespace std;

string a, b;

string add(string a, string b) {
    int carry = 0;
    string ret = "";
    
    while(a.size() < b.size()) a = '0' + a;
    while(a.size() > b.size()) b = '0' + b;
    
    for(int i = (int)a.size() - 1; i >= 0; i--) {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        ret = char(sum % 10 + '0') + ret;
    }
    if(carry) ret = "1" + ret;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    cout << add(a, b) << '\n';
    return 0;
}
