/*
    https://www.acmicpc.net/problem/11383
    (image expansion)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_IMAGES = 10;
const string POSSIBLE = "Eyfa";
const string IMPOSSIBLE = "Not Eyfa";

int N, M;
string image_1[NUM_IMAGES + 1];
string image_2[NUM_IMAGES + 1];

void solve(){
    bool is_expansion = true;
    for(int idx=1; idx<=N; ++idx){
        for(int pos_1=0, pos_2=0; pos_1<M; ++pos_1, pos_2+=2){
            char ch = image_1[idx][pos_1];
            if(!(ch == image_2[idx][pos_2] && ch == image_2[idx][pos_2 + 1])){
                is_expansion = false;
                break;
            }
        }
        if(!is_expansion){
            break;
        }
    }
    if(is_expansion){
        cout << POSSIBLE << endl;
    }
    else{
        cout << IMPOSSIBLE << endl;
    }
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> image_1[i];
    }
    for(int i=1; i<=N; ++i){
        cin >> image_2[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
