/*
    https://www.acmicpc.net/problem/16519
    (other side)

    solutions
        https://www.acmicpc.net/source/51371494
        (topology, 0 ms)

        https://www.acmicpc.net/source/32634900
        (xiaowuc1, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - when "left unsupervised", wolves will eat sheep and sheep will eat cabbages
        - wolves don’t eat cabbages
        - transportation will be carried out using a boat that can hold up to K of these items at the same time
        >> consider both on the bank and in the boat <<

        Q. when it is possible to perform the transportation without the loss of items ?

    Algorithm
        consider only the possible cases:

        if S <= K : take all sheeps
        else
            (here, at least one sheep left, so no wolves and cabbages be left)
            if W+C <= K : take all wolves & cabbages

        5 21 5 10
        // NO

        2 2 2 2
        // YES
        2 2 3 2
        // NO
        4 1 4 2
        // YES
*/

int W, S, C, K; // wolf > sheep, sheep > cabbage, load

void solve(){
    if(K >= 1){
        if(S < K || (S == K && (W+C) <= 2*K)){
            cout << "YES" << endl;
        }
        else if(W+C < K || (W+C) == K && S <= 2*K){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    else{
        cout << "NO" << endl;
    }
}

void input(){
    cin >> W >> S >> C >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
