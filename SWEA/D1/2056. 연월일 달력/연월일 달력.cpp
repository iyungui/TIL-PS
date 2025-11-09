#include<bits/stdc++.h>

using namespace std;

int T;
string s;
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> s;
        string y = s.substr(0, 4);
        string m = s.substr(4, 2);
        string d = s.substr(6, 2);

        int mm = stoi(m);
        int dd = stoi(d);

        bool flag = false;

        if(mm < 1 || mm > 12) flag = true;
        else if(dd < 1 || dd > days[mm]) flag = true;

        cout << "#" << t << " ";
        if(flag) cout << -1 << '\n';
        else cout << y << "/" << m << "/" << d << '\n';
    }
    return 0;
}