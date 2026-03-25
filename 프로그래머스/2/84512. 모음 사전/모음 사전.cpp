#include <string>
#include <vector>

using namespace std;

string s = "AEIOU";
vector<string> dict;

void dfs(string cur) {
    dict.push_back(cur);
    if(cur.size() == 5) return;
    for(char c : s) dfs(cur + c);
}

int solution(string word) {
    dfs("");
    for(int i = 0; i < (int)dict.size(); i++) {
        if(dict[i] == word) return i;
    }
    return 0;
}