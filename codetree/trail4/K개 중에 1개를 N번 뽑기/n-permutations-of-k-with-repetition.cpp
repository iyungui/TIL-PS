#include <iostream>

using namespace std;

int K, N;

int chosen[10];

void go(int idx) {
    if(idx == N) {  // N개를 다 선택했을 때
        // output
        for(int i = 0; i < N; i++) {
            cout << chosen[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i <= K; i++) {
        chosen[idx] = i;
        go(idx+1);
    }
}

int main() {
    cin >> K >> N;

    go(0);

    return 0;
}
