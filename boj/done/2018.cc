/*
    https://www.acmicpc.net/problem/2018
    (sum of numbers 5) : herd sums

    similar problem
        https://www.acmicpc.net/problem/2015
        (sum of numbers 4)

    solution
        closed form solutions
            https://www.acmicpc.net/source/7716448
            (fromis_9, 0 ms) : implemented in solve_closed_form()
            https://www.acmicpc.net/source/78523389
            (vmffotltka, 0 ms)
            https://www.acmicpc.net/source/7895717
            (junghun1997, 0 ms) : (N - len(len + 1)/2) % len
        two-pointer
            https://www.acmicpc.net/source/71395422
            (dbgksdl00, 0 ms)

    reference
        two-pointer, implemented in solve_two_pointer()
        https://thought-process-ing.tistory.com/125

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    k=1 : x = N
    k=2 : (x+x+1) = N
    k=3 : (x+x+1+x+2) = N
    k=4 : (x+x+1+x+2+x+3) = N = 4x+1+2+3
    k=5 : N = 5x+1+2+3+4
    ...
    N=kx+1+...+(k-1)=kx+k(k-1)/2 where x > 0

*/

const int MAX_NUM = 10'000'000; // 10^7
ll N;

void solve_closed_form(){
    int cnt = 0;
    for(ll len=1; ; ++len){
        ll target = N;
        ll sum = len*(len-1) >> 1;
        target -= sum;
        if(target <= 0){
            break;
        }
        if(target % len == 0){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void solve_two_pointer(){
    int cnt = 0;
    for(int left=1, right=1, sum=1; right<=N; ){
        if(sum < N){
            ++right;
            sum += right;
        }
        else if(sum > N){
            sum -= left;
            ++left;
        }
        else{
            ++cnt;

            // sum -= left;
            // ++left;

            ++right;
            sum += right;
        }
    }
    cout << cnt << endl;
}

void solve(){
    // solve_closed_form();

    solve_two_pointer();
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
