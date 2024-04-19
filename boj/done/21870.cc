/*
    https://www.acmicpc.net/problem/21870
    (array GCD)

    solution
        https://www.acmicpc.net/source/66589085
        (aru0504, 28 ms) : implemented in divide_and_conquer_2()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 10^5 ~ 10^3 * 10^2 ~ 2^10 * 2^7 ~ 2^17
        => binary search ~ 17
        => brute force ?

    time complexity
        2^17 ~ 2^20 ~ 10^6

    gcd ai...aj
        NlogN ~ 17 * 10^5 ~ 10^7
*/

const int ARR_SIZE = 200'000;   // 2 * 10^5
const int MAX_NUM = 200'000;    // 2 * 10^5

int N;
int arr[ARR_SIZE + 1];

void solve_greedy_wrong(){
    int sum_gcd = 0;
    for(int left=1, right=N; left <= right; ){
        if(left == right){
            sum_gcd += arr[left];
            break;
        }

        int size = right - left + 1;
        int middle = left + (size >> 1) - 1;
        // int middle = ((left + right - 1) >> 1);

        int gcd_left = arr[left];
        int gcd_right = arr[right];
        int idx;
        for(idx=left; idx<=middle; ++idx){
            gcd_left = gcd(gcd_left, arr[idx]);
        }
        for(idx=middle+1; idx<=right; ++idx){
            gcd_right = gcd(gcd_right, arr[idx]);
        }

        // cout << middle << " " << gcd_left << " " << gcd_right << endl;
        if(gcd_left >= gcd_right){
            sum_gcd += gcd_left;
            left = middle + 1;
        }
        else{
            sum_gcd += gcd_right;
            right = middle;
        }
    }
    cout << sum_gcd << endl;
}

int divide_and_conquer_1(int left, int right){
    if(left == right){
        return arr[left];
    }

    int middle = (left + right - 1) >> 1;
    int gcd_left = arr[left];
    int gcd_right = arr[right];
    for(int idx=left; idx<=middle; ++idx){
        gcd_left = gcd(gcd_left, arr[idx]);
    }
    for(int idx=middle+1; idx<=right; ++idx){
        gcd_right = gcd(gcd_right, arr[idx]);
    }

    return max({
        divide_and_conquer_1(left, middle) + gcd_right,
        gcd_left + divide_and_conquer_1(middle + 1, right),
    });
}

pair<int, int> divide_and_conquer_2(int left, int right){
    if(left == right){
        return {arr[left], arr[left]};
    }

    int middle = (left + right - 1) >> 1;
    auto [gcd_left, sum_left] = divide_and_conquer_2(left, middle);
    auto [gcd_right, sum_right] = divide_and_conquer_2(middle + 1, right);

    return {gcd(gcd_left, gcd_right), max(gcd_left + sum_right, sum_left + gcd_right)};
}

void solve_divide_and_conquer(){
    // cout << divide_and_conquer_1(1, N) << endl;

    cout << divide_and_conquer_2(1, N).second << endl;
}

void solve(){
    // solve_greedy_wrong();

    solve_divide_and_conquer();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
