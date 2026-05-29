#include <bits/stdc++.h>

using namespace std;

struct File {
    string head;
    int number;
    string original;
    int idx;
};

File parse(const string& s, int idx) {
    int n = (int)s.size();
    int i;
    string h = "";
    for(i = 0; i < n; i++) {
        if(!isdigit(s[i])) {
            char c = tolower(s[i]); // 소문자로 통일
            h.push_back(c);
        }
        else break;
    }
    string num = "";
    for(; i < n; i++) {
        int c = (int)num.size();
        if(c < 5 && isdigit(s[i])) num.push_back(s[i]);
        else break;
    }
    int tmp = stoi(num);    // 앞의 0 제거
    
    return {h, tmp, s, idx};
}

bool cmp(const File& a, const File& b) {
    if(a.head != b.head) return a.head < b.head;
    if(a.number != b.number) return a.number < b.number;
    return a.idx < b.idx;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<File> fs;
    // 1. 파일명을 세 부분으로 나누기
    for(int i = 0; i < (int)files.size(); i++) {
        fs.push_back(parse(files[i], i));
    }
    // 2. 기준에 따라 정렬하기 
    sort(fs.begin(), fs.end(), cmp);
    // 3. 정렬된 배열을 출력하기
    for(const auto& f : fs) answer.push_back(f.original);
    return answer;
}