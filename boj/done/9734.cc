/*
    https://www.acmicpc.net/problem/9734
    (repeating decimals)

    similar problem
        https://www.acmicpc.net/problem/5376
        (float to fraction) < solutions
        https://www.acmicpc.net/problem/16513
        (rational ratio)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_DIGIT = 9;

string number;

void solve(){
    int len = number.size();
    int num = 0;
    int cnt_decimal = 0;
    int cnt_repeat = 0;
    bool is_decimal = false;
    bool is_repeat = false;
    for(int idx=0; idx<len; ++idx){
        char ch = number[idx];
        if(ch == '.'){
            is_decimal = true;
        }
        else if(ch == '('){
            is_repeat = true;
        }
        else if(ch == ')'){

        }
        else{
            num *= 10;
            num += (ch - '0');
            if(is_decimal){
                ++cnt_decimal;
            }
            if(is_repeat){
                ++cnt_repeat;
            }
        }
    }

    int numerator, denominator;
    denominator = stoi(string(cnt_repeat, '9') + string(cnt_decimal - cnt_repeat, '0'));

    int sub = num;
    for(int ith=1; ith<=cnt_repeat; ++ith){
        sub /= 10;
    }
    numerator = num - sub;

    int _gcd = gcd(numerator, denominator);
    cout << number << " = " << numerator/_gcd << " / " << denominator/_gcd << endl;
}

void input(){
    while(cin >> number){
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
