#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> spell, vector<string> dic) {
    // spell의 알파벳들을 정렬
    sort(spell.begin(), spell.end());
    
    // 각 사전 단어에 대해 검사
    for(string word : dic) {
        // 길이가 다르면 무시
        if(word.length() != spell.size()) continue;
        
        // 단어의 각 문자를 정렬
        string temp = word;
        sort(temp.begin(), temp.end());
        
        // 정렬된 문자들이 spell의 문자들과 일치하는지 확인
        bool valid = true;
        for(int i = 0; i < spell.size(); i++) {
            if(spell[i][0] != temp[i]) {
                valid = false;
                break;
            }
        }
        
        if(valid) return 1;
    }
    
    return 2;
}