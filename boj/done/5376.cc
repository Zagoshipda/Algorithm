/*
    https://www.acmicpc.net/problem/5376
    (float to fraction)

    similar problem
        https://www.acmicpc.net/problem/9734
        (repeating decimals)
        https://www.acmicpc.net/problem/16513
        (rational ratio)

    solutions
        https://www.acmicpc.net/source/20768526
        (h0ngjun7, 0 ms)
        https://www.acmicpc.net/source/1249952
        (dotorya, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    given a number in decimal notation, returns the fraction
    ﬁrst two characters are 0.
*/

const int MAX_DECIMAL_LENGTH = 6;   // 10^6
const int MAX_REPEAT_LENGTH = 9;    // 10^9
int T;
string number;

void solve_1(){
    int len = number.size();
    ll num = 0;
    bool is_repeat = false;
    int cnt_repeat = 0;
    int cnt_decimal = 0;
    for(int idx=2; idx<len; ++idx){
        char ch = number[idx];
        if(ch == '('){
            is_repeat = true;
        }
        else if(ch == ')'){

        }
        else{
            num *= 10;
            num += (ch - '0');
            ++cnt_decimal;
            if(is_repeat){
                ++cnt_repeat;
            }
        }
    }
    if(num == 0){
        cout << "0/1" << endl;
        return;
    }

    ll numerator, denominator;
    numerator = num;

    if(is_repeat){
        denominator = stoll(string(cnt_repeat, '9') + string(cnt_decimal - cnt_repeat, '0'));

        ll sub = num;
        for(int ith=1; ith<=cnt_repeat; ++ith){
            sub /= 10;
        }
        numerator -= sub;
    }
    else{
        denominator = 1;
        for(int ith=1; ith<=cnt_decimal; ++ith){
            denominator *= 10;
        }
    }

    ll _gcd = gcd(numerator, denominator);
    cout << numerator/_gcd << "/" << denominator/_gcd << endl;
}

void solve_2(){
    int len = number.size();
    ll num_decimal = 0;
    ll power_decimal = 1;
    ll num_repeat = 0;
    ll power_repeat = 1;
    bool is_repeat = false;
    for(int idx=2; idx<len; ++idx){
        char ch = number[idx];
        if(ch == '('){
            is_repeat = true;
        }
        else if(ch == ')'){

        }
        else{
            if(is_repeat){
                num_repeat *= 10;
                num_repeat += (ch - '0');
                power_repeat *= 10;
            }
            else{
                num_decimal *= 10;
                num_decimal += (ch - '0');
                power_decimal *= 10;
            }
        }
    }

    ll numerator;
    ll denominator;
    if(power_decimal == 1){
        numerator = num_repeat;
        denominator = power_decimal * power_repeat - power_decimal;
    }
    else if(power_repeat == 1){
        numerator = num_decimal;
        denominator = power_decimal * power_repeat;
    }
    else{
        numerator = num_decimal * power_repeat + num_repeat - num_decimal;
        denominator = power_decimal * power_repeat - power_decimal;
    }
    ll _gcd = gcd(numerator, denominator);
    cout << numerator/_gcd << "/" << denominator/_gcd << endl;
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> number;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
