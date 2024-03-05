/*
    https://www.acmicpc.net/problem/1735
    (fraction sum)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

29999 29997
29995 29993

// 1799520022 899700021
*/

int a, b;
int c, d;

void solve_1(){
    // ERROR : int overflow
    // int denominator = lcm(b, d);
    // int numerator = a * denominator / b + c * denominator / d;

    // int denominator = lcm(b, d);
    // int numerator = a * (denominator / b) + c * (denominator / d);

    ll denominator = lcm(b, d);
    ll numerator = a * denominator / b + c * denominator / d;

    int divisor = gcd(numerator, denominator);
    cout << numerator/divisor << " " << denominator/divisor << endl;
}

void solve_2(){
    int denominator = b * d;
    int numerator = a * d + b * c;
    int divisor = gcd(numerator, denominator);
    // cout << divisor << endl;
    cout << numerator/divisor << " " << denominator/divisor << endl;
}

void solve(){
    // solve_1();
    solve_2();
}

void input(){
    cin >> a >> b;
    cin >> c >> d;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
