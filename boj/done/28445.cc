/*
    https://www.acmicpc.net/problem/28445
    (colorful parrot)

    solutions
        https://www.acmicpc.net/source/65015252
        (kcm1700, 0 ms) : entire answer as a set
        https://www.acmicpc.net/source/65011539
        (edenooo, 0 ms) : insert pair(a, b) into a set
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        4ㅠ2 = 4 * 4 ?

        => considering "duplicates", kㅠ2 = k * k
*/

const int NUM_PARTS = 2;
const int NUM_ANS = (NUM_PARTS << 1);
// string parrot_1[NUM_PARTS + 1];
// string parrot_2[NUM_PARTS + 1];
string color;
// string parrot_3[NUM_ANS + 1];
set<string> parrot_3;

vector<string> choices;
void backtracking(int nth){
    if(nth >= NUM_PARTS){
        for(string choice : choices){
            cout << choice << " ";
        }
        cout << endl;
        return;
    }

    for(auto it=parrot_3.begin(); it!=parrot_3.end(); ++it){
        choices.push_back(*it);
        backtracking(nth+1);
        choices.pop_back();
    }
}

void solve_backtracking(){
    backtracking(0);
}

void solve_iterative(){
    for(auto it=parrot_3.begin(); it!=parrot_3.end(); ++it){
        for(auto jt=parrot_3.begin(); jt!=parrot_3.end(); ++jt){
            cout << *it << " " << *jt << endl;
        }
    }
}

void solve(){
    // solve_backtracking();

    solve_iterative();
}

void input(){
    // cin >> parrot_1[1] >> parrot_1[2];
    // cin >> parrot_2[1] >> parrot_2[2];
    for(int i=1; i<=NUM_ANS; ++i){
        cin >> color;
        parrot_3.insert(color);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
