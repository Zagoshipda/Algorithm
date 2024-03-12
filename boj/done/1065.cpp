/*
    https://www.acmicpc.net/problem/1065
    (digit arithmetic number)

    solutions
        https://www.acmicpc.net/source/687773
        (leekh100000, 0 ms) : closed form (a - b = b - c) brute force

        https://www.acmicpc.net/source/7170439
        (wariatros, 0 ms) : closed form (a + c = 2 * b) brute force
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = 1;
const int MAX_NUM = 1'000;

int N;

bool is_digit_arithmetic(int num){
    vector<int> digits;
    while(num){
        digits.push_back(num % 10);
        num /= 10;
    }
    int len = digits.size();
    int difference = digits[0] - digits[1];
    for(int idx=1; idx<=len-2; ++idx){
        if(digits[idx] - digits[idx+1] != difference){
            return false;
        }
    }
    return true;
}

void solve(){
    int cnt = 0;
    for(int num=1; num<=N; ++num){
        if(is_digit_arithmetic(num)){
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void input(){
    cin >> N;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
