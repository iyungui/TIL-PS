#include <bits/stdc++.h>

using namespace std;

string str, ret;

void toPW() {
    for(int a : str) {
        // 대문자
        if(a >= 65 && a <= (65 + 26)) {
            int next_a = a + 13;
            if(next_a >= 65 + 26) {
                // 초과 값
                int temp = next_a - (65 + 26);
                next_a = 65 + temp;
            }
            ret += next_a;
        }
        // 소문자
        else if(a >= 97 && a <= (97 + 26)) {
            int next_a = a + 13;
            if(next_a >= 97 + 26) {
                // 초과 값
                int temp = next_a - (97 + 26);
                next_a = 97 + temp;
            }
            ret += next_a;
          
        // 공백
        } else {
            ret += a;
        }
    }
}

int main() {
    
    getline(cin, str);
    
    toPW();
    
    cout << ret;
    
    return 0;
}
