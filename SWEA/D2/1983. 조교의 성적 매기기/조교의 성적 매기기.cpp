#include<bits/stdc++.h>
using namespace std;

int T, n, k; 
double mid, final, assign;

struct Student {
    int id;
    double total;
};

bool cmp(const Student & a, const Student & b) {
    return a.total > b.total;
}

const string grade[] = {
    "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" 
};

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {

        cin >> n >> k;
        
        vector<Student> s(n);

        for(int i = 0; i < n; i++) {
            cin >> mid >> final >> assign;
            s[i].total = mid * 0.35 + final * 0.45 + assign * 0.2;
            s[i].id = i + 1;
        }

        sort(s.begin(), s.end(), cmp);
        
        int rank = 0;
        for(int i = 0; i < n; i++) {
            if(s[i].id == k) {
                rank = i; break;
            }
        }
        int idx = rank / (n / 10);

        cout << "#" << t << " " << grade[idx] << '\n';
    }
    return 0;
}