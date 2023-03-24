#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define MOD 1'000'000'000
int N;
int stair_number[101][10];
int number_of_stair_number;

void calculate_stair_number(){
    // initialize
    for(int end=1; end<=9; ++end){
        stair_number[1][end] = 1;
    }

    // bottom-up
    for(int pos=2; pos<=N; ++pos){
        for(int end=0; end<=9; ++end){
            if(end == 0){
                stair_number[pos][end] = stair_number[pos-1][end+1];
            }
            else if(end == 9){
                stair_number[pos][end] = stair_number[pos-1][end-1];
            }
            else{
                stair_number[pos][end] = stair_number[pos-1][end-1] + stair_number[pos-1][end+1];
            }
            stair_number[pos][end] %= MOD;
        }
    }

    for(int i=0; i<=9; ++i){
        number_of_stair_number += stair_number[N][i];
        number_of_stair_number %= MOD;
    }
}

int main(){
    IOS;

    cin >> N;

    calculate_stair_number();

    cout << number_of_stair_number << endl;

    return 0;
}
