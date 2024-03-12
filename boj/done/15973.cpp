/*
    https://www.acmicpc.net/problem/15973
    (two boxes)

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

*/

const int MIN_POS = -1'000'000'000;
const int MAX_POS = 1'000'000'000;

int x_1[3], y_1[3], x_2[3], y_2[3];

void solve(){
    if(x_2[1] < x_1[2] || y_2[1] < y_1[2] || x_1[1] > x_2[2] || y_1[1] > y_2[2]){
        cout << "NULL" << endl;
    }
    else{
        if((x_1[2] == x_2[1] && (y_2[1] == y_1[2] || y_1[1] == y_2[2])) ||
            x_1[1] == x_2[2] && (y_1[1] == y_2[2] || y_2[1] == y_1[2])){
            cout << "POINT" << endl;
        }
        else if(y_1[1] == y_2[2] || y_2[1] == y_1[2] || x_1[1] == x_2[2] || x_2[1] == x_1[2]){
            cout << "LINE" << endl;
        }
        else{
            cout << "FACE" << endl;
        }
    }
}

void input(){
    cin >> x_1[1] >> y_1[1] >> x_2[1] >> y_2[1];
    cin >> x_1[2] >> y_1[2] >> x_2[2] >> y_2[2];
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
