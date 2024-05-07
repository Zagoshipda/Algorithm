/*
    https://www.acmicpc.net/problem/21479
    (number)

    similar problem
        https://www.acmicpc.net/problem/16496
        (make a big number)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - The number of lines in the input file does not exceed 100
        - each line contains from 1 to 100 digits
        - It is guaranteed that in "at least one line the first digit is NOT zero"
        => find the maximum number before cutting

4
00
0020
001
0010

// 40020001001000

*/

const int ARR_SIZE = 100;
const int MAX_DIGIT = 100;

int len = 1;
string numbers[ARR_SIZE + 1];

string num;
vector<string> vec_num;

struct cmp_numbers{
    bool operator()(string num_1, string num_2){
        return (num_1 + num_2) > (num_2 + num_1);
    }
};

void solve_array(){
    --len;  // NOTE : len range
    sort(numbers+1, numbers+1+len, cmp_numbers());

    for(int idx=1; idx<=len; ++idx){
        cout << numbers[idx];
    }
    cout << endl;
}

void solve_vector(){
    sort(vec_num.begin(), vec_num.end(), cmp_numbers());

    for(string num : vec_num){
        cout << num;
    }
    cout << endl;
}

void solve(){
    // solve_array();
    solve_vector();
}

void input(){
    while(cin >> num){
        numbers[len] = num;
        ++len;

        vec_num.push_back(num);
    }
}

int main(){
    IOS;

    // freopen("21479.in", "rt", stdin);
    // freopen("21479.out", "wt", stdout);

    input();

    solve();

    return 0;
}
