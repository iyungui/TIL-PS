#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string & input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while(end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int solution(string s) {
    int answer = 0;
    vector<string> num = split(s, " ");
    string prev;
    for(string str : num) {
        if(str == "Z") {
            answer -= stoi(prev);
        } else {
            answer += stoi(str);
            prev = str;
        }
    }
    return answer;
}