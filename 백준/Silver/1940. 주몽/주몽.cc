#include <bits/stdc++.h>

using namespace std;

int n, m, temp, sum, ret;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            sum = v[i] + v[j];
            if(sum == m) {
                ret++;
            }
        }
    }
    cout << ret;
    return 0;
}
