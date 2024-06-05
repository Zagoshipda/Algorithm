/*
    https://www.acmicpc.net/problem/6800
    (Huffman encoding)

    solution
        https://www.acmicpc.net/source/22418628
        (dotorya, 0 ms)

    reference
        https://en.wikipedia.org/wiki/Huffman_coding
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - "prefix-free" property: a binary sequence for one character is never a prefix of another character’s binary sequence
        - to construct a "prefix-free" binary sequence, put the characters as the leaves, and label the left edge as 0, and the right edge as 1
        - The path from the root to a leaf node forms the code for the character at that leaf node
        - any sequence of these codes can be uniquely decoded into the original characters
*/

const int MAX_LENGTH = 10;
const int MAX_CODE_LENGTH = 250;

int k;
char ch;
string seq;
string code;
unordered_map<string, char> hashes;

void solve_greedy(){
    int len = code.size();
    for(int pos=0, cnt=1; pos<len; ++cnt){
        string key = code.substr(pos, cnt);
        if(hashes.count(key) > 0){
            cout << hashes[key];
            pos += cnt;
            cnt = 0;
        }
    }
    cout << endl;
}

void solve(){
    solve_greedy();
}

void input(){
    cin >> k;
    for(int i=1; i<=k; ++i){
        cin >> ch >> seq;
        hashes.insert({seq, ch});
    }
    cin >> code;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
