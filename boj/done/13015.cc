/*
    https://www.acmicpc.net/problem/13015
    (star printing - 23)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_HEIGHT = 1'000;   // 10^3
const int MAX_WIDTH = 1'000;    // 10^3
const char STAR = '*';
const char EMPTY = ' ';

int N;
int height, width;
bool ans[MAX_HEIGHT + 1][MAX_WIDTH + 1];

int middle;
void print_star(){
    for(int row=1; row<=middle; ++row){
        for(int col=1; col+row<=width+1; ++col){
            if(ans[row][col]){
                cout << STAR;
            }
            else{
                cout << EMPTY;
            }
        }
        cout << endl;
    }
    for(int row=middle+1, padding=N; row<=height; ++row, --padding){
        for(int col=1; col+padding<=width+1; ++col){
            if(ans[row][col]){
                cout << STAR;
            }
            else{
                cout << EMPTY;
            }
        }
        cout << endl;
    }
}

void solve(){
    height = (N << 1) - 1;
    width = (N << 2) - 3;

    middle = height >> 1;
    for(int col=1; col<=N; ++col){
        ans[1][col] = true;
        ans[height][col] = true;
    }
    for(int col=width-N+1; col<=width; ++col){
        ans[1][col] = true;
        ans[height][col] = true;
    }

    for(int row=2; row<=middle; ++row){
        ans[row][row] = ans[row][row+N-1] = true;
        ans[height-row+1][row] = ans[height-row+1][row+N-1] = true;

        ans[row][width-row+1] = ans[row][width-row+1-(N-1)] = true;
        ans[height-row+1][width-row+1] = ans[height-row+1][width-row+1-(N-1)] = true;
    }
    ans[middle+1][N] = ans[middle+1][N+(N-1)] = ans[middle+1][N+(N-1)+(N-1)] = true;

    print_star();
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
