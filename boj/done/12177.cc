/*
    https://www.acmicpc.net/problem/12177
    (dreary design 3)

    solutions
        https://www.acmicpc.net/source/35452637
        (cozyyg, 0 ms)

        https://www.acmicpc.net/source/10479490
        (alex9801, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    bland if and only if all pairs of its component values differ by no more than V
    RGB range 0...K
    RGB difference 0...V for all pairs

    NOTE : K * K * K ~ 10^27 overflow ?

    AC
        range K >= choice V (length V+1 sliding window)
        0 1...    K
        0 1...V
            0 1...V

        (V+1)^3*(K-V+1) - V^3*(K-1-V+1) by inclusion-exclusion
        = ((V+1)^3-V^3)*(K-V) + (V+1)^3


    WRONG (different problem)
        for fixed R : max(0,R-V) <= G,B <= min(R+V,K)
        for V<=R<=K-V : 0<=G,B<=K

        ex.
        K=2, V=1
        0 1 2
        0 01 01       = 4
        1 012 012       = 9
        2 12 12       = 4
        => 17

        K=2, V=2
        0 1 2
        0 012 012       = 9
        1 012 012       = 9
        2 012 012       = 9
        => 27

        K=3, V=2
        0 1 2 3
        0 012 012       = 9
        1 0123 0123     = 16
        2 0123 0123     = 16
        3 123 123       = 9
        => 50 = 25 * 2 = (2V+1) * (K-1)

        K=4, V=2
        0 1 2 3 4
        0 012 012       = 9
        1 0123 0123     = 16
        2 01234 01234   = 25
        3 1234 1234     = 16
        4 234 234       = 9
        => 75 = 25 * 3

        K=6, V=2
        0 1 2 3 4 5 6
        0 012 012       = 9
        1 0123 0123     = 16
        2 01234 01234   = 25
        3 12345 12345   = 25
        4 23456 23456   = 25
        5 3456 3456     = 16
        6 456 456       = 9
        => 125 = 25 * 5

        suppose K > V
        0 1 ... K
        0   0..V 0...V                      = (V+1)^2
        1   01...V+1 01...V+1               = (V+2)^2
        ...
        V   0...V...2V 0...V...2V           = (2V+1)^2
        V+1 1...V+1...2V+1 1...V+1...2V+1   = (2V+1)^2
        ...
        K-V K-2V...K-V...K K-2V...K-V...K   = (2V+1)^2
        ...
        K   K-V...K K-V...K                 = (V+1)^2
        => (V+1)^2+...+(2V)^2 + (2V+1)^2+...+(2V+1)^2 + (2V)^2+...+(V+1)^2
        if K==2V+1 : 1 * (2V+1)^2
        if K==2V+2 : 2 * (2V+1)^2
        if K==2V+3 : 3 * (2V+1)^2

        if V = 0 : K + 1, since 000...KKK only possible
        else if V < K : (2V+1)^2 * (K-1)
        else K <= V : (K+1)^3, since all 0...K possible for each RGB


    opposite problem : what if difference bigger than V for all pairs ?
        = (# all - original problem)

        (all #) - (# 1-diff > V) + (# 2-diff > V) - (# 3-diff > V)
        # (RG > V) + # (GB > V) + # (RB > V)     =
        # RG > V + # RB > V + # GB > V  =
        # RGB > V                       =

        diff>V
            R=0 : G,B=V+1...K : (K-V + max(0,-V-1))^2
            R=1 : G,B=V+2...K : (K-V-1 + max(0,1-V-1))^2
            R=2 : G,B=V+3...K : (K-V-2 + max(0,2-V-1))^2
            ...
            R=K-V-1 : G,B=K...K : (1 + max(0,K-2V-2))^2
                0 <= K-V-1-(V+1) ?
                0 <= K-2V-2 ?
            sum( (K-V-R + max(0, R-V-1))^2 ) for R=0...K-V-1
            => time complexity = O(K) : max when V=0 ~ O(10^9)
*/

const ll MAX_COLOR = 2'000'000'000;
const ll MAX_DIFFERENCE = 1'000;
int T;
ll K, V;
int cnt;

void solve(){
    cout << "Case #" << cnt << ": ";
    cout << (V+1)*(V+1)*(V+1)* (K-V+1) - V*V*V* (K-V) << endl;
}

void input(){
    cin >> T;
    for(cnt=1; cnt<=T; ++cnt){
        cin >> K >> V;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
