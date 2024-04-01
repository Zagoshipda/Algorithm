/*
    https://www.acmicpc.net/problem/2477
    (area by circumference)

    solutions
        https://www.acmicpc.net/source/4135882
        (BaaaaaaaaaaarkingDog, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    r - shaped area

    1 2 3 4 must be shown at least once
    total length should satisfy 1 == 2, 3 == 4
    4 > 2 > 3 > 1
*/

const int NUM_VERTICES = 6;
const int MAX_NUM = 20;
const int MAX_LENGTH = 500; // 5 * 10^2
const int NUM_DIRECTIONS = 4;

enum DIRECTIONS{
    east    = 1,
    west    = 2,
    south   = 3,
    north   = 4,
};

int K;
int a, b;
vector<int> lengths[NUM_DIRECTIONS + 1];

int width, height;
vector<int> circum;
void solve(){
    for(int len : lengths[east]){
        width += len;
    }
    for(int len : lengths[south]){
        height += len;
    }

    int len = circum.size();
    for(int idx=0; idx<len; ++idx){
        int val_1 = circum[idx];
        int val_2;
        if(idx + 1 >= len){
            idx = -1;
        }
        val_2 = circum[idx+1];
        if((val_1 == width && val_2 == height) || (val_1 == height && val_2 == width)){
            cout << K * (width * height - circum[(idx+3) % len] * circum[(idx+4) % len]) << endl;
            break;
        }
    }
}

void input(){
    cin >> K;
    for(int i=1; i<=NUM_VERTICES; ++i){
        cin >> a >> b;
        circum.push_back(b);
        lengths[a].push_back(b);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
