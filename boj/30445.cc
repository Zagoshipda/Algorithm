/*
    https://www.acmicpc.net/problem/30445
    (happiness score)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

ex.
H SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS

// 3.12 (X)
// 3.13 (O)

*/

string message;
string happy = "HAPPY";
string sad = "SAD";

void solve(){
    double p_h = 0;
    double p_g = 0;
    for(char letter : message){
        if(happy.find(letter) != string::npos){
            ++p_h;
        }
        if(sad.find(letter) != string::npos){
            ++p_g;
        }
    }

    if(p_h == 0 && p_g == 0){
        // cout << 50.00 << endl;  // WRONG
        cout << "50.00" << endl;    // AC
    }
    else{
        // cout << setprecision(2) << fixed << 100 * p_h / (p_h + p_g) << endl;     // WRONG
        cout << setprecision(2) << fixed << round(10000 * p_h / (p_h + p_g)) / 100 << endl;     // AC
    }
}

void input(){
    getline(cin, message);
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
