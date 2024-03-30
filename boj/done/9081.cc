/*
    https://www.acmicpc.net/problem/9081
    (next word)

    solutions
        https://www.acmicpc.net/source/1606777
        (armagedd, 0 ms) : using char [], implemented in solve_2()

        https://www.acmicpc.net/source/150088
        (movie_jo, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    find the lexicographically next word

    Algorithm
        Observation : if a_i > ... > a_j then a next word does NOT exist
        => find the first position where a_k < a_k+1

        then for a_k < a_k+1 > ... > a_n observe that a_kk+1 is the biggest number
            WANT : a_k => next larger number among (a_n...a_k+1)
            and then following numbers are in ascending order s.t.
            a_x (? < ? < ... < ?)

        => find the smallest number a_x that is larger than a_k among (a_k+1...a_n)
            current : a_k (a_k+1 ... a_x ... a_n)
            WANT    : a_x (a_n ... a_k ... a_k+1)
        observation : swap(a_k, a_x) does not change the order of (a_k+1...a_n)

        ex.
        3 2 4 1     > 3 4 1 2
        5 3 4 2 1   > 5 4 1 2 3
        4 2 5 3 1   > 4 3 1 2 5
        DBECA > DCABE
*/

int T;
string word;

void solve_permutation(){
    string ans = word;
    if(next_permutation(word.begin(), word.end())){
        ans = word;
    };

    cout << ans << endl;
}

void solve_1(){
    int len = word.size();
    for(int idx=len-1; idx>0; --idx){
        if(word[idx-1] < word[idx]){
            int pos = idx-1;
            for(int jdx=len-1; jdx>pos; --jdx){
                if(word[pos] < word[jdx]){
                    swap(word[pos], word[jdx]);
                    break;
                }
            }
            reverse(word.begin() + pos+1, word.end());
            cout << word << endl;
            return;
        }
    }

    cout << word << endl;
}

void solve_2(){
    int len = word.size();
    for(int idx=len-1; idx>=0; --idx){
        for(int jdx=len-1; jdx>idx; --jdx){
            if(word[idx] < word[jdx]){
                swap(word[idx], word[jdx]);
                reverse(word.begin() + idx+1, word.end());

                // NOTE : index trick for breaking nested loop
                // idx = 0;
                // break;
                cout << word << endl;
                return;
            }
        }
    }

    cout << word << endl;
}

void solve(){
    // solve_permutation();

    // solve_1();
    solve_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> word;
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
