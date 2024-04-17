/*
    https://www.acmicpc.net/problem/16505
    (star)

    similar problem
        https://www.acmicpc.net/problem/2447
        (star printing - 10)
        https://www.acmicpc.net/problem/2448
        (star printing - 11)

    solution
        recursive solution
            https://www.acmicpc.net/source/11250496
            (zych1751, 8 ms) : implemented in solve_recursive_2_triangle()

            implemented in solve_recursive_1_triangle()
                https://www.acmicpc.net/source/24608508
                (keunbum, 4 ms)
                https://www.acmicpc.net/source/18866764
                (goooora,4 ms)

        iterative solution
            https://www.acmicpc.net/source/10818229
            (portableangel, 4 ms) : implemented in solve_iterative_3()

            https://www.acmicpc.net/source/20006920
            (fromis_9, 8 ms) : implemented in solve_iterative_1_triangle()

            implemented in solve_iterative_2_triangle()
                https://www.acmicpc.net/source/10814954
                (dotorya, 8 ms)
                https://www.acmicpc.net/source/10841939
                (irikong, 8 ms)

        bitwise solution
            https://www.acmicpc.net/source/10870867
            (koosaga, 8 ms) : implemented in solve_bitwise_1()
            https://www.acmicpc.net/source/10859193
            (functionx, 8 ms) : implemented in solve_bitwise_2()

        DP solution
            https://www.acmicpc.net/source/57912971
            (tlsdydaud1, 88 ms) : implemented in solve_dp()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    no empty space on the end of line (eol)
*/

const int MAX_NUM = 10;
const char STAR = '*';
const char EMPTY = ' ';

int N;
bool ans[(1 << MAX_NUM) + 1][(1 << MAX_NUM) + 1];
// int next_size;  // NOTE : NOT use recursion variable as a global variable
void solve_recursive_1_triangle(int size, int start_row, int start_col){
    if(size <= 1){
        ans[start_row][start_col] = true;
        return;
    }

    int next_size = size >> 1;
    solve_recursive_1_triangle(next_size, start_row, start_col);
    solve_recursive_1_triangle(next_size, start_row, start_col + next_size);
    solve_recursive_1_triangle(next_size, start_row + next_size, start_col);
}

void solve_recursive_2_triangle(int nth, int start_row, int start_col){
    if(nth <= 0){
        ans[start_row][start_col] = true;
        return;
    }

    int next_pos = 1 << (nth - 1);
    solve_recursive_2_triangle(nth - 1, start_row, start_col);
    solve_recursive_2_triangle(nth - 1, start_row, start_col + next_pos);
    solve_recursive_2_triangle(nth - 1, start_row + next_pos, start_col);
}

void solve_iterative_1_triangle(){
    // initial case
    ans[1][1] = true;
    int size;
    for(int ith=1; ith<=N; ++ith){
        size = 1 << (ith - 1);

        // (generate / copy to) bottom triangle
        for(int row=size+1; row<=size<<1; ++row){
            for(int col=1; col<=size-(row-size)+1; ++col){
                ans[row][col] = ans[row-size][col];
            }
        }

        // (generate / copy to) right triangle
        for(int row=1; row<=size; ++row){
            for(int col=size+1; col<=(size<<1) - row + 1; ++col){
                ans[row][col] = ans[row][col-size];
            }
        }
    }
}

void solve_iterative_2_triangle(){
    ans[1][1] = true;
    int size;
    for(int ith=1; ith<=N; ++ith){
        size = 1 << (ith - 1);

        for(int row=1; row<=size; ++row){
            for(int col=1; col<=size-row+1; ++col){
                // bottom triangle
                ans[row+size][col] = ans[row][col];

                // right triangle
                ans[row][col+size] = ans[row][col];
            }
        }
    }
}

void solve_iterative_3(){
    ans[0][0] = true;
    int size;
    for(int ith=1; ith<=N; ++ith){
        size = 1 << (ith - 1);
        for(int row=size; row<(size<<1); ++row){
            for(int col=0; col<=row; ++col){
                ans[row][col] = ans[row - size][col % size];
            }
        }
    }
}

void solve_bitwise_1(){
    for(int row=0; row<(1<<N); ++row){
        for(int col=0; col<(1<<N)-row; ++col){
            ans[row+1][col+1] = !(row & col);
            // cout << (row & col);
        }
        // cout << endl;
    }
}

void solve_bitwise_2(){
    for(int col_size=(1<<N)-1, row=1; col_size>=0; --col_size, ++row){
        for(int col=0; col<=col_size; ++col){
            ans[row][col+1] = !((col_size - col) & col);
            // cout << ((col_size - col) & col);
        }
        // cout << endl;
    }
}

void solve_dp(){
    int size = 1 << N;

    // base case
    for(int idx=1; idx<=size; ++idx){
        ans[idx][1] = true;
        ans[1][idx] = true;
    }

    // recurrence relation
    for(int row=2; row<=size; ++row){
        for(int col=2; col+row<=size+1; ++col){
            ans[row][col] = (ans[row-1][col] != ans[row][col-1]);
        }
    }
}

void print_star_1(){
    int size = 1 << N;

    for(int row=1; row<=size; ++row){
        // for(int col=1; col<=size-row+1; ++col){
        for(int col=1; col+row<=size+1; ++col){
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

void print_star_2(){
    int size = 1 << N;

    for(int row=size-1; row>=0; --row){
        for(int col=0; col<=row; ++col){
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
    // solve_recursive_1_triangle(1 << N, 1, 1);
    // solve_recursive_2_triangle(N, 1, 1);


    // solve_iterative_1_triangle();
    // solve_iterative_2_triangle();


    // solve_bitwise_1();
    // solve_bitwise_2();


    solve_dp();

    print_star_1();

    ////////////////////////////////////////////////

    // solve_iterative_3();

    // print_star_2();
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
