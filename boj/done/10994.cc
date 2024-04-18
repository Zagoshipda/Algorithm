/*
    https://www.acmicpc.net/problem/10994
    (star printing - 19)

    solution
        https://www.acmicpc.net/source/4962006
        (andy627, 0 ms) : implemented in solve_iterative_2()

        implemented in solve_iterative_3()
            https://www.acmicpc.net/source/898093
            (dotorya, 0 ms) : from boundary to center
            https://www.acmicpc.net/source/11568523
            (luniro, 0 ms) : from center to boundary

        https://www.acmicpc.net/source/19734994
        (smilu2245, 0 ms) : recursive solution
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    1 + 4 (N - 1) = 4N - 3
*/

const int MAX_NUM = 100;
const int MAX_SIZE = (MAX_NUM << 2) - 3;
const char STAR = '*';
const char EMPTY = ' ';

int N;

bool ans[MAX_SIZE + 1][MAX_SIZE + 1];

void solve_recursive(int size, int start_row, int start_col){
    if(size <= 1){
        ans[start_row][start_col] = true;
        return;
    }

    // perimeter
    for(int col=start_col; col<=start_col+size-1; ++col){
        ans[start_row][col] = true;
        ans[start_row+size-1][col] = true;
    }
    for(int row=start_row; row<=start_row+size-1; ++row){
        ans[row][start_col] = true;
        ans[row][start_col+size-1] = true;
    }

    solve_recursive(size - 4, start_row + 2, start_col + 2);
}

void solve_iterative_1(){
    for(int ith=1, start_row=1, start_col=1, size=(N << 2) - 3; ith<=N; ++ith, start_row+=2, start_col+=2, size-=4){
        for(int row=start_row; row<=start_row+size-1; ++row){
            ans[row][start_col] = true;
            ans[row][start_col+size-1] = true;
        }

        for(int col=start_col; col<=start_col+size-1; ++col){
            ans[start_row][col] = true;
            ans[start_row+size-1][col] = true;
        }
    }
}

void solve_iterative_2(){
    // int center = (size >> 1) + 1;
    int center = (N << 1) - 1;

    for(int ith=1, start_row=1, start_col=1, size=(N << 2) - 3; ith<=N; ++ith, start_row+=2, start_col+=2, size-=4){
        int offset = 2 * (N - ith);
        for(int col=0; col<size; ++col){
            ans[center - offset][start_col + col] = true;
            ans[center + offset][start_col + col] = true;
        }
        for(int row=0; row<size; ++row){
            ans[start_row + row][center - offset] = true;
            ans[start_row + row][center + offset] = true;
        }
    }
}

void solve_iterative_3(){
    for(int top_left=0, bottom_right=4*(N-1); top_left<=bottom_right; top_left+=2, bottom_right-=2){
        int pos_1 = top_left + 1;
        int pos_2 = bottom_right + 1;
        for(int perimeter=pos_1; perimeter<=pos_2; ++perimeter){
            ans[pos_1][perimeter] = true;
            ans[pos_2][perimeter] = true;
            ans[perimeter][pos_1] = true;
            ans[perimeter][pos_2] = true;
        }
    }
}

void print_star(){
    int size = (N << 2) - 3;
    for(int row=1; row<=size; ++row){
        for(int col=1; col<=size; ++col){
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
    // solve_recursive((N << 2) - 3, 1, 1);

    // solve_iterative_1();

    // solve_iterative_2();

    solve_iterative_3();

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
