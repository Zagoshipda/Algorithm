/*
    https://www.acmicpc.net/problem/4375
    (ones)

    reference
        https://www.acmicpc.net/board/view/112354

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        any integer 0 <= n <= 10000 not divisible by 2 or 5,
        some multiple of n is a number which in decimal notation is a sequence of 1's

    Algorithm
        observation : 1...1 = (10^k-1) / 9
        (1) 10^phi(n) = 1 (mod n) if gcd(10, n)=1
            n not divisible by 2 or 5 => not divisible by 10 => gcd(n, 10) = 1
            => 10^phi(n) = 1 (mod n) or n^phi(10) = n^4 = 1 (mod 10)

        (2) 10^phi(n)-1 = 0 => 1...1 = (10^phi(n)-1)/9 = 0 (mod n) s.t. phi(n) < n
            (n * k) = a_x*10^x + a_x-1*10^x-1 + ... + a_1*10^1 + a_0 (x+1 digit)
                    = 10^x + 10^x-1 + ... + 10^1 + 10^0 (since all a_i = 1)
            here apply modular by n to both sides we get
            0 = 10^x + 10^x-1 + ... + 10^1 + 10^0 (mod n)
                = 1 + 1 + ... + 10^phi(n) + ... + 10^1 + 10^0 (mod n)
                = x-phi(n) + 1...1(phi(n) + 1 digit) (mod n)
            => brute force here, just add ones and take modular, and check if it becomes zero



    1 2 3 4 5 6 7 8 9 10
    1   3   5   7   9
        1  3  7  9
        11 13 17 19
        21 23 27 29

    3 * 3 * 13 = 111
    29 * x = 1...1
    (19+10) * x = 19*x + 10*x = 11...1

    1...1 = m * x ? (multiples of any number x s.t. not multiples of 2 or 5)
        1...1 1...1 ... 1...1 : a * (k+1) digit
        = 1...1 * (1+10^a+10^2a+...+10^ka)
        = 1...1 * sum (10^ka for a=0...k)
        = 1...1 * (10^a(k+1)-1)/10^a-1
        = 1...1 * (9...9 a(k+1)digit / 9...9 a digit)
        = 1...1 (a digit) * 0...01 0...01 0...01 0...01 (a*(k+1) digit, k+1 slots)

        ex. a=2 * (k=1+1)
        11 11 = 11 * (100+1) = 11 * (100^2-1/99) = 11 * (9999/99) = 11 * 0101

*/

int n;

void solve_number_wrong(){
    ll ones = 1;
    int digit = 1;
    while(ones % n){    // error : may overflow long long
        ones *= 10;
        ones += 1;
        ++digit;
    }
    cout << digit << endl;
}

void solve_number(){
    int ones = 0;
    int digit;
    for(digit=1; digit<n; ++digit){
        ones *= 10;
        ones += 1;
        ones %= n;
        if(ones == 0){
            break;
        }
    }
    cout << digit << endl;
}

void solve_vector(){
    vector<int> ones;
    ones.push_back(1);
    int remainder = 1;
    remainder %= n;
    while(remainder){
        ones.push_back(1);
        remainder *= 10;
        remainder += 1;
        remainder %= n;
    }
    cout << ones.size() << endl;
}

void solve(){
    // solve_number_wrong();
    solve_number();

    // solve_vector();
}

void input(){
    while(cin >> n){
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
