#include <bits/stdc++.h>

using namespace std;

int n, m;
string A[500];
string B[500];
int ret;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> A[i];

    for (int i = 0; i < n; i++) cin >> B[i];

    // Please write your code here.
    // 0부터 M-1까지 수 중에서 세개를 뽑는 조합 X 해당 조합(i, j, k)에서 먼저 A 알파벳들을 set에 넣기
    // B에서 뽑은 알파벳들 중에 하나라도 A그룹에 속한 다면 해당 조합은 X

    for(int i = 0; i < m; i++) {
        for(int j = i+1; j < m; j++) {
            for(int k = j+1; k < m; k++) {
                unordered_set<string> st;
                
                for(int r = 0; r < n; r++) {
                    string a = "";
                    a += A[r][i]; a += A[r][j]; a+= A[r][k]; // 뽑은 세자리수 알파벳 하나
                    st.insert(a);
                }

                bool is_matched = 0;

                for(int r = 0; r < n; r++) {
                    string b = "";
                    b += B[r][i]; b += B[r][j]; b += B[r][k];
                    auto it = st.find(b);
                    if(it != st.end()) {
                        is_matched = 1; break;
                    }
                }

                if(!is_matched) ret++;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}
