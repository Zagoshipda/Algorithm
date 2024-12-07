/*
    https://www.acmicpc.net/problem/1874
    (stack sequence)

    similar problem
        https://www.acmicpc.net/problem/23284
        (all stack sequence)

    solution
        https://www.acmicpc.net/source/40392523
        (cc951, 12 ms)
        https://www.acmicpc.net/source/16712135
        (qdjjd, 8 ms) : using array
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - 1...n
        - stack push in increasing order

    Algorithm
        all sequence made from stack (pop / push) ?
        increasing - decreasing

        => just simulate


3
2 3 1

// + + - + - -


*/

const int ARR_SIZE = 100'000;   // 10^5

int n;
int arr[ARR_SIZE + 1];

stack<int> stk;

void solve_1(){
    string ans;

    int pos = 1;
    for(int num=1; num<=n; ++num){
        stk.push(num);
        ans.push_back('+');

        while(!stk.empty() && arr[pos] == stk.top()){
            stk.pop();
            ans.push_back('-');
            ++pos;
        }
    }

    if(!stk.empty()){
        cout << "NO" << endl;
    }
    else{
        for(auto c : ans){
            cout << c << endl;
        }
    }
}

void insert(int& num, vector<char>& ans){
    stk.push(num);
    ++num;
    ans.push_back('+');
}

void solve_2(){
    vector<char> ans;
    int num = 1;
    for(int ith=1; ith<=n; ++ith){
        if(stk.empty()){
            insert(num);
        }

        while(!stk.empty() && stk.top() < arr[ith]){
            insert(num);
        }

        if(stk.top() == arr[ith]){
            stk.pop();
            ans.push_back('-');
        }
        else{
            cout << "NO" << endl;
            return;
        }
    }

    for(char c : ans){
        cout << c << endl;
    }
}

void solve(){
    // solve_1();

    solve_2();
}

void input(){
    cin >> n;
    for(int ith=1; ith<=n; ++ith){
        cin >> arr[ith];
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
