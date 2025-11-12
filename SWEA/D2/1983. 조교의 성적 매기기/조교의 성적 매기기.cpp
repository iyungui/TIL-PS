#include<bits/stdc++.h>

using namespace std;

int T, n, k;
string grade[] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

struct Student {
    int id;
    double total;

    bool operator<(const Student& other) const {
        return total > other.total;
    }

};

int main() {
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> k;

        vector<Student> students(n);
        
        for(int i = 0; i < n; i++) {
            int mid, final, assign;
            cin >> mid >> final >> assign;
            students[i].id = i + 1;
            students[i].total = mid * 0.35 + final * 0.45 + assign * 0.20;
        }

        sort(students.begin(), students.end());

        int rank = 0;
        for(int i = 0; i < n; i++) {
            if(students[i].id == k) {
                rank = i;
                break;
            }
        }
        int gradeIndex = rank / (n / 10);

        cout << "#" << t << " " << grade[gradeIndex] << '\n';
    }

    return 0;
}