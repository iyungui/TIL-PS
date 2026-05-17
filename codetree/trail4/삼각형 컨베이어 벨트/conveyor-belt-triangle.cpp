#include <bits/stdc++.h>
using namespace std;

int n, t;
int main() {
    cin >> n >> t;
    vector<int> L(n), R(n), D(n);
    for(int i = 0; i < n; i++) cin >> L[i];
    
    for(int i = 0; i < n; i++) cin >> R[i];
    
    for(int i = 0; i < n; i++) cin >> D[i];

    while(t--) {
        int a = L[n-1], b = R[n-1], c = D[n-1];

        for(int i = n-1; i >= 1; i--) {
            L[i] = L[i-1];
            R[i] = R[i-1];
            D[i] = D[i-1];
        }
        L[0] = c;
        R[0] = a;
        D[0] = b;
    }
    
    for(int i = 0; i < n; i++) cout << L[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++) cout << R[i] << " ";
    cout << '\n';
    for(int i = 0; i < n; i++) cout <<  D[i] << " ";

    return 0;
}