/*
    https://www.acmicpc.net/problem/1173
    (exercise)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_DIFFERENCE = 1;
const int MAX_DIFFERENCE = 200;
const int MAX_EXERCISE = 200;
const int MIN_PULSE = 50;
const int MAX_PULSE = 200;
const int MAX_TIME = (MAX_PULSE - MIN_PULSE) * MAX_DIFFERENCE * MAX_EXERCISE << 1;
int N, m, M, T, R;

void solve_1(){
    int time = 0;
    for(int pulse=m, exercise=0; exercise<N; ++time){
        if(time > MAX_TIME){
            cout << -1 << endl;
            return;
        }

        if(pulse + T <= M){
            pulse += T;
            exercise += 1;
        }
        else{
            pulse = max(m, pulse - R);
        }
    }

    cout << time << endl;
}

void solve_2(){
    if(m + T > M){
        cout << -1 << endl;
        return;
    }

    int time = 0;
    for(int pulse=m, exercise=0; exercise<N; ++time){
        if(pulse + T <= M){
            pulse += T;
            exercise += 1;
        }
        else{
            pulse = max(m, pulse - R);
        }
    }

    cout << time << endl;
}

void solve(){
    // solve_1();
    solve_2();
}

void input(){
    cin >> N >> m >> M >> T >> R;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
