#include<bits/stdc++.h>

using namespace std;

int T;
string s;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> s;
        int y = stoi(s.substr(0, 4));
        int m = stoi(s.substr(4, 2));
        int d = stoi(s.substr(6, 2));
        
        bool vaild = (m >= 1 && m <= 12 && d >= 1 && d <= days[m]);
        
        cout << "#" << t << " ";
        if(vaild) printf("%04d/%02d/%02d\n", y, m, d);
        else cout << -1 << '\n';
    }
    return 0;
}