/*
 #include <bits/stdc++.h>
 using namespace std;

 // 숫자와 연산자를 따로 저장할 벡터
 vector<int> num;           // 숫자만 저장하는 벡터 (예: "3+8*7" -> [3,8,7])
 vector<char> oper_str;     // 연산자만 저장하는 벡터 (예: "3+8*7" -> ['+','*'])

 // 전역 변수들
 int n;                     // 수식의 길이
 int ret = -987654321;      // 최댓값을 저장할 변수 (충분히 작은 값으로 초기화)
 string s;                  // 입력받을 수식 문자열

 // 입출력 속도 향상을 위한 함수
 void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 }

 // 연산을 수행하는 함수
 // a: 연산자, b,c: 피연산자
 int oper(char a, int b, int c){
    cout << "연산 수행: " << b << a << c << "=";  // 디버깅
    int result;
    if(a == '+') result = b + c;
    if(a == '-') result = b - c;
    if(a == '*') result = b * c;
    cout << result << "\n";  // 디버깅
    return result;
 }

 // 재귀적으로 모든 경우를 탐색하는 함수
 // here: 현재 보고 있는 연산자의 위치
 // _num: 현재까지 계산된 결과
 void go(int here, int _num){
    cout << "\n현재 위치(here): " << here << ", 현재까지의 계산값(_num): " << _num << "\n";  // 디버깅
    
    // 기저 사례: 마지막 숫자까지 왔을 때
    if(here == num.size() - 1){
        cout << "끝에 도달! 현재 ret: " << ret << ", 새로운 값: " << _num << "\n";  // 디버깅
        ret = max(ret, _num);
        return;
    }

    // 1. 괄호 없이 순서대로 계산하는 경우
    cout << "괄호 없이 계산하는 경우\n";  // 디버깅
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));

    // 2. 다음 두 숫자를 괄호로 묶어서 계산하는 경우
    if(here + 2 <= num.size() - 1){  // 앞으로 숫자가 2개 이상 남아있어야 함
        cout << "괄호 사용하는 경우\n";  // 디버깅
        cout << "괄호 안을 먼저 계산: " << num[here + 1] << oper_str[here + 1] << num[here + 2] << "\n";  // 디버깅
        
        // 괄호 안의 계산을 먼저 수행
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        
        // 괄호 계산 결과와 현재까지의 값을 연산
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
 }

 int main(){
    fastIO();
    
    // 입력받기
    cin >> n;   // 수식의 길이
    cin >> s;   // 수식 문자열
    
    // 수식 문자열에서 숫자와 연산자를 분리하여 저장
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){  // 짝수 인덱스: 숫자
            num.push_back(s[i] - '0');  // 문자를 숫자로 변환하여 저장
            cout << "숫자 추가: " << s[i] - '0' << "\n";  // 디버깅
        }
        else{  // 홀수 인덱스: 연산자
            oper_str.push_back(s[i]);
            cout << "연산자 추가: " << s[i] << "\n";  // 디버깅
        }
    }

    // 계산 시작 (첫 번째 숫자를 초기값으로)
    cout << "\n계산 시작!\n";  // 디버깅
    go(0, num[0]);
    
    // 결과 출력
    cout << "\n최종 결과: " << ret << "\n";
    return 0;
 }
 */

#include <bits/stdc++.h>
using namespace std;


// 숫자와 연산자를 따로 저장할 벡터
vector<int> num;    // 숫자만 저장하는 벡터 (ex: "3+8*7" => {3, 8, 7}
vector<char> oper_str;  // 연산자만 저장하는 벡터 (ex: "3+8*7" => {'+', '*'}

// 전역 변수 선언
int n;
int ret = INT_MIN;  // 최댓값을 저장할 변수 (충분히 작은 값으로 초기화)
string s;

// 연산을 수행하는 함수
// a: 연산자
// b, c: 피연산자 (숫자)
int oper(char a, int b, int c) {
//    cout << "연산 수행: " << b << a << c << "=";
    int result;
    if(a == '+') result = b + c;
    if(a == '-') result = b - c;
    if(a == '*') result = b * c;
//    cout << result << '\n';
    return result;
}


// 재귀적으로 모든 경우를 탐색하는 함수
// here: 현재 보고 있는 연산자의 위치
// _num: 현재까지 계산된 결과
void go(int here, int _num) {
//    cout << "\n현재 위치(here): " << here << ", 현재까지의 계산값(_num): " << _num << '\n';
    
    // 기저 사례: 마지막 숫자까지 왔을 때
    if(here == num.size() - 1) {
//        cout << "끝에 도달! 현재 ret: " << ret << ", 새로운 값: " << _num << "\n";
        ret = max(ret, _num);
        return;
    }
    
    // 1. 괄호 없이 순서대로 계산하는 경우
//    cout << "괄호 없이 계산하는 경우, go(" << here + 1 << ", oper(" << oper_str[here] << ", " << _num << ", " << num[here + 1] << ")) 호출\n";
    go(here + 1, oper(oper_str[here], _num, num[here + 1]));
    
    // 2. 다음 두 숫자를 괄호로 묶어서 계산하는 경우
    if(here + 2 <= num.size() - 1) {    // 단, 앞으로 숫자가 2개 이상 남아있어야 함
//        cout << "괄호 사용하는 경우\n"; // 디버깅
//        cout << "괄호 안을 먼저 계산: " << num[here + 1] << oper_str[here + 1] << num[here + 2] << '\n';
        
        // 괄호 안 계산을 먼저 수행
        int temp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
        
        // 괄호 계산 결과와 현재까지의 값을 연산
        go(here + 2, oper(oper_str[here], _num, temp));
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    // 수식 문자열에서 숫자와 연산자를 분리하여 저장
    for(int i = 0; i < n; i++) {
        // 짝수 인덱스: 숫자
        if(i % 2 == 0) {
            num.push_back(s[i] - '0');  // 문자를 숫자로 변환하여 저장
        } else {    // 홀수 인덱스: 연산자
            oper_str.push_back(s[i]);
        }
    }
    
    // 계산 시작 (첫 번째 숫자를 초기값으로)
//    cout << "\n 계산 시작: \n";
    go(0, num[0]);
    
    // 결과 출력
    cout << ret << '\n';
    return 0;
}
