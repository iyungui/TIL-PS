#include <bits/stdc++.h>
using namespace std;

struct Item {
    double weight, value, ratio;
};

bool cmp(const Item& a, const Item& b) {
    return a.ratio > b.ratio;
}

int n;
double m;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;

    vector<Item> items(n);

    for(int i = 0; i < n; i++) {
        // double 자료형으로 계산하여 벡터에 저장
        cin >> items[i].weight >> items[i].value;
        items[i].ratio = items[i].value / items[i].weight;
    }

    // 가성비가 좋은 보석을 먼저 담도록 정렬
    sort(items.begin(), items.end(), cmp);

    double total_value = 0;
    double cur_weight = 0;

    for(int i = 0; i < n; i++) {
        // i번째 보석을 가방에 온전히 다 넣을 수 있는 경우
        if(cur_weight + items[i].weight <= m) {
            cur_weight += items[i].weight;
            total_value += items[i].value;
        }
        // 가방 공간이 부족하여 쪼개어 넣어야하는 경우
        else {
            double remain_weight = m - cur_weight;  // 가방 남은 공간 계산
            // 남은공간 * 무게당 가치(ratio) = 쪼개어 넣은 보석의 가치
            total_value += remain_weight * items[i].ratio;  
            // 가방이 꽉 찼으므로 탐색 종료
            break;
        }
    }

    // 소수점 셋째 자리까지 출력
    cout << fixed << setprecision(3);
    cout << total_value << '\n';

    return 0;
}