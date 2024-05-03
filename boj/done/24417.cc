/*
    https://www.acmicpc.net/problem/24417
    (fibonacci number 2)

    similar problem
        https://www.acmicpc.net/problem/24416
        (fibonacci number 1)

    solution
        power by n, take matrix[1][2] or matrix[2][1], implemented in solve_5()
            https://www.acmicpc.net/source/60771555
            (qvixnh22, 0 ms)
            https://www.acmicpc.net/source/38154703
            (jinhan814, 0 ms)
            https://www.acmicpc.net/source/38806310
            (thdtjdals3, 0 ms)

        https://www.acmicpc.net/source/38156798
        (pjshwa, 0 ms) : implemented in solve_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        efficient (log n) exponential

        (observation)
            result for power k, initial 1 1
            fk+1 fk | 1 = fk+2
            fk fk-1 | 1 = fk+1

            1 1 2 3 5 8 13 ...
            power=0
                1 0 f1 f0
                0 1 f0 f1
            power=1
                1 1 f2 f1
                1 0 f1 f0
            power=2
                2 1 f3 f2
                1 1 f2 f1
            power=3
                3 2 f4 f3
                2 1 f3 f2

        mat^1 = (1 1 1 0)
        mat^2 = (2 1 1 1)

        mat^1 = mat^1 * I
        mat^2 = mat^2 * I
        mat^3 = mat^2 * mat^1 * I
        ...

        mat^n-2 * mat^1 = mat^n-1
*/

const int MAX_NUM = (100'000'000 << 1); // 2 * 10^8
const int MOD = 1'000'000'007;          // 10^9 + 7

int n;

// int fib[MAX_NUM + 1];
void solve_memory_exceeded(){
    // fib[1] = 1;
    // fib[2] = 1;
    // for(int num=3; num<=n; ++num){
    //     fib[num] = fib[num-1] + fib[num-2];
    //     fib[num] %= MOD;
    // }
    // cout << fib[n] << " " << n - 2 << endl;
}

void solve_iterative(){
    int n_1 = 1;
    int n_2 = 1;
    int n_3;
    for(int num=3; num<=n; ++num){
        n_3 = n_1 + n_2;

        // n_3 %= MOD;         // 688 ms

        if(n_3 >= MOD){     // 272 ms
            n_3 -= MOD;
        }

        n_1 = n_2;
        n_2 = n_3;
    }
    cout << n_3 << " " << n - 2 << endl;
}

const int MATRIX_SIZE = 2;
ll matrix[MATRIX_SIZE + 1][MATRIX_SIZE + 1];
ll mul[MATRIX_SIZE+ 1][MATRIX_SIZE + 1];
ll result[MATRIX_SIZE+ 1][MATRIX_SIZE + 1];

void initialize(){
    // identity matrix
    result[1][1] = 1;
    result[2][2] = 1;

    // fibonacci matrix
    // fib[n+2] = fib[n+1] + fib[n]
    // fib[n+1] = fib[n+1]
    matrix[1][1] = 1;
    matrix[1][2] = 1;
    matrix[2][1] = 1;
}

void matrix_product(ll mat_1[][MATRIX_SIZE + 1], ll mat_2[][MATRIX_SIZE + 1]){
    for(int row=1; row<=MATRIX_SIZE; ++row){
        for(int col=1; col<=MATRIX_SIZE; ++col){
            mul[row][col] = 0;
            for(int kdx=1; kdx<=MATRIX_SIZE; ++kdx){
                mul[row][col] += mat_1[row][kdx] * mat_2[kdx][col];
                mul[row][col] %= MOD;
            }
        }
    }

    for(int row=1; row<=MATRIX_SIZE; ++row){
        for(int col=1; col<=MATRIX_SIZE; ++col){
            mat_1[row][col] = mul[row][col];
        }
    }
}


void solve_2(){
    // calculate matrix power n-2
    for(int power=n-2; power>0; power>>=1){
        if(power & 1){
            matrix_product(result, matrix);
        }
        matrix_product(matrix, matrix);
    }

    cout << (result[1][1] + result[1][2]) % MOD << " " << n-2 << endl;
}

void solve_4(){
    for(int power=n-1; power>0; power>>=1){
        if(power & 1){
            matrix_product(result, matrix);
        }
        matrix_product(matrix, matrix);
    }
    cout << result[1][1] << " " << n - 2 << endl;
}

void solve_5(){
    for(int power=n; power>0; power>>=1){
        if(power & 1){
            matrix_product(result, matrix);
        }
        matrix_product(matrix, matrix);
    }
    // NOTE : symmetric matrix
    // cout << result[2][1] << " " << n-2 << endl;
    cout << result[1][2] << " " << n-2 << endl;
}

// matrix power n-2, recursive
void solve_3(int size){
    if(size & 1){

    }
    else{

    }
}

void solve(){
    // solve_iterative();

    initialize();
    // solve_2();
    // solve_3();
    // solve_4();
    solve_5();
}

void input(){
    cin >> n;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
