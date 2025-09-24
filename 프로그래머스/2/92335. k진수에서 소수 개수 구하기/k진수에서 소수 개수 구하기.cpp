#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n == 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string str;

    while (n) {
        str += n % k + 48;
        n /= k;
    }

    reverse(str.begin(), str.end());
    str += 48;

    int ans = 0;

    for (long long hold = 0, i = 0; i < str.size(); ++i) {
        if (str[i] == '0') {    // 분기점
            if (is_prime(hold)) ++ans;
            hold = 0;
            continue;
        }
        hold = 10 * hold + str[i] - 48;
    }

    return ans;
}