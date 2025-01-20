/*
    https://www.acmicpc.net/problem/9019
    (dslr)

    solution
        https://www.acmicpc.net/source/49470375
        (shabby_whale, 1080 ms) : parent pointer, implemented in solev_bfs_3()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        4 operations
        D: (2n mod 10'000) D doubles up n. If the result is greater than 9999, modulo 10000 is taken.
        S: (10'000 + S - 1 mod 10'000) S subtracts one from n and stores the result n-1 to the register. If n is zero, 9999 is stored to the register instead.
        L: L rotates each of four digits of n to the left and stores the result to the register. After this operation, the four digits of the value of the register from left to right are (d2, d3, d4, d1).
        R: R rotates each of four digits of n to the right and stores the result to the register. After this operation, the four digits of the value of the register from left to right are (d4, d1, d2, d3).

        => Given two different integers A_str and B_str (A_str ≠ B_str), you are to write a program to generate a minimal sequence of commands changing the register contents from A_str to B_str

    Algorithm
        Q1. is it always possible (A_str -> B_str)
            D : binary shift left
            S : remove rightmost 1 bit and make trailing 1 bits
            L, R : decimal move bit (left / right)

            even only using S, we can go through every number 0...9999 therefore it is always possible to make (A_str -> B_str)

        Q2. how many commands required ?

            max num ~ 10^4
            max digit ~ 5

            # commands = k ?
            4 choices per step => 4^k

1
342 3459
DSRDRDLSS   (X)
DSRSLLDS    (O)

342 684 683 3068 3067 673 6730 3460 3459


1
9999 0
DDLSLDDRDDDD

*/

const int MIN_NUM = 0;
const int MAX_NUM = 10'000;     // 10^4
const int MOD = 10'000;         // 10^4
const int MAX_BIT = 4;
const int NUM_OPERATION = 4;

int T;
string A_str, B_str;
int A_num, B_num;

void solve_bfs_TLE(){
    queue<pair<string, string> > nodes;    // (num, command)
    set<string> visited;

    visited.insert((A_str));
    nodes.push({A_str, ""});

    while(!nodes.empty()){
        auto [curr, command] = nodes.front();
        nodes.pop();

        if(stoi(curr) == stoi(B_str)){
            cout << command << endl;
            break;
        }

        int curr_num = stoi(curr);
        string next_D = to_string((curr_num << 1) % MOD);
        string next_S = to_string((MOD + curr_num - 1) % MOD);
        string next_L = curr;
        string next_R = curr;
        int len = curr.size();
        for(int ith=0; ith<len; ++ith){
            next_L[ith] = curr[(ith + 1) % len];
            next_R[ith] = curr[(len + ith - 1) % len];
        }

        if(!visited.count(next_D)){
            visited.insert(next_D);
            nodes.push({next_D, command + 'D'});
        }
        if(!visited.count(next_S)){
            visited.insert(next_S);
            nodes.push({next_S, command + 'S'});
        }
        if(!visited.count(next_L)){
            visited.insert(next_L);
            nodes.push({next_L, command + 'L'});
        }
        if(!visited.count(next_R)){
            visited.insert(next_R);
            nodes.push({next_R, command + 'R'});
        }
    }
}

void solve_bfs_2(){
    queue<pair<int, string> > nodes;    // (num, command)
    bool visited[MAX_NUM + 1];
    // NOTE : MUST initialize every time
    for(int num=0; num<=MAX_NUM; ++num){
        visited[num] = false;
    }

    nodes.push({A_num, ""});
    visited[A_num] = true;

    while(!nodes.empty()){
        auto [curr, command] = nodes.front();
        nodes.pop();

        if(curr == B_num){
            cout << command << endl;
            return;
        }

        int num_D = (curr << 1) % MOD;
        int num_S = (MOD + curr - 1) % MOD;

        int msd = curr / 1'000;
        int lsd = curr % 10;
        int num_L = (curr * 10) % MOD + msd;
        // int num_L = (curr % 1'000) * 10 + msd;
        // int num_R = 1'000 * lsd + (curr / 10) % MOD;
        int num_R = 1'000 * lsd + (curr / 10);

        if(!visited[num_D]){
            visited[num_D] = true;
            nodes.push({num_D, command + "D"});
        }
        if(!visited[num_S]){
            visited[num_S] = true;
            nodes.push({num_S, command + "S"});
        }
        if(!visited[num_L]){
            visited[num_L] = true;
            nodes.push({num_L, command + "L"});
        }
        if(!visited[num_R]){
            visited[num_R] = true;
            nodes.push({num_R, command + "R"});
        }
    }
}

enum TYPES{
    type_d = 1,
    type_s = 2,
    type_l = 3,
    type_r = 4,
};

void solev_bfs_3(){
    pair<int, int> parent[MAX_NUM + 1]; // (parent, type)
    for(int num=0; num<=MAX_NUM; ++num){
        parent[num] = {-1, -1};
    }

    queue<int> nodes;   // num
    nodes.push(A_num);

    while(!nodes.empty()){
        int curr = nodes.front();
        nodes.pop();

        if(curr == B_num){
            break;
        }

        int num_D = (curr << 1) % MOD;
        int num_S = (MOD + curr - 1) % MOD;
        int num_L = (curr * 10) % MOD + curr / 1'000;
        int num_R = (curr % 10) * 1'000 + (curr / 10);
        int nums[] = { num_D, num_S, num_L, num_R };
        for(int type=1; type<=NUM_OPERATION; ++type){
            if(nums[type - 1] != A_num && parent[nums[type - 1]].first < 0){
                nodes.push(nums[type - 1]);
                parent[nums[type - 1]] = { curr, type };
            }
        }
    }

    // follow parent pointer and print backwards
    stack<char> stk;
    for(int num=B_num; num!=A_num; num=parent[num].first){
        int type = parent[num].second;
        if(type == type_d){
            stk.push('D');
        }
        else if(type == type_s){
            stk.push('S');
        }
        else if(type == type_l){
            stk.push('L');
        }
        else if(type == type_r){
            stk.push('R');
        }
    }

    while(!stk.empty()){
        cout << stk.top();
        stk.pop();
    }
    cout << endl;
}

void solve(){
    // solve_bfs_TLE();
    // solve_bfs_2();   // ~ 3'000 ms
    solev_bfs_3();      // ~ 1'000 ms
}

void input(){
    cin >> T;
    while(T--){
        // cin >> A_str >> B_str;
        cin >> A_num >> B_num;
        // A_str = to_string(A_num);
        // B_str = to_string(B_num);
        solve();
    }
}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    // solve();

    return 0;
}
