/*
    https://www.acmicpc.net/problem/2562
    (maximum)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM = 9;
pair<int, int> numbers[NUM + 1];
int number;

void solve_sort(){
    sort(numbers+1, numbers+1 + NUM);
    cout << numbers[NUM].first << endl;
    cout << numbers[NUM].second << endl;
}

void solve(){
    solve_sort();
}

int max_num, max_index;
void input(){
    for(int idx=1; idx<=NUM; ++idx){
        cin >> number;
        // numbers[idx] = {number, idx};

        if(number > max_num){
            max_num = number;
            max_index = idx;
        }
    }
    cout << max_num << endl;
    cout << max_index << endl;
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
