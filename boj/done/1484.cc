/*
    https://www.acmicpc.net/problem/1484
    (diet)

    similar problem
        https://www.acmicpc.net/problem/6131
        (perfect squares)

    solution
        implemented in solve_1()
            https://www.acmicpc.net/source/4662754
            (koosaga, 0 ms) : sort(vector<>)
            https://www.acmicpc.net/source/54473761
            (greydra_k, 0 ms) : using stack<>
            https://www.acmicpc.net/source/8550387
            (dlqudrjs, 0 ms)

        https://www.acmicpc.net/source/8457173
        (khj94811, 0 ms) : implemented in solve_2()

        https://www.acmicpc.net/source/10048291
        (movie_jo, 0 ms) : implemented in solve_two_pointer()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        x^2 - y^2 = G >= 1
        (x+y)(x-y) = G
        => check all divisors of G s.t. x-y <= x+y

        x^2 = G + y^2
*/

const int MAX_NUM = 100'000;    // 10^5

int G;

vector<pair<int, int> > divisors;   // (x-y, x+y)
void solve_1(){
    int div_1, div_2;
    for(int div=1; div*div<=G; ++div){
        if(G % div == 0){
            div_1 = div;
            div_2 = G / div;
            if(div_2 - div_1 && ((div_1 + div_2) & 1) == 0){
                divisors.push_back({div, G / div});
            }
        }
    }

    if(divisors.empty()){
        cout << -1 << endl;
        return;
    }

    for(auto it=divisors.rbegin(); it!=divisors.rend(); ++it){
        auto [val_1, val_2] = *it;
        // if((val_1 + val_2) & 1 == 0){   // WRONG : operator precedence
        // if(((val_1 + val_2) & 1) == 0){
            cout << ((val_1 + val_2) >> 1) << endl;
        // }
    }
}

bool is_square(ll num){
    // 0 ms
    // int root = sqrt(num);   // WRONG
    ll root = sqrt(num);
    return root * root == num;

    // 552 ms
    // for(ll div=1; div*div<=num; ++div){
    //     if(num == div*div){
    //         return true;
    //     }
    // }

    // return false;
}

void solve_2(){
    ll diff;
    bool is_exist = false;
    for(ll num=2; num<=(G+1) >> 1; ++num){
    // for(ll num=2; num<=G; ++num){
        diff = num * num - G;
        if(diff > 0 && is_square(diff)){
            cout << num << endl;
            is_exist = true;
        }
    }

    if(!is_exist){
        cout << -1 << endl;
    }
}

void solve_two_pointer(){
    int cnt = 0;
    int diff;
    for(int left=1, right=2; left < right; ){
        diff = right * right - left * left;
        if(diff == G){
            cout << right << endl;
            ++cnt;
            ++right;
        }
        else if(diff > G){
            ++left;
        }
        else if(diff < G){
            ++right;
        }
    }
    if(cnt <= 0){
        cout << -1 << endl;
    }
}

void solve(){
    // solve_1();
    solve_2();
    // solve_two_pointer();
}

void input(){
    cin >> G;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
