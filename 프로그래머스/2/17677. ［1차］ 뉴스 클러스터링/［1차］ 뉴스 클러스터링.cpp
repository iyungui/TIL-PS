#include <string>

using namespace std;

const int mod = 65536;
const int T = 676;
int A[T], B[T];

void parse(const string& s, int cnt[]) {
    for(int i = 0; i < (int)s.size()-1; i++) {
        if(isalpha(s[i]) && isalpha(s[i+1])) {
            int c = (tolower(s[i]) - 'a') * 26 + (tolower(s[i+1]) - 'a');
            cnt[c]++;
        }
    }
}

int solution(string str1, string str2) {
    parse(str1, A);
    parse(str2, B);
    int answer = 0;
    int inter = 0, uni = 0;
    
    for(int i = 0; i < T; i++) {
        inter += min(A[i], B[i]);
        uni += max(A[i], B[i]);
    }
    if(uni == 0) return mod;
    return (int)((double)inter / uni * mod);
}