/*
    https://www.acmicpc.net/problem/16503
    (no bracket arithmetic)

    solution
        https://www.acmicpc.net/source/17907383
        (kimyeonwoo0506, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const char ADD = '+';
const char SUB = '-';
const char MUL = '*';
const char DIV = '/';

char operation_1;
char operation_2;

int ans_1;
int ans_2;

int num_1;
int num_2;
int num_3;

void calculate_1(int& val){
    if(operation_1 == ADD){
        val = num_1 + num_2;
    }
    else if(operation_1 == SUB){
        val = num_1 - num_2;
    }
    else if(operation_1 == MUL){
        val = num_1 * num_2;
    }
    else if(operation_1 == DIV){
        val = num_1 / num_2;
    }

    if(operation_2 == ADD){
        val = val + num_3;
    }
    else if(operation_2 == SUB){
        val = val - num_3;
    }
    else if(operation_2 == MUL){
        val = val * num_3;
    }
    else if(operation_2 == DIV){
        val = val / num_3;
    }
}

void calculate_2(int& val){
    if(operation_2 == ADD){
        val = num_2 + num_3;
    }
    else if(operation_2 == SUB){
        val = num_2 - num_3;
    }
    else if(operation_2 == MUL){
        val = num_2 * num_3;
    }
    else if(operation_2 == DIV){
        val = num_2 / num_3;
    }

    if(operation_1 == ADD){
        val = num_1 + val;
    }
    else if(operation_1 == SUB){
        val = num_1 - val;
    }
    else if(operation_1 == MUL){
        val = num_1 * val;
    }
    else if(operation_1 == DIV){
        val = num_1 / val;
    }
}

void solve(){
    calculate_1(ans_1);
    calculate_2(ans_2);

    cout << min(ans_1, ans_2) << endl;
    cout << max(ans_1, ans_2) << endl;
}

void input(){
    cin >> num_1 >> operation_1 >> num_2 >> operation_2 >> num_3;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
