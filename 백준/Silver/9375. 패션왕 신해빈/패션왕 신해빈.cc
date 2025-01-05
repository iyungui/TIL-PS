
#include <bits/stdc++.h>

using namespace std;

class Clothes {
    public:
        string name, type;
    
    Clothes(string name, string type) {
        this->name = name;
        this->type = type;
    }
    
    Clothes() {};
};

int total_case, n;
Clothes clothes[30];

int GetCase() {
    // 의상 종류별 개수를 세기 위한 map
    map<string, int> type_count;
    
    // 각 의상의 type별로 개수를 센다
    for(int i = 0; i < n; i++) {
        type_count[clothes[i].type]++;
    }
    
    // 각 종류별로 (안입는 경우 + 해당 종류의 옷 개수)를 모두 곱한 뒤
    // 아무것도 안입는 경우 1을 뺀다
    int cnt = 1;
    for(auto it : type_count) {
        cnt *= (it.second + 1);
    }
    
    return cnt - 1;
}

int main() {
    cin >> total_case;
    
    for(int i = 0; i < total_case; i++) {
        cin >> n;   // 의상의 수
        
        for(int j = 0; j < n; j++) {
            string name, type;
            
            cin >> name >> type;
            
            clothes[j] = Clothes(name, type);
        }
        
        cout << GetCase() << '\n';
        
    }
    return 0;
}
