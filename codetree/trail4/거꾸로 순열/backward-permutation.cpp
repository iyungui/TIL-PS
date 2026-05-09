#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    cin >> n;
    vector<int> v;
    for(int i = n; i > 0; i--) v.push_back(i);
    do {
        for(int num : v) cout << num << " ";
        cout << '\n';
    } while(prev_permutation(v.begin(), v.end()));
    return 0;
}