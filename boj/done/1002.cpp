/*
    https://www.acmicpc.net/problem/1002
    (turret)

    solutions
        https://www.acmicpc.net/source/12646851
        (althea, 0 ms)
        https://www.acmicpc.net/source/5991788
        (donghoon0709, 0 ms)

    similar problem
        https://www.acmicpc.net/problem/2527
        (rectangle)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    NOTE : compare 3 values : max_r - min_r, dist, max_r + min_r
*/

const int MIN_POS = -10'000;
const int MAX_POS = 10'000;
const int MIN_RADIUS = 1;
const int MAX_RADIUS = 10'000;

int T;
int x_1, y_1, r_1, x_2, y_2, r_2;

void solve_1(){
    if(x_1 == x_2 && y_1 == y_2){
        if(r_1 == r_2){
            cout << -1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        double dist = hypot(x_1 - x_2, y_1 - y_2);
        if(r_1 + r_2 < dist){
            cout << 0 << endl;
        }
        else if(r_1 + r_2 == dist){
            cout << 1 << endl;
        }
        else if(dist < r_1 + r_2){
            int max_r = max(r_1, r_2);
            int min_r = min(r_1, r_2);
            // if(dist == abs(r_1 - r_2)){
            if(dist == max_r - min_r){
                cout << 1 << endl;
            }
            else if(dist < max_r - min_r){
                cout << 0 << endl;
            }
            else if(max_r - min_r < dist){
                cout << 2 << endl;
            }
            else{
                // error
            }
        }
        else{
            // error
        }
    }
}

void solve_2(){
    double dist = hypot(x_1 - x_2, y_1 - y_2);
    int max_r = max(r_1, r_2);
    int min_r = min(r_1, r_2);

    if(dist == 0 && r_1 == r_2){
        cout << -1 << endl;
    }
    else if(dist == max_r - min_r || dist == max_r + min_r){
        cout << 1 << endl;
    }
    else if(max_r - min_r < dist && dist < max_r + min_r){
        cout << 2 << endl;
    }
    else{
        cout << 0 << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> x_1 >> y_1 >> r_1 >> x_2 >> y_2 >> r_2;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
