#include <bits/stdc++.h>
using namespace std;

unordered_set<int> A, B;
int a, b;
int main() {
    cin >> a >> b;
    for(int i = 0; i < a; i++) {
        int num; cin >> num;
        A.insert(num);
    }
    for(int i = 0; i < b; i++) {
        int num; cin >> num;
        B.insert(num);
    }
    unordered_set<int> ret;
    for(int num : A) {
        if(B.find(num) == B.end()) ret.insert(num);
    }
    for(int num : B) {
        if(A.find(num) == A.end()) ret.insert(num);
    }
    cout << (int)ret.size() << '\n';
    return 0;
}