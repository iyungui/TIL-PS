#include<bits/stdc++.h>

using namespace std;

struct Info {
    string p;
    int cnt, st, ed;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;

    map<string, vector<int>> cnt;
    set<string> names;

    for(int i = 0; i < n; i++) {
        string name, place;
        int st, ed;
        cin >> name >> place >> st >> ed;

        if(names.count(name)) continue;
        names.insert(name);

        // 처음 나온 장소이면 벡터크기 초기화
        if(cnt.find(place) == cnt.end()) {
            cnt[place].resize(50004, 0);
        };

        for(int t = st; t < ed; t++) {
            cnt[place][t]++;
        }
    }

    Info best = {"", -1, 0, 0};

    for(auto const& [place, counts] : cnt) {
        int cur_max_cnt = 0;

        for(int t = 1; t <= 50000; t++) {
            cur_max_cnt = max(cur_max_cnt, counts[t]);
        }

        if(cur_max_cnt == 0) continue;

        int s, e;
        for(int t = 1; t <= 50000; t++) {
            if(cur_max_cnt == counts[t]) {
                s = t;
                while(t <= 50000 && cur_max_cnt == counts[t]) {
                    t++;
                }
                e = t;
                break;
            }
        }

        // 1
        if(cur_max_cnt > best.cnt) best = {place, cur_max_cnt, s, e};
    }

    cout << best.p << " " << best.st << " " << best.ed << '\n';
    return 0;
}
/*
같은 이름 학생 -> 첫번째 제출만 인정 => set<string>
장소(10가지)
시간대 st, ed(50000)

우선순위
1.제출횟수cnt
2.가장앞에오는시간대
3.가장빠른
4.가장 긴시간

장소별로 시간대 카운트(1) => 장소별로 maxCnt시작부터 maxCnt끝까지의 구간 => 그 구간 중 우선순위대로
int cnt[11][50004]
*/