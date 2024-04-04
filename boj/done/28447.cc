/*
    https://www.acmicpc.net/problem/28447
    (pick the ingredient)

    solutions
        using __builtin_popcount(), implemented in solve_brute_force_1()
            https://www.acmicpc.net/source/65011782
            (edenooo, 0 ms)
            https://www.acmicpc.net/source/65320918
            (golazcc83, 0 ms)
            https://www.acmicpc.net/source/65302315
            (hssong, 0 ms) : implemented in solve_brute_force_2()

    references
        implementing popcount() (population count / hamming weight)
            https://en.wikipedia.org/wiki/Hamming_weight#Efficient_implementation
            https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
            https://stackoverflow.com/questions/38644840/what-is-the-means-of-i-i-1-in-java
            https://blog.naver.com/PostView.naver?blogId=jinhan814&logNo=222540111549
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    NOTE : compatibility forms a symmetric matrix
*/

const int MAX_NUM = 10;                 // 10^1
const int MIN_COMPATIBILITY = -1'000;   // - 10^3
const int MAX_COMPATIBILITY = +1'000;   // + 10^3

int N, K;
int comp[MAX_NUM + 1][MAX_NUM + 1]; // compatibility between ingredient pair (a, b)
int max_taste = -1'000'000;         // - 10^6

bool used[MAX_NUM + 1];
void backtracking(int nth, int start){
    if(nth >= K){
        int taste = 0;
        for(int idx=1; idx<=N; ++idx){
            if(used[idx]){
                for(int jdx=1; jdx<=N; ++jdx){
                    if(used[jdx]){
                        taste += comp[idx][jdx];
                    }
                }
            }
        }
        taste >>= 1;

        max_taste = max(max_taste, taste);
        return;
    }

    for(int idx=start; idx<=N; ++idx){
        if(!used[idx]){
            used[idx] = true;
            backtracking(nth+1, idx+1);
            used[idx] = false;
        }
    }
}

void solve_backtracking(){
    backtracking(0, 1);

    cout << max_taste << endl;
}

// const int MAX_CHOICE = (1 << MAX_NUM) - 1;

int popcount(int num){
    int cnt = 0;
    for( ; num; num &= (num-1)){
        ++cnt;
    }
    return cnt;
}

void solve_brute_force_1(){
    int max_choice = (1 << N) - 1;  // 0 ~ 1...1
    for(int choice=1; choice<=max_choice; ++choice){
        if(popcount(choice) == K){
            vector<int> choices;
            int val = choice;
            for(int bit=1; val; ++bit){
                if(val & 1){
                    choices.push_back(bit);
                }
                val >>= 1;
            }

            int taste = 0;
            int len = choices.size();
            for(int idx=0; idx<len; ++idx){
                // for(int jdx=0; jdx<len; ++jdx){
                for(int jdx=idx+1; jdx<len; ++jdx){
                    taste += comp[choices[idx]][choices[jdx]];
                }
            }
            // taste >>= 1;

            max_taste = max(max_taste, taste);
        }
    }

    cout << max_taste << endl;
}

void solve_brute_force_2(){
    int max_choice = (1 << N) - 1;
    for(int choice=1; choice<=max_choice; ++choice){
        if(popcount(choice) == K){
            int taste = 0;
            for(int idx=1; idx<=N; ++idx){
                for(int jdx=idx+1; jdx<=N; ++jdx){
                    if((choice >> idx-1) & 1 && (choice >> jdx-1) & 1){
                        taste += comp[idx][jdx];
                    }
                }
            }
            max_taste = max(max_taste, taste);
        }
    }

    cout << max_taste << endl;
}

void solve(){
    // solve_backtracking();

    // solve_brute_force_1();
    solve_brute_force_2();
}

void input(){
    cin >> N >> K;
    for(int row=1; row<=N; ++row){
        for(int col=1; col<=N; ++col){
            cin >> comp[row][col];
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
