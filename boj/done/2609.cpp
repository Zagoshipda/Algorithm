#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int a, b;

int gcd_1(int a, int b){
    int big = max(a, b);
    int small = min(a, b);
    while(small != big){
        big -= small;
        if(big < small){
            swap(big, small);
        }
    }

    return small;
}

int gcd_2(int a, int b){
    int r;
    while(a > 0){
        r = b % a;
        b = a;
        a = r;
    }

    return b;
}

int gcd_recursive(int a, int b){
    if(a == 0){
        return b;
    }

    return gcd_recursive(b % a, a);
}

int gcd_brute_force(int a, int b){
    for(int i=min(a, b); i>=1; --i){
        if(a % i == 0 && b % i == 0){
            return i;
        }
    }

    return 1;
}

int gcd(int a, int b){
    // return gcd_1(a, b);

    return gcd_2(min(a, b), max(a, b));
    // return gcd_recursive(min(a, b), max(a, b));

    // return gcd_brute_force(a, b);
}

int lcm(int a, int b){
    // int _gcd = gcd(a, b);
    // return _gcd * (a/_gcd) * (b/_gcd);

    return (a * b) / gcd(a, b);
}

void solve(){
    cout << gcd(a, b) << endl;
    cout << lcm(a, b) << endl;
}

int main(){
    IOS;

    cin >> a >> b;

    solve();

    return 0;
}
