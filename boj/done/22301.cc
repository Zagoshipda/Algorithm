/*
    https://www.acmicpc.net/problem/22301
    (palindrome numbers)

    similar problem
        https://www.acmicpc.net/problem/1334
        (next palindrome number) : implemented in solve_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - A word is considered a palindrome if it is the same when read left to right or right to left
        - leading zeroes are insignificant and do not appear in any number

        Q. determine the smallest palindrome by value that is greater than or equal to that number


    2 4 6 8 X 8 7 5 2

    123(9)567
    124(0)421

    12(99)45
    13(00)31

    12(0)12
    12(0)21
*/

const int MAX_DIGIT = 80;
int T;
string N_str;
string N_str_2;
string N_str_3;
string N_str_4;

void solve_1(){
    int len = N_str.size();
    int center_1, center_2;
    if(len & 1){
        center_1 = len >> 1;
        center_2 = center_1;
    }
    else{
        center_2 = len >> 1;
        center_1 = center_2 - 1;
    }

    int carry = 0;
    for(int left=center_1, right=center_2; 0<=left && right<len; --left, ++right){
        if(N_str[left] < N_str[right]){
            carry = 1;
            break;
        }
        else if(N_str[left] > N_str[right]){
            break;
        }
    }

    for(int left=center_1, right=center_2; 0<=left && right<len; --left, ++right){
        if(carry){
            N_str[left] += carry;
            if(N_str[left] > '9'){
                N_str[left] = '0';
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        N_str[right] = N_str[left];
    }

    cout << N_str << endl;
}

void solve_2(){
    int len = N_str_4.size();
    int center_right = len >> 1;
    int center_left;
    if(len & 1){
        center_left = center_right;
    }
    else{
        center_left = center_right - 1;
    }

    while(true){
        for(int left=center_left, right=center_right; 0<=left && right<len; --left, ++right){
            N_str_3[left] = N_str_2[left];
            N_str_3[right] = N_str_2[left];
        }
        // NOTE : only difference to problem 1334
        if(N_str_3 >= N_str_4){
            break;
        }

        int carry = 1;
        for(int left=center_left; 0<=left; --left){
            if(carry){
                N_str_2[left] += carry;
                if(N_str_2[left] > '9'){
                    N_str_2[left] = '0';
                    carry = 1;
                }
                else{
                    carry = 0;
                }
            }
            else{
                break;
            }
        }
        // not happen actually
        if(carry){
            N_str_3 = "1" + string(len-1, '0') + "1";
            break;
        }
    }

    cout << N_str_3 << endl;
}

void solve(){
    N_str_2 = N_str;
    N_str_3 = N_str;
    N_str_4 = N_str;

    // solve_1();
    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N_str;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
