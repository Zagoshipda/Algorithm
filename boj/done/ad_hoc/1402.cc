/*
    https://www.acmicpc.net/problem/1402
    (A class problem)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        range ~ 2^31 (int)
        A = a1 * a2 * ... * an
        B = a1 + a2 + ... + an

        if A <= B
            always possible by using 1's
        else
            prime factorization + brute force ?
            9 = 3 * 3
            6 = 3 + 3

        (observation) take the x, y s.t. x * y = A, x+y min

        8 = 2 * 4
        6 = 2 + 4
*/

int T;
int A, B;

void solve_wrong(){
    if(A == 0){
        cout << "yes" << endl;
        return;
    }

    for(int div=sqrt(A); div>=1; --div){
        if(A % div == 0){
            if(min(A, div + A / div) <= B){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
            return;
        }
    }
}

void solve(){
    cout << "yes" << endl;
}

void input(){
    cin >> T;
    while(T--){
        cin >> A >> B;
        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
