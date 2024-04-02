/*
    https://www.acmicpc.net/problem/10465
    (rolling encryption)

    solutions
        https://www.acmicpc.net/source/2685125
        (dotorya, 4 ms)
        https://www.acmicpc.net/source/2685213
        (ialy1595, 4 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MOD = 26;
int k;
string word;

int cnt[MOD];
void solve_1(){
    int len = word.size();
    string ans;
    for(int idx=0; idx<k; ++idx){
        ans.push_back(word[idx]);
    }

    for(int idx=k; idx<len; ++idx){
        for(int i=0; i<MOD; ++i){
            cnt[i] = 0;
        }

        for(int jdx=idx-k; jdx<idx; ++jdx){
            ++cnt[word[jdx]-'a'];
        }

        int max_cnt = 0;
        int shift;
        for(int jdx=0; jdx<MOD; ++jdx){
            if(max_cnt < cnt[jdx]){
                max_cnt = cnt[jdx];
                shift = jdx + 1;
            }
        }

        char ch = word[idx];
        // cout << ch << " " << shift << endl;
        for(int jdx=0; jdx<shift; ++jdx){
            if(ch == 'z'){
                ch = 'a';
            }
            else{
                ++ch;
            }
        }
        ans.push_back(ch);
    }

    cout << ans << endl;
}

void solve_2(){
    int len = word.size();
    string ans;
    for(int idx=0; idx<k; ++idx){
        ans.push_back(word[idx]);
        ++cnt[word[idx]-'a'];
    }

    for(int idx=k; idx<len; ++idx){
        // if(idx > k){
        //     --cnt[word[idx-k-1]-'a'];
        //     ++cnt[word[idx-1]-'a'];
        // }

        int max_cnt = 0;
        int shift;
        for(int jdx=0; jdx<MOD; ++jdx){
            if(max_cnt < cnt[jdx]){
                max_cnt = cnt[jdx];
                shift = jdx + 1;
            }
        }
        // cout << idx << " " << shift << endl;

        char ch = word[idx];
        ch = (ch - 'a' + shift) % MOD + 'a';
        ans.push_back(ch);

        // process at the end
        ++cnt[word[idx]-'a'];
        --cnt[word[idx-k]-'a'];
    }

    cout << ans << endl;
}

void solve(){
    // solve_1();  // 676 ms

    solve_2();  // 4 ms
}

void input(){
    cin >> k;
    cin >> word;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
