#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;
int n;

const int T = 10;

int main() {
    for(int t = 1; t <= T; t++) {
        cin >> n >> s;
        
        vector<ll> nums;
        vector<char> ops;

        ll temp = s[0] - '0';

        for(int i = 1; i < n; i+=2) {
            char op = s[i];
            int num = s[i+1] - '0';
            if(op == '*') {
                temp *= num;
            } else {
                nums.push_back(temp);
                ops.push_back('+');
                temp = num;
            }
        }
        nums.push_back(temp);

        ll ret = 0;
        for(ll num : nums) ret += num;
        cout << "#" << t << " " << ret << '\n';
    }
}