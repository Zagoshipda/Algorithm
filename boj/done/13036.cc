/*
    https://www.acmicpc.net/problem/13036
    (zeroes and ones)

    solutions
        https://www.acmicpc.net/source/52009648
        (xiaowuc1, 0 ms) : using boolean array

        using xor with char array, implemented in solve_xor()
            https://www.acmicpc.net/source/13171721
            (koosaga, 0 ms)
            https://www.acmicpc.net/source/13171758
            (jaydoubluel, 0 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - Given two strings of the same length
        - make them equal using operation s.t. take two adjacent characters of "one of" the strings and invert them both
        - Inversion transforms 0 to 1 and 1 to 0
        - use the minimal number of inversion operations

    Algorithm
        when it is (possible / impossible) ?
        for each inversion, # of 1's and 0's changes only by multiples of 2
        => parity (# of 1's / # of 0's) remains the same
        => can always make into 2 groups
        ex.
            n=2 (00 11) (01 10)
            n=3 (000 110 101 011) (001 111 010 100)
            n=4 (0000 0011 0101 0110 1010 1100 1001 1111) 1's 0 or 2 or 4 (even)
                (0001 0010 0100 1000 0111 1011 1101 1110) 1's 1 or 3 (odd)

        how to get the minimum # of inversions ?
            => greedy choice (just do it, simulation)
*/

const int MAX_SIZE = 100'000;   // 10^5
int t;
int n;
string str_1;
string str_2;

void solve_string(){
    int cnt_1 = 0;
    int cnt_2 = 0;
    for(int idx=0; idx<n; ++idx){
        if(str_1[idx] == '1'){
            ++cnt_1;
        }
        if(str_2[idx] == '1'){
            ++cnt_2;
        }
    }

    if((cnt_1 + cnt_2) & 1){
        cout << -1 << endl;
    }
    else{
        int idx;
        int cnt = 0;
        for(idx=0; idx<n-1; ++idx){
            if(str_1[idx] != str_2[idx]){
                // inversion operation
                ++cnt;
                if(str_1[idx] == '0'){
                    str_1[idx] = '1';
                }
                else{
                    str_1[idx] = '0';
                }
                if(str_1[idx+1] == '0'){
                    str_1[idx+1] = '1';
                }
                else{
                    str_1[idx+1] = '0';
                }
            }
        }
        cout << cnt << endl;
    }
}

void solve_xor(){
    vector<int> is_different;
    for(int idx=0; idx<n; ++idx){
        is_different.push_back(str_1[idx] ^ str_2[idx]);
        // cout << is_different[idx] << " ";
    }
    // cout << endl;

    int cnt = 0;
    for(int idx=0; idx<n-1; ++idx){
        if(is_different[idx]){
            is_different[idx] ^= 1;
            is_different[idx + 1] ^= 1;
            ++cnt;
        }
    }

    if(is_different[n-1]){
        cout << -1 << endl;
    }
    else{
        cout << cnt << endl;
    }
}

void solve(){
    // solve_string();

    solve_xor();
}

void input(){
    cin >> t;
    while(t--){
        cin >> n;
        cin >> str_1;
        cin >> str_2;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
