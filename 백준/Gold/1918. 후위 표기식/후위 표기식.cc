#include <bits/stdc++.h>
using namespace std;

// 연산자의 우선순위를 반환하는 함수
int prec(char op) {
    if (op == '(' || op == ')') return 0;
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return -1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    stack<char> s;

    for (char c : str) {
        if (isupper(c)) { // 1. 피연산자(A-Z)
            cout << c;
        } else if (c == '(') { // 2. 왼쪽 괄호
            s.push(c);
        } else if (c == ')') { // 3. 오른쪽 괄호
            while (!s.empty() && s.top() != '(') {
                cout << s.top();
                s.pop();
            }
            s.pop(); // '(' 제거
        } else { // 4. 연산자
            // 나보다 우선순위가 높거나 같은 것들은 다 뱉어내게 함
            while (!s.empty() && prec(s.top()) >= prec(c)) {
                cout << s.top();
                s.pop();
            }
            s.push(c);
        }
    }

    // 5. 남은 것들 모두 출력
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << '\n';

    return 0;
}