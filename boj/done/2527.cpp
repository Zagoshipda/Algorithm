/*
    https://www.acmicpc.net/problem/2527
    (rectangle)

    similar problem
        https://www.acmicpc.net/problem/15973
        (two boxes) : bigger range

        https://www.acmicpc.net/problem/1002
        (turret) : circle version

    solutions
        https://www.acmicpc.net/source/70070
        (Apple_Cplus, 0 ms)

        https://www.acmicpc.net/source/11613689
        (eaststar, 0 ms)

        https://www.acmicpc.net/source/337208
        (Nada, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

0 0 3 3 3 3 5 5
0 0 1 1 1 1 2 2
35 56 67 90 67 80 500 600
3 10 50 60 100 100 200 300

// c c b d

0 0 3 3 1 1 3 3
0 0 1 1 1 1 2 2
35 56 67 90 67 80 500 600
3 10 50 60 100 100 200 300

// a c b d

35 56 67 90 67 100 500 600
30 10 50 60 50 80 80 100
30 60 60 90 60 20 90 50
30 60 60 90 50 90 80 120

// d d d b


0 0 3 3 6 3 9 9
3 10 50 60 100 100 200 300
45 50 600 600 400 450 500 543
35 56 67 90 67 80 500 600

// d d a b

*/

const char OVERLAP_RECTANGLE    = 'a';
const char OVERLAP_LINE         = 'b';
const char OVERLAP_POINT        = 'c';
const char OVERLAP_NONE         = 'd';
const int NUM = 2;
const int MIN_POS = 1;
const int MAX_POS = 50'000;

int T = 4;
int x[NUM + 1], y[NUM + 1], p[NUM + 1], q[NUM + 1]; // rectangle (x,y) ~ (p,q) : x < p, y < q

// error: assigning to an array from an initializer list
// cannot assign directly to an array after its declaration
// pair<int, int> rectangles[NUM + 1][5];    // LD LU RU RD : clockwise

vector<pair<int, int> > rectangles[NUM + 1];    // LD LU RU RD : clockwise

void solve(){
    rectangles[1] = { {-1, -1}, {x[1], y[1]}, {x[1], q[1]}, {p[1], q[1]}, {p[1], y[1]} };
    rectangles[2] = { {-1, -1}, {x[2], y[2]}, {x[2], q[2]}, {p[2], q[2]}, {p[2], y[2]} };

    // clockwise order
    if(p[1] < x[2] || y[1] > q[2] || x[1] > p[2] || q[1] < y[2]){
        cout << OVERLAP_NONE << endl;
    }
    else{
        if(rectangles[1][3] == rectangles[2][1] || rectangles[1][4] == rectangles[2][2] ||
            rectangles[1][1] == rectangles[2][3] || rectangles[1][2] == rectangles[2][4]){
            cout << OVERLAP_POINT << endl;
        }

        // else if((p[1] == x[2] && !(q[1] < y[2] || y[1] > q[2])) ||
        //         (y[1] == q[2] && !(p[1] < x[2] || x[1] > p[2])) ||
        //         (x[1] == p[2] && !(y[1] > q[2] || q[1] < y[2])) ||
        //         (q[1] == y[2] && !(p[1] < x[2] || p[2] < x[1])) ){
        //     cout << OVERLAP_LINE << endl;
        // }
        else if(p[1] == x[2] || y[1] == q[2] || x[1] == p[2] || q[1] == y[2]){
            cout << OVERLAP_LINE << endl;
        }
        else{
            cout << OVERLAP_RECTANGLE << endl;
        }
    }
}

void input(){
    while(T--){
        cin >> x[1] >> y[1] >> p[1] >> q[1];
        cin >> x[2] >> y[2] >> p[2] >> q[2];

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
