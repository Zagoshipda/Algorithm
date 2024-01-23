/*
    https://www.acmicpc.net/problem/6591
    (binomial showdown)

    similar problems
        https://www.acmicpc.net/problem/2407
        (combination)
        https://www.acmicpc.net/problem/11050
        (binomial coefficient 1...6)
        https://www.acmicpc.net/problem/13239
        (combinations)

    solutions
        https://www.acmicpc.net/source/6979130
        (fromis_9, 0 ms) implemented in solve_2()

        https://www.acmicpc.net/source/6306349
        (YunGoon, 0 ms) recursive solution

    short codes
        https://www.acmicpc.net/source/6694061
        (sait2000, 0 ms) implemented in solve_3()

        https://www.acmicpc.net/source/25044220
        (cgiosy, 0 ms) implemented in solve_4()

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 100;
int n, k;
vector<int> comb[MAX_NUM+1][MAX_NUM+1];
void solve_error(){
    for(int row=0; row<=MAX_NUM; ++row){
        for(int col=0; col<=row; ++col){
            if(col==0 || col==row){
                comb[row][col].push_back(1);
            }
            else{
                int sum, carry = 0;
                vector<int> num_1 = comb[row-1][col-1];
                vector<int> num_2 = comb[row-1][col];
                while(carry || !num_1.empty() || !num_2.empty()){
                    int val_1 = 0, val_2 = 0;
                    if(!num_1.empty()){
                        val_1 = num_1.back();
                        num_1.pop_back();
                    }
                    if(!num_2.empty()){
                        val_2 = num_2.back();
                        num_2.pop_back();
                    }
                    sum = carry + val_1 + val_2;
                    if(sum > 9){
                        sum -= 10;
                        carry = 1;
                    }
                    else{
                        carry = 0;
                    }
                    comb[row][col].push_back(sum);
                }
                reverse(comb[row][col].begin(), comb[row][col].end());
            }
        }
    }

    for(int num : comb[n][k]){
        cout << num;
    }
    cout << endl;
}

void solve_2(){
    ll ans = 1;
    // NOTE : without conversion, time exceeded
    if(k > n/2){    // k > n-k
        k = n-k;
    }
    for(int up=n, down=1; up>n-k; --up, ++down){
        ans *= up;
        ans /= down;
    }
    cout << ans << endl;
}

void solve_3(){
    long d;
    int i;
    for(k=k<n-k?k:n-k,d=i=1; i<=k; d/=i++){
        d*=n--;
    }
    cout << d << endl;
}

void solve_4(){
    long x=1;
    int i;
    for(i=0; i<k&k<n;){
    // for(i=0; i<k;){  // time exceeded
        x=x*n--/++i;
    }
    cout << x << endl;
}

void solve(){
    // solve_error();

    // solve_2();

    // solve_3();

    solve_4();
}

void input(){
    // solve();

    while(cin >> n >> k){
        if(n == 0 && k == 0){
            break;
        }

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
