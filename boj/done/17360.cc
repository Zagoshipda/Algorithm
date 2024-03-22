/*
    https://www.acmicpc.net/problem/17360
    (palindrome subsequence)

    solutions
        disjoint set (union & find), implemented in solve_disjoint_set()
            https://www.acmicpc.net/source/74770331
            (79brue, 4 ms)
            https://www.acmicpc.net/source/14119154
            (koosaga, 4 ms)
            https://www.acmicpc.net/source/14420802
            (portableangel, 4 ms)
                N, K ~ 10^3
                N^2 ~ 10^6
                => possible to check all substrings

        closed form solution, implemented in solve_closed_form()
            https://www.acmicpc.net/source/33121680
            (thenitromefan, 0 ms) : power by binary exponential

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

    dp ?
        1 2 ... N-1 N
        1 2 ... N-1 / 1 2 ... N-1 N
        new palindromes : (1...N) ... (N-1 N) (N)

    using a palindrome property
    N=2a
        K=1 : M^N (M choices for each element)
        K=N : M^(N+1)/2
        K=2x : M (all numbers are the same)
        K=2x+1 : M^2 (2 equivalence classes)
        K>N : M^N (no condition for the array element)
    N=2a+1
        K=1 : M^N (M choices for each element)
        K=N : M^(N+1)/2
        K=2x : M (all numbers are the same)
        k=2x+1 : M^2 (2 equivalence classes)
        K>N : M^N (no condition for the array element)

ex.

4 3 4
oxxo : 3^2

5 2 1
12 12 12 12 12 : 2^5 = 32

5 2 2
ooooo : 2 (all numbers are the same)

5 2 3
oxoxo : 2^2 = 4

5 2 4
xxxxx : 2

5 2 5 : 2^3 = 8
oxaxo

7 3 1 : 3^7
7 3 2 : 3 (all numbers are the same
xxxxxxx
7 3 3 : 3^2
xoxoxox
7 3 4 : 3
ooooooo
7 3 5 : 3^2
oxoxoxo
7 3 6 : 3
oxaaxo?
?oxaaxo

7 3 7 : 3^4
oxabaxo


*/

const int MOD = 1'000'000'007;  // 10^9 + 7
const int ARR_SIZE = 2'000;
const int MAX_NUM = 2'000;

ll N, M, K;

class Disjoint_Set{
    private:
        int parent[ARR_SIZE + 1];
    public:
        Disjoint_Set(){
            for(int i=0; i<=ARR_SIZE; ++i){
                parent[i] = i;
            }
        }

        int find_set(int node){
            while(parent[node] != node){
                node = parent[node] = parent[parent[node]];
            }
            return node;
        }

        void union_set(int node_1, int node_2){
            int rep_1 = find_set(node_1);
            int rep_2 = find_set(node_2);
            if(rep_1 != rep_2){
                parent[rep_2] = rep_1;
            }
        }
};

Disjoint_Set disjoint_set;
bool used[ARR_SIZE + 1];
void solve_disjoint_set(){
    for(int idx=1; idx<=N-K+1; ++idx){
        for(int left=idx, right=idx+K-1; left<right; ++left, --right){
            disjoint_set.union_set(left, right);
        }
    }

    ll cnt = 1;
    for(int idx=1; idx<=N; ++idx){
        // if(!used[disjoint_set.find_set(idx)]){
        //     cnt *= M;
        //     cnt %= MOD;
        //     used[disjoint_set.find_set(idx)] = true;
        // }
        if(disjoint_set.find_set(idx) == idx){
            cnt *= M;
            cnt %= MOD;
        }
    }
    cout << cnt << endl;
}

void solve_closed_form(){
    ll cnt = 1;
    int power;
    if(K == 1){
        power = N;
    }
    else if(K == N){
        power = (N+1) >> 1;
    }
    else if(K > N){
        power = N;
    }
    else if(K & 1){
        power = 2;
    }
    else{   // K & 1 == 0
        power = 1;
    }

    for(int i=1; i<=power; ++i){
        cnt *= M;
        cnt %= MOD;
    }
    cout << cnt << endl;
}

void solve(){
    // solve_closed_form();

    solve_disjoint_set();
}

void input(){
    cin >> N >> M >> K;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
