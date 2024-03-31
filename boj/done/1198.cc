/*
    https://www.acmicpc.net/problem/1198
    (largest triangle in polygon)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Time complexity
        N ~ 10^2
        NC3 = 10^6
        => brute force

        area of triangle with 3 points
        = 1/2 * abs(x1 y2 + x2 y3 + x3 y1 - x2 y1 - x3 y2 - x1 y3)

    Range check
        area ~ 10^8 => range fits int

    Q. closed-form solution ?
*/

const int MIN_NUM = 3;
const int MAX_NUM = 35;
const int MAX_POS = 10'000; // 10^4
const int MAX_PRECISION = 9;

int N;
int x, y;
pair<double, double> points[MAX_NUM + 1];
double max_area;

void solve(){
    double area;
    for(int first=1; first<=N; ++first){
        for(int second=first+1; second<=N; ++second){
            for(int third=second+1; third<=N; ++third){
                auto [x_1, y_1] = points[first];
                auto [x_2, y_2] = points[second];
                auto [x_3, y_3] = points[third];
                area = abs(x_1*y_2 + x_2*y_3 + x_3*y_1 - x_2*y_1 - x_3*y_2 - x_1*y_3) / 2;

                max_area = max(max_area , area);
            }
        }
    }

    cout << setprecision(MAX_PRECISION << 1) << max_area << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> x >> y;
        points[i] = {x, y};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
