#include <string>
#include <vector>

using namespace std;

int getDir(string s) {
    if(s == "up") return 0;
    if(s == "right") return 1;
    if(s == "down") return 2;
    if(s == "left") return 3;
    return 0;
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    int dy[] = {1, 0, -1, 0};
    int dx[] = {0, 1, 0, -1};
    int x = 0, y = 0;
    int my = (int)board[1] / 2;
    int mx = (int)board[0] / 2;
    for(int i = 0; i < keyinput.size(); i++) {
        int dir = getDir(keyinput[i]);
        int ny = y + dy[dir];
        int nx = x + dx[dir];
        
        if(ny >= -my && ny <= my && nx >= -mx && nx <= mx) {
            y = ny;
            x = nx;
        }
    }
    return {x, y};
}