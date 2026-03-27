#include<bits/stdc++.h>

using namespace std;

struct Info {
    string place;
    int max_cnt, st, ed;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    // 중복학생 체크용
    set<string> names;
    // 장소별 시간 카운트 배열(1~50000)
    map<string, vector<int>> place_data;

    for(int i = 0; i < n; i++) {
        string name, place;
        int st, ed;
        cin >> name >> place >> st >> ed;

        // 1. 학생 중복 제출 방지
        if(names.count(name))continue;
        names.insert(name);

        // 2. 장소별 시간대 카운팅(처음 등장하는 장소면 벡터 크기 초기화)
        if(place_data.find(place) == place_data.end()) place_data[place].resize(50005, 0);
        for(int t = st; t < ed; t++) {
            place_data[place][t]++;
        }
    }

    Info best = {"", -1, 0, 0};
    // 각 장소를 순회(map은 키 기준 자동 정렬됨)
    for(auto const& [place, counts] : place_data) {
        int max_val = 0;
        for(int t = 1; t <= 50000; t++) {
            max_val = max(max_val, counts[t]);
        }

        if(max_val == 0) continue;

        // 해당 장소에서 max_val이 유지되는 가장 빠르고 가장 긴 구간 찾기
        int s, e;

        for(int t = 1; t <= 50000; t++) {
            if(counts[t] == max_val) {
                s = t;
                while(t <= 50000 && counts[t] == max_val) {
                    t++;
                }
                e = t;

                // 가장 빠른 시간대를 찾아야 하므로, 첫 번째 발견된 구간만 확인
                break;
            }
        }

        // 1)인원수, 2,3,4) 사전순 장소(이미정렬됨), 가장 빠른. 긴 시간대는 이미 장소별로찾음
        if(max_val > best.max_cnt) {
            best = {place, max_val, s, e};
        }
    }

    cout << best.place << " " << best.st << " " << best.ed << '\n';
    return 0;
}