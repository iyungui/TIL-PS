#include <bits/stdc++.h>

using namespace std;

#define MAX_NUM 64

int n;
string s;
char arr[101][101];

string solution(int y, int x, int size) {
    if(size == 1) return string(1, arr[y][x]);
    char b = arr[y][x];   // 0인지 1인지 알기 위해서 일단 뽑고
    string ret = "";
    
    for(int i = y; i < y + size; i++) {
        for(int j = x; j < x + size; j++) {
            if(b != arr[i][j]) {
                ret += '(';
                ret += solution(y, x, size / 2);
                ret += solution(y, x + size / 2, size / 2);
                ret += solution(y + size / 2, x, size / 2);
                ret += solution(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
        }
    }
    
    return string(1, arr[y][x]);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s;
        
        for(int j = 0; j < n; j++) {
            arr[i][j] = s[j];
        }
    }
    
                // sx, sy, size
    // size는 n부터
    cout << solution(0, 0, n) << '\n';
    return 0;
}
