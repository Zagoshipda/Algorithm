/*
    https://www.acmicpc.net/problem/1025
    (finding squares)

    solutions
        recursive function call
            https://www.acmicpc.net/source/207932
            (portableangel, 0 ms)
            https://www.acmicpc.net/source/3797443
            (armagedd, 0 ms)

        https://www.acmicpc.net/source/4731931
        (choyi0521, 0 ms) : do...while() implementation

        https://www.acmicpc.net/source/4428416
        (sequence, 0 ms) : boundary trick, iterate on the difference range (-N~N, -M~M)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_ROW = 9;
const int MAX_COL = 9;
const int MIN_NUM = 0;
const int MAX_NUM = 9;

int N, M;
string number;
int numbers[MAX_ROW + 1][MAX_COL + 1];
int max_square = -1;

int get_max_square(int num){
    int val = -1;
    for(int div=0; div*div<=num; ++div){
        if(div * div == num){
            val = max(val, div);
        }
    }
    if(val >= 0){
        // return val * val;
        return num;
    }
    else{
        return val;
    }
}

bool check_range(int row, int col){
    return (1 <= row && row <= N) && (1 <= col && col <= M);
}

void solve_brute_force(){
    // choice for the starting block
    for(int start_row=1; start_row<=N; ++start_row){
        for(int start_col=1; start_col<=M; ++start_col){
            // // NOTE : check for the base case
            // max_square = max(max_square, get_max_square(numbers[start_row][start_col]));

            // choice for the common difference : forward & backward
            for(int diff_row=-(N-1); diff_row<=N-1; ++diff_row){
                for(int diff_col=-(M-1); diff_col<=M-1; ++diff_col){
                    // NOTE : no need to search
                    // if(diff_row == 0 && diff_col == 0){
                    //     continue;
                    // }

                    // finding squares & maximum square
                    int curr_num = 0;
                    for(int row=start_row, col=start_col; check_range(row, col); row+=diff_row, col+=diff_col){
                        curr_num *= 10;
                        curr_num += numbers[row][col];

                        max_square = max(max_square, get_max_square(curr_num));

                        if(diff_row == 0 && diff_col == 0){
                            break;
                        }
                    }

                    // int row = start_row, col = start_col;
                    // do{
                    //     curr_num *= 10;
                    //     curr_num += numbers[row][col];

                    //     max_square = max(max_square, get_max_square(curr_num));

                    //     row += diff_row;
                    //     col += diff_col;
                    // }while((diff_row | diff_col) && check_range(row, col));
                }
            }
        }
    }

    cout << max_square << endl;
}

void solve_brute_force_2(){
    // choice for the starting block
    for(int start_row=1; start_row<=N; ++start_row){
        for(int start_col=1; start_col<=M; ++start_col){
            // // NOTE : check for the base case
            // max_square = max(max_square, get_max_square(numbers[start_row][start_col]));

            // choice for the common difference : forward & backward
            for(int diff_row=-(N); diff_row<=N; ++diff_row){
                for(int diff_col=-(M); diff_col<=M; ++diff_col){
                    // NOTE : no need to search
                    if(diff_row == 0 && diff_col == 0){
                        continue;
                    }

                    // finding squares & maximum square
                    int curr_num = 0;
                    for(int row=start_row, col=start_col; check_range(row, col); row+=diff_row, col+=diff_col){
                        curr_num *= 10;
                        curr_num += numbers[row][col];

                        max_square = max(max_square, get_max_square(curr_num));

                        // if(diff_row == 0 && diff_col == 0){
                        //     break;
                        // }
                    }
                }
            }
        }
    }

    cout << max_square << endl;
}

void solve(){
    // solve_brute_force();

    solve_brute_force_2();

}

void input(){
    cin >> N >> M;
    for(int row=1; row<=N; ++row){
        cin >> number;
        for(int col=1; col<=M; ++col){
            numbers[row][col] = number[col-1] - '0';
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
