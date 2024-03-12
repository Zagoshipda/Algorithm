/*
    https://www.acmicpc.net/problem/4673
    (self numbers)

    solutions
        https://www.acmicpc.net/source/20019134
        (cektjtro, 0 ms)

        https://www.acmicpc.net/source/21445363
        (kiho5044 , 0 ms) : 1-pass brute force, implemented in solve_brute_force_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Kaprekar : A number with no generators is a self-number, for a positive integer
*/

const int MAX_NUM = 10'000;
bool not_self[MAX_NUM + 1];
int digit_sum(int num){
    int sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void solve_brute_force_1(){
    for(int generator=1; generator<=MAX_NUM; ++generator){
        int num = generator + digit_sum(generator);
        if(num<=MAX_NUM){
            not_self[num] = true;
        }
    }

    for(int num=1; num<=MAX_NUM; ++num){
        if(!not_self[num]){
            cout << num << endl;
        }
    }
}

void solve_brute_force_2(){
    for(int num=1; num<=MAX_NUM; ++num){
        int sum = num + digit_sum(num);
        if(sum <= MAX_NUM){
            not_self[sum] = true;
        }
        if(!not_self[num]){
            cout << num << endl;
        }
    }
}

void solve(){
    // solve_brute_force_1();
    solve_brute_force_2();
}

void input(){

}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
