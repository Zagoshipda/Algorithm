/*
    https://www.acmicpc.net/problem/6131
    (perfect squares)

    similar problem
        https://www.acmicpc.net/problem/1484
        (diet)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1 <= B <= A <= 500
    B^2 + N = A^2
    A^2 - B^2 = N
    (A-B)(A+B) = N

    N=15
    1 15 (8,7)
    3 5  (4,1)

    if A-B = A+B => B=0 (X)
    => find factors of N with 2 different numbers


    squares
        1 4 9 16 25 36 49 64 81 100 ...
*/

const int MIN_DIFFERENCE = 1;
const int MAX_DIFFERENCE = 1'000;
int N;

void solve(){
    int cnt = 0;
    for(int div=1; div*div<N; ++div){
        if(N % div == 0){
            if((div + N/div) % 2 == 0){
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
