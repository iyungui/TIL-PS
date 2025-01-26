#include <bits/stdc++.h>

using namespace std;

int n;
int min_price = INT_MAX;
int mp,mf,ms,mv;
vector<int> num;
struct Point {
    int a, b, c, d, e;
};

vector<Point> points;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for(int i = 0; i < n; i++) {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        points.push_back({a, b, c, d, e});
    }
    
//    for(int i = 0; i < n; i++) {
//        cout << points[i].a << " " << points[i].b << " " << points[i].c << " " << points[i].d << " " << points[i].e << '\n';
//    }
    
    for(int i = 0; i < (1 << n); i++) {
        vector<Point> temp;
        vector<int> selected;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                temp.push_back(points[j]);
                selected.push_back(j + 1);
            }
        }
        int sumP = 0, sumF = 0, sumS = 0, sumV = 0, sumC = 0;
        for(Point p : temp) {
            sumP += p.a;
            sumF += p.b;
            sumS += p.c;
            sumV += p.d;
            sumC += p.e;
        }
        
        // mp,mf,ms,mv
        if(mp <= sumP && mf <= sumF && ms <= sumS && mv <= sumV) {
            if(min_price > sumC) {
                min_price = sumC;
                num.clear();
                num = selected;
            }
            else if(min_price == sumC) {
                vector<int> temp = num;
                sort(selected.begin(), selected.end());
                sort(temp.begin(), temp.end());
                if(selected < temp) {
                    num = selected;
                }
            }
        }
    }
    
    if(min_price == INT_MAX) {
        cout << -1 << '\n';
        return 0;
    }
    cout << min_price << '\n';
    
    sort(num.begin(), num.end());
    for(int i : num) cout << i << " ";
    return 0;
}
