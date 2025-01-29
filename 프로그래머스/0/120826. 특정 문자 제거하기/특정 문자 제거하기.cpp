#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string letter) {
    while(my_string.find(letter) != string::npos) {
        my_string.erase(my_string.find(letter), letter.size());
    }
    
    return my_string;
}