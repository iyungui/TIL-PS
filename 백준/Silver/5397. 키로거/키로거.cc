#include<bits/stdc++.h>
using namespace std;

int t;
string s;
int main(){
    cin >> t;
    while(t--) {
        cin >> s;
        list<char> L = {};
        auto p = L.begin();

        for(char c : s) {
            if(c == '<' && p != L.begin()) p--;
            else if(c == '>' && p != L.end()) p++;
            else if(c == '-' && p != L.begin()) p = L.erase(--p);
            else if(c != '<' && c != '>' && c != '-')  L.insert(p, c);
        }

        for(auto c : L) cout << c;
        cout << '\n';
    }
}