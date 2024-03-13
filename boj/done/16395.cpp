/*
    https://www.acmicpc.net/problem/16395
    (pascal triangle)

    similar problem
        https://www.acmicpc.net/problem/15489
        (pascal triangle)

    solutions
        https://www.acmicpc.net/source/17231642
        (goehd4551, 0 ms) : 1-D dp, implemented in solve_dp_2()

        https://www.acmicpc.net/source/31262594
        (qoalstjr, 0 ms) : recursive solution, implemented in solve_recursive_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    n, k ~ 30
    NOTE : 30! overflow long long

    n-1Ck-1 = (n-1) (n-2) ... / (k-1) (k-2) ... 2 1
*/

const int MAX_ROW = 30;
const int MAX_COL = 30;
int n, k;

int dp[MAX_ROW + 1][MAX_COL + 1];
void solve_dp_1(){
    dp[0][0] = 1;
    for(int row=1; row<=n; ++row){
        for(int col=1; col<=row; ++col){
            dp[row][col] = dp[row-1][col-1] + dp[row-1][col];
        }
    }
    cout << dp[n][k] << endl;
}

/*
    1 0 0 ...
    1 1 0 ...
    1 2 1 0 ...
    1 3 3 1 0 ...
    1 4 6 4 1 0 ...
*/
int dp_2[MAX_ROW + 1];
void solve_dp_2(){
    dp_2[1] = 1;
    for(int row=2; row<=n; ++row){
        // WRONG : previous calculation affects the later
        // for(int col=1; col<=row; ++col){
        //     dp_2[col] += dp_2[col-1];
        // }

        // NOTE : must proceed from the end
        for(int col=row; col>=1; --col){
            dp_2[col] += dp_2[col-1];
        }
    }
    cout << dp_2[k] << endl;
}

int cache[MAX_ROW + 1][MAX_COL + 1];
int solve_recursive_1(int num, int choice){
    if(choice <= 0){
        return 1;
    }
    // if(choice <= 1){
    //     return num;
    // }

    if(cache[num][choice]){
        return cache[num][choice];
    }

    // NOTE : calculation order matters for int division
    return cache[num][choice] = solve_recursive_1(num-1, choice-1) * num / choice;
    // return num / choice * solve_recursive_1(num-1, choice-1); // WRONG
}

int solve_recursive_2(int num, int choice){
    if(choice <= 0){
        return 1;
    }

    // NOTE : calculation order matters for int division
    return solve_recursive_2(num-1, choice-1) * num / choice;
    // return num / choice * solve_recursive_2(num-1, choice-1);   // WRONG
}

void solve_iterative_1(){
    int ans = 1;

    // from small to large
    for(int ith=k-1; ith>=1; --ith){
        // ans *= n-1-(ith-1) / k-1-(ith-1);    // WRONG
        ans *= n-1-(ith-1);
        ans /= k-1-(ith-1);
    }
    cout << ans << endl;
}

void solve_iterative_2(){
    int ans = 1;

    // from small to large
    int numerator = n-1-(k-2);
    int denominator = k-1-(k-2);
    for(int ith=1; ith<=k-1; ++ith){
        // ans *= (numerator / denominator); // WRONG
        ans *= numerator;
        ans /= denominator;
        ++numerator;
        ++denominator;
    }
    cout << ans << endl;
}

void solve(){
    // solve_dp_1();
    // solve_dp_2();

    // cout << solve_recursive_1(n-1, k-1) << endl;
    cout << solve_recursive_2(n-1, k-1) << endl;

    // solve_iterative_1();
    // solve_iterative_2();
}

void input(){
    cin >> n >> k;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
