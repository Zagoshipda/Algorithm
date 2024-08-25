/*
    https://www.acmicpc.net/problem/12981
    (ball boxing 1)

    similar problem
        https://www.acmicpc.net/problem/12982
        (ball boxing 2)

    solution
        https://www.acmicpc.net/source/3429829
        (choiking10, 0 ms) : implemented in solve_simulation()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - # balls in one box : 1 or 2 or 3
        - color : all different or all the same

    Algorithm
        closed form solution ?
        brute force or DP ?

        closed form solution
            take remainders 0 or 1 or 2 (mod 3)

            while not 0 0 0:
                try 1 1 1
                ...

            78 53 64
            26...0 17...2 21...1
            64, 0 2 1

            all cases for remainder combinations
                total : 3 * 3 * 3 = 27 cases
                1 more step
                    excluding 2 cases, 2 * 2 * 2 = 8 : 1
                    (2 0 0) 3 : 1

                2 more steps
                    (2 1 0) 6 : 2
                    (2 1 1) 3 : 2
                    (2 2 0) 3 : 2
                    (2 2 1) 3 : 2
                    (2 2 2) 1 : 2

        DP : just dp is fine enough
            S ubproblem
                think as 3-dim dp, with (prefix / suffix)
                dp[x][y][z] : min # box fo x R, y G, z B
            R ecurrence relation
                ball choice for current box
                # ball : combination
                3 : (1, 1, 1), (3, 0, 0), (0, 3, 0), (0, 0, 3)
                2 : (1, 1, 0), (1, 0, 1), (0, 1, 1), (2, 0, 0), (0, 2, 0), (0, 0, 2)
                1 : (1, 0, 0), (0, 1, 0), (0, 0, 1)

                dp[x][y][z] = min(
                    dp[x][y][z],
                    min(
                        dp[x-3][y][z],
                        dp[x][y-3][z],
                        dp[x][y][z-3],
                        ...
                    ) + 1,
                )

            T opological order
                for x=0...R
                    for y=0...G
                        for z=0...B
            B ase case
                dp[0][0][0] = 0
            O riginal problem
                dp[R][G][B]
            T ime complexity
                # subproblems : O(RGB) ~ O(10^6)
                operations per subproblem : ~ O(10)
                total : O(10^7)
                2's time limit ~ O(10^8)
*/

const int MAX_BALL = 100;   // 10^2
const int BOX_SIZE = 3;
const int INF = MAX_BALL << 5;

int R, G, B;

int dp[MAX_BALL + 1][MAX_BALL + 1][MAX_BALL + 1];
void initialize(){
    for(int red=0; red<=R; ++red){
        for(int green=0; green<=G; ++green){
            for(int blue=0; blue<=B; ++blue){
                dp[red][green][blue] = INF;
            }
        }
    }

    dp[0][0][0] = 0;
}
void solve_dp(){
    initialize();

    for(int red=0; red<=R; ++red){
        for(int green=0; green<=G; ++green){
            for(int blue=0; blue<=B; ++blue){
                dp[red][green][blue] = min({
                    dp[red][green][blue],
                    min({
                        red >= 1 && green >= 1 && blue >= 1 ? dp[red - 1][green - 1][blue - 1] : INF,
                        red >= 3 ? dp[red - 3][green][blue] : INF,
                        green >= 3 ? dp[red][green - 3][blue] : INF,
                        blue >= 3 ? dp[red][green][blue - 3] : INF,
                        red >= 1 && green >= 1 ? dp[red - 1][green - 1][blue] : INF,
                        red >= 1 && blue >= 1 ? dp[red - 1][green][blue - 1] : INF,
                        green >= 1 && blue >= 1 ? dp[red][green - 1][blue - 1] : INF,
                        red >= 2 ? dp[red - 2][green][blue] : INF,
                        green >= 2 ? dp[red][green - 2][blue] : INF,
                        blue >= 2 ? dp[red][green][blue - 2] : INF,
                        red >= 1 ? dp[red - 1][green][blue] : INF,
                        green >= 1 ? dp[red][green - 1][blue] : INF,
                        blue >= 1 ? dp[red][green][blue - 1] : INF,
                    }) + 1,
                });
            }
        }
    }

    cout << dp[R][G][B] << endl;
}

void solve_simulation(){
    int cnt = 0;

    // step 1
    // while(R >= BOX_SIZE){
    //     ++cnt;
    //     R -= BOX_SIZE;
    // }
    // while(G >= BOX_SIZE){
    //     ++cnt;
    //     G -= BOX_SIZE;
    // }
    // while(B >= BOX_SIZE){
    //     ++cnt;
    //     B -= BOX_SIZE;
    // }

    cnt += R / BOX_SIZE + G / BOX_SIZE + B / BOX_SIZE;
    R %= BOX_SIZE;
    G %= BOX_SIZE;
    B %= BOX_SIZE;

    // step 2
    while(R >= 1 && G >= 1 && B >= 1){
        ++cnt;
        --R;
        --G;
        --B;
    }

    while(R >= 1 && G >= 1){
        ++cnt;
        --R;
        --G;
    }
    while(R >= 1 && B >= 1){
        ++cnt;
        --R;
        --B;
    }
    while(G >= 1 && B >= 1){
        ++cnt;
        --G;
        --B;
    }

    // step 3
    // WRONG
    // while(R){
    //     ++cnt;
    //     --R;
    // }
    // while(G){
    //     ++cnt;
    //     --G;
    // }
    // while(B){
    //     ++cnt;
    //     --B;
    // }

    // AC
    cnt += R ? 1 : 0 + G ? 1 : 0 + B ? 1 : 0;

    cout << cnt << endl;
}

void solve(){
    // solve_dp();

    solve_simulation();
}

void input(){
    cin >> R >> G >> B;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
