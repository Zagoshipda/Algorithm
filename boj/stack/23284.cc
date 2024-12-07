/*
    https://www.acmicpc.net/problem/23284
    (all stack sequence)

    similar problem
        https://www.acmicpc.net/problem/1874
        (stack sequence)

    solution
        backtracking
            https://www.acmicpc.net/source/34739195
            (qhsl1213, 28 ms)
            https://www.acmicpc.net/source/34721449
            (cozyyg, 8 ms)
            https://www.acmicpc.net/source/36876265
            (red1108, 8 ms) : implemented in solve_backtracking()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        10! = 3'628'800 ~ O(10^7)
        n ~ 10
        2's time limit

        stack sequence check ~ O(n) ~ O(10)

        brute force ~ O(10^8)
            try for all possible permutations

        backtracking ~ O(n!) ~ O(10^7)
            2 choices for each number : push or pop
*/

const int MAX_NUM = 10;     // 10^1

int n;

vector<int> seq;

void insert(stack<int>& stk, int& num){
    stk.push(num);
    ++num;
}

bool is_stack_sequence(){
    stack<int> stk;
    int num = 1;
    for(int ith=0; ith<n; ++ith){
        while(stk.empty() || stk.top() < seq[ith]){
            insert(stk, num);
        }

        if(stk.top() == seq[ith]){
            stk.pop();
        }
        else{
            return false;
        }
    }

    if(stk.empty()){
        return true;
    }
    else{
        return false;
    }
}

void print_sequence(){
    for(int s : seq){
        cout << s << " ";
    }
    cout << endl;
}

void solve_brute_force(){
    for(int num=1; num<=n; ++num){
        seq.push_back(num);
    }

    do{
        if(is_stack_sequence()){
            print_sequence();
        }
    }while(next_permutation(seq.begin(), seq.end()));
}

// void dfs(stack<int>& stk, int num){
void dfs(stack<int> stk, int num){
    if(seq.size() >= n){
        print_sequence();

        return;
    }

    if(!stk.empty()){
        int val = stk.top();
        stk.pop();

        seq.push_back(val);
        dfs(stk, num);
        seq.pop_back();

        stk.push(val);
    }

    if(num <= n){
        stk.push(num);
        dfs(stk, num + 1);
        // stk.pop();
    }
}

void solve_backtracking(){
    stack<int> stk;
    dfs(stk, 1);
}

void solve(){
    // solve_brute_force(); // 300 ms

    solve_backtracking();   // 16 ms
}

void input(){
    cin >> n;
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
