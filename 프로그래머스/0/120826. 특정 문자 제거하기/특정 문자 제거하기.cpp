#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string letter) {
//     // 내 코드 (letter 길이가 2이상이어도 대응됨)
//     while(my_string.find(letter) != string::npos) {
//         my_string.erase(my_string.find(letter), letter.size());
//     }
    
//     return my_string;
    
    // 최적 코드
    my_string.erase(remove(my_string.begin(), my_string.end(), letter[0]), my_string.end());
    return my_string;
}