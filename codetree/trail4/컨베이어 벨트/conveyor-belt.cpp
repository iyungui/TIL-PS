#include <bits/stdc++.h>
using namespace std;
int N, T;
int main() {
    cin >> N >> T;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    
    while(T--) {
        int tmp_a = A[N-1];
        int tmp_b = B[N-1];

        for(int i = N-1; i >= 1; i--) {
            A[i] = A[i-1];
            B[i] = B[i-1];
        }
        A[0] = tmp_b;
        B[0] = tmp_a;
    }

    for(int i = 0; i < N; i++) cout << A[i] << " ";
    cout << '\n';
    for(int i = 0; i < N; i++) cout << B[i] << " ";
    cout << '\n';

    return 0;
}