#include<bits/stdc++.h>

using namespace std;

const int n = 10;
int T;
int sum;
int temp;

int main() {
    cin >> T;
    for(int i = 1; i <= T; i++) {
        sum = 0;
        for(int j = 0; j < n; j++) {
            cin >> temp;
            sum += temp;
        }
        double avg = (double) sum / n;
        cout << "#" << i << " " << (int)round(avg) << '\n';
    }
    return 0;
}