/*
    https://www.acmicpc.net/problem/15483
    (edit distance)

    similar problem
        https://www.acmicpc.net/problem/2216
        (string and score)

        https://www.acmicpc.net/problem/7620
        (edit distance)

    solution
        https://www.acmicpc.net/source/8846180
        (klimmek55, 4 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_LENGTH = 1'000;   // 10^3

string str_A, str_B;
int len_A, len_B;
int dp_1[MAX_LENGTH << 1][MAX_LENGTH << 1];   // dp_1[a][b] : distance between (str_A[a:], str_B[b:])

void solve_dp_1(){
    // base case : empth string
    // dp_1[len_A][len_B] = 0;
    for(int ith=len_A; ith>=0; --ith){
        dp_1[ith][len_B] = len_A - ith;
    }
    for(int jth=len_B; jth>=0; --jth){
        dp_1[len_A][jth] = len_B - jth;
    }

    // bottom-up dp
    for(int ith=len_A-1; ith>=0; --ith){
        for(int jth=len_B-1; jth>=0; --jth){
            if(str_A[ith] == str_B[jth]){
                dp_1[ith][jth] = dp_1[ith + 1][jth + 1];
            }
            else{
                dp_1[ith][jth] = 1 + min({
                    dp_1[ith + 1][jth + 1],     // replace
                    1 + dp_1[ith][jth + 1],     // insert
                    1 + dp_1[ith + 1][jth],     // delete
                });
            }
        }
    }

    cout << dp_1[0][0] << endl;
}

int dfs(int idx, int jdx){
    if(len_A <= idx){
        return dp_1[idx][jdx] = len_B - jdx;
    }
    if(len_B <= jdx){
        return dp_1[idx][jdx] = len_A - idx;
    }
    if(dp_1[idx][jdx]){
        return dp_1[idx][jdx];
    }

    int val;
    if(str_A[idx] == str_B[jdx]){
        val = dfs(idx + 1, jdx + 1);
    }
    else{
        val = 1 + min({
            dfs(idx + 1, jdx + 1),
            dfs(idx, jdx + 1),
            dfs(idx + 1, jdx),
        });
    }

    return dp_1[idx][jdx] = val;
}

void solve_dp_2(){
    cout << dfs(0, 0) << endl;
}

void solve(){
    len_A = str_A.size();
    len_B = str_B.size();

    // solve_dp_1();    // 8 ms
    solve_dp_2();       // 24 ms
}

void input(){
    cin >> str_A >> str_B;
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
