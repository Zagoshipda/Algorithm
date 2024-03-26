/*
    https://www.acmicpc.net/problem/16513
    (rational ratio)

    similar problem
        https://www.acmicpc.net/problem/5376
        (float to fraction) < solutions
        https://www.acmicpc.net/problem/9734
        (repeating decimals)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    repeating decimal points

*/

string number;
int repeat;

void solve(){
    int len = number.size();
    int cnt_num = 0;
    int cnt_decimal = 0;
    ll num = 0;
    ll decimal = 0;
    bool is_decimal = false;
    for(int idx=0; idx<len; ++idx){
        char ch = number[idx];
        if(ch == '.'){
            is_decimal = true;
        }
        else{
            if(is_decimal){
                ++cnt_decimal;
                num *= 10;
                decimal *= 10;
                decimal += (ch - '0');
            }
            else{
                ++cnt_num;
                num *= 10;
                num += (ch - '0');
            }
        }
    }

    ll numerator, denominator;

    denominator = stoll(string(repeat, '9') + string(cnt_decimal - repeat, '0'));

    // numerator = num + decimal - stol(number.substr(len-repeat, repeat));    // WRONG
    numerator = num + decimal;
    ll sub = numerator;
    for(int ith=1; ith<=repeat; ++ith){
        sub /= 10;
    }
    numerator -= sub;

    ll _gcd = gcd(numerator, denominator);
    cout << numerator/_gcd << "/" << denominator/_gcd << endl;
}

void input(){
    cin >> number >> repeat;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
