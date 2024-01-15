/*
    https://www.acmicpc.net/problem/21921
    (find range of maximum visitors to blog)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    250'000 * 8'000 ~ 2'000'000'000
    => int range possible

*/

const int NUM_DAYS = 250'000;
int N, X;
int visitors[NUM_DAYS + 1];
int prefix_sum[NUM_DAYS + 1];
int max_visitor = 0;
int num_max_visitor = 0;

void print_output(){
    if(max_visitor){
        cout << max_visitor << endl;
        cout << num_max_visitor << endl;
    }
    else{
        cout << "SAD" << endl;
    }
}

void solve_prefix_sum(){
    for(int start=1, end=X; end<=N; ++start, ++end){
        int visitor = prefix_sum[end] - prefix_sum[start-1];
        // max_visitor = max({
        //     max_visitor,
        //     visitor
        // });
        if(max_visitor < visitor){
            num_max_visitor = 1;
            max_visitor = visitor;
        }
        else if(max_visitor == visitor){
            ++num_max_visitor;
        }
    }

    print_output();
}

void solve_sliding_window_with_two_pointers(){
    int visitor = 0;
    for(int idx=1; idx<=X; ++idx){
        visitor += visitors[idx];
    }
    max_visitor = visitor;
    num_max_visitor = 1;

    for(int pos=X+1; pos<=N; ++pos){
        visitor = visitor - visitors[pos-X] + visitors[pos];
        if(max_visitor < visitor){
            num_max_visitor = 1;
            max_visitor = visitor;
        }
        else if(max_visitor == visitor){
            ++num_max_visitor;
        }
    }

    print_output();
}

void solve(){
    // solve_prefix_sum();

    solve_sliding_window_with_two_pointers();
}

void input(){
    cin >> N >> X;
    for(int i=1; i<=N; ++i){
        cin >> visitors[i];
        prefix_sum[i] = prefix_sum[i-1] + visitors[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
