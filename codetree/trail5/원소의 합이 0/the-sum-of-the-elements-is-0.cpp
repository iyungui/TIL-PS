#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int A[5000];
int B[5000];
int C[5000];
int D[5000];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    for (int i = 0; i < n; i++) cin >> C[i];

    for (int i = 0; i < n; i++) cin >> D[i];

    // Please write your code here.
    unordered_map<ll, int> mp;
    int ret = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mp[A[i] + B[j]]++;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int t = -((ll)C[i]+D[j]);

            if(mp.find(t) != mp.end()) ret += mp[t];
        }
    }

    cout << ret << '\n';
    return 0;
}
