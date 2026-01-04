#include<bits/stdc++.h>
using namespace std;

int k;
int a[15], mask[15];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1) {
        cin >> k;
        if(!k) break;
        for(int i = 0; i < k; i++) cin >> a[i];
        for(int i = 6; i < k; i++) mask[i] = 1;
        do {
            for(int i = 0; i < k; i++) {
                if(!mask[i]) cout << a[i] << ' ';
            }
            cout << '\n';
        } while(next_permutation(mask, mask+k));
        cout << '\n';
    }
    return 0;
}