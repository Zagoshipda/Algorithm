/*
    https://www.acmicpc.net/problem/1334
    (next palindrome number)

    similar problem
        https://www.acmicpc.net/problem/4096
        (palindrometer)

        https://www.acmicpc.net/problem/22301
        (palindrome numbers)

    solutions
        https://www.acmicpc.net/source/70387
        (Apple_Cplus) : manipulate only left half, implemented in solve_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    12(0)12
    12(0)21

    2352348290
    2352(34)8290
    2352(44)2532 (O)
    2352(33)2532 (X)

    12(31)21
    12(33)21

    990
    999 (O)
    1001 (X)

    if left = right (palindrome), add to the center
    if left < right, add to the center
    if left > right, right = left
*/

string N_str;
string N_str_2;
string N_str_3;
string N_str_4;

void solve_1(){
    int len = N_str.size();

    int center_left, center_right;
    if(len & 1){
        center_right = len >> 1;
        center_left = center_right;
    }
    else{
        center_right = len >> 1;
        center_left = center_right - 1;
    }

    int carry = -1;
    for(int left=center_left, right=center_right; 0<=left && right<len; --left, ++right){
        if(N_str[left] > N_str[right]){
            carry = 0;
            break;
        }
        else if(N_str[left] < N_str[right]){
            carry = 1;
            break;
        }
    }
    if(carry < 0){
        carry = 1;
    }

    for(int left=center_left, right=center_right; 0<=left && right<len; --left, ++right){
        if(carry){
            N_str[left] += 1;
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

    if(N_str[0] == '0'){
        // cout << 1 << N_str.substr(0, len-1) << 1 << endl;
        cout << 1 << string(len-1, '0') << 1 << endl;
    }
    else{
        cout << N_str << endl;
    }
}

void solve_2(){
    int len = N_str_2.size();

    int center_left, center_right;
    if(len & 1){
        center_right = len >> 1;
        center_left = center_right;
    }
    else{
        center_right = len >> 1;
        center_left = center_right - 1;
    }

    int carry = 1;
    for(int left=center_left, right=center_right; 0<=left && right<len; --left, ++right){
        if(N_str_2[left] > N_str_2[right]){
            carry = 0;
            break;
        }
        else if(N_str_2[left] < N_str_2[right]){
            break;
        }
    }

    for(int left=center_left, right=center_right; 0<=left && right<len; --left, ++right){
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
        N_str_2[right] = N_str_2[left];
    }

    if(N_str_2[0] == '0'){
        cout << 1 << N_str_2.substr(0, len-1) << 1 << endl;
    }
    else{
        cout << N_str_2 << endl;
    }
}

void solve_3(){
    int len = N_str_3.size();
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
            N_str_2[left] = N_str_3[left];
            N_str_2[right] = N_str_3[left];
        }
        // NOTE : only difference to problem 22301
        if(N_str_2 > N_str_4){
            break;
        }

        int carry = 1;
        for(int left=center_left; 0<=left; --left){
            if(carry){
                N_str_3[left] += carry;
                if(N_str_3[left] > '9'){
                    N_str_3[left] = '0';
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
        if(carry){
            N_str_2 = "1" + string(len-1, '0') + "1";
            break;
        }
    }

    cout << N_str_2 << endl;
}

void solve(){
    N_str_2 = N_str;
    N_str_3 = N_str;
    N_str_4 = N_str;

    // solve_1();
    // solve_2();
    solve_3();
}

void input(){
    cin >> N_str;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
