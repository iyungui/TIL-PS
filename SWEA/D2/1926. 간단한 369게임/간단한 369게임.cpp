#include<bits/stdc++.h>

using namespace std;

int N;

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int num = i;
        int cnt = 0;
        while(num > 0) {
            int temp = num % 10;
            if(temp == 3 || temp == 6 || temp == 9) cnt++;
            num /= 10;
        }
        if(cnt) {
            while(cnt--) cout << "-";
        } else {
            cout << i;
        }
        if(i < N) cout << " ";
    }
    return 0;
}