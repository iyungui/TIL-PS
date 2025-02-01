#include <bits/stdc++.h>

using namespace std;

string solution(string letter) {
    map<string, char> morse = {
        {".-", 'a'},  {"-...", 'b'}, {"-.-.", 'c'}, {"-..", 'd'},
        {".", 'e'},   {"..-.", 'f'}, {"--.", 'g'},  {"....", 'h'},
        {"..", 'i'},  {".---", 'j'}, {"-.-", 'k'},  {".-..", 'l'},
        {"--", 'm'},  {"-.", 'n'},   {"---", 'o'},  {".--.", 'p'},
        {"--.-", 'q'},{".-.", 'r'},  {"...", 's'},  {"-", 't'},
        {"..-", 'u'}, {"...-", 'v'}, {".--", 'w'},  {"-..-", 'x'},
        {"-.--", 'y'},{"--..", 'z'}
    };
    
    string answer = "";
    string code = "";
    
    for(int i = 0; i < letter.size(); i++) {
        if(letter[i] == ' ') {
            answer += morse[code];
            code = "";
        } else {
            code += letter[i];
        }
    }
    answer += morse[code];
    return answer;
}