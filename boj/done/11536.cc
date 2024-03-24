/*
    https://www.acmicpc.net/problem/11536
    (line up)

    solutions
        https://www.acmicpc.net/source/9777270
        (jihoon708, 0 ms) : implemented in solve_permutation()

        https://www.acmicpc.net/source/2889597
        (sys7961, 0 ms) : implemented in solve_brute_force()

        https://www.acmicpc.net/source/2063255
        (codek, 0 ms) : counting # of (increase / decrease)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

string INCREASING = "INCREASING";
string DECREASING = "DECREASING";
string NEITHER = "NEITHER";

const int MAX_NUM = 20;
int N;
string names_1[MAX_NUM + 1];
string names_2[MAX_NUM + 1];

void solve_sort(){
    bool is_increasing = true;
    bool is_decreasing = true;

    sort(names_1+1, names_1+1+N, less<string>());
    for(int idx=1; idx<=N; ++idx){
        if(names_1[idx] != names_2[idx]){
            is_increasing = false;
            break;
        }
    }

    sort(names_1+1, names_1+1+N, greater<string>());
    for(int idx=1; idx<=N; ++idx){
        if(names_1[idx] != names_2[idx]){
            is_decreasing = false;
        }
    }

    if(is_increasing){
        cout << INCREASING << endl;
    }
    else if(is_decreasing){
        cout << DECREASING << endl;
    }
    else{
        cout << NEITHER << endl;
    }
}

void solve_permutation(){
    if(!prev_permutation(names_1+1, names_1+1+N)){
        cout << INCREASING << endl;
    }
    else if(!next_permutation(names_2+1, names_2+1+N)){
        cout << DECREASING << endl;
    }
    else{
        cout << NEITHER << endl;
    }
}

void solve_brute_force(){
    bool is_increasing = true;
    bool is_decreasing = true;
    for(int idx=2; idx<=N; ++idx){
        if(names_1[idx-1] <= names_1[idx]){
            is_decreasing = false;
        }
        else if(names_1[idx-1] >= names_1[idx]){
            is_increasing = false;
        }
    }

    if(is_increasing){
        cout << INCREASING << endl;
    }
    else if(is_decreasing){
        cout << DECREASING << endl;
    }
    else{
        cout << NEITHER << endl;
    }
}

void solve(){
    // solve_sort();

    // solve_permutation();

    solve_brute_force();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> names_1[i];
        names_2[i] = names_1[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
