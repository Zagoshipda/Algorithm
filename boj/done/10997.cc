/*
    https://www.acmicpc.net/problem/10997
    (star printing - 22)

    solution
        drawing spiral
            implemented in solve_recursive_2()
                https://www.acmicpc.net/source/4052859
                (goooora, 0 ms) : recursive
                https://www.acmicpc.net/source/72466030
                (kimsd1983, 112 ms) : iterative, erasing star

            https://www.acmicpc.net/source/20216658
            (ruz, 0 ms) : iterative, checking conflict with the front star

            https://www.acmicpc.net/source/10739641
            (evenharder, 0 ms) : spiral from the center to boundary, implemented in solve_recursive_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    height
        1 7 11 15
        3 + 4(N-1) = 4N - 1

    width = 1 + 4(N - 1) = 4N - 3
*/

const int MAX_NUM = 100;
const int MAX_HEIGHT = (MAX_NUM << 2) - 1;
const int MAX_WIDTH = (MAX_NUM << 2) - 3;
const char STAR = '*';
const char EMPTY = ' ';

int N;

bool ans[MAX_HEIGHT + 1][MAX_WIDTH + 1];
void solve_recursive_1(int height, int width, int start_row, int start_col){
    if(width <= 1){
        ans[start_row][start_col] = true;
        ans[start_row + 1][start_col] = true;
        ans[start_row + 2][start_col] = true;
        return;
    }

    // perimeter
    for(int row=start_row; row<=start_row+height-1; ++row){
        ans[row][start_col] = true;
        ans[row][start_col+width-1] = true;
    }
    for(int col=start_col; col<=start_col+width-1; ++col){
        ans[start_row][col] = true;
        ans[start_row+height-1][col] = true;
    }

    // 2 special points
    ans[start_row+1][start_col+width-1] = false;
    ans[start_row+2][start_col+width-2] = true;

    solve_recursive_1(height - 4, width - 4, start_row + 2, start_col + 2);
}

void solve_recursive_2(){

}

void solve_recursive_3(){

}

void print_star(int height, int width){
    for(int row=1; row<=height; ++row){
        // output format
        if(row==2){
            cout << STAR << endl;
            continue;
        }

        for(int col=1; col<=width; ++col){
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
    if(N <= 1){
        cout << STAR << endl;
        return;
    }

    int height = (N << 2) - 1;
    int width = (N << 2) - 3;

    solve_recursive_1(height, width, 1, 1);

    print_star(height, width);
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
