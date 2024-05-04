/*
    https://www.acmicpc.net/problem/10972
    (next permutation)

    similar problem
        https://www.acmicpc.net/problem/10973
        (previous permutation)
        https://www.acmicpc.net/problem/10974
        (all permutation)

    solutions
        https://www.acmicpc.net/source/6918290
        (binaryrain01, 0 ms) : efficient sort using swap(front, back)
        https://www.acmicpc.net/source/881890
        (dpwls7506, 0 ms) :
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 10^4
    N! ~ N^N : backtracking impossible time complexity

    Algorithm
        ak ... aN
        if aN-1 < aN : swap
        if ak < ak+1 > ... > aN-1 > aN
            step1) find first position s.t. ak < ak+1 for k=N-1...1
            step2) swap(ak, am) s.t.
                (1) ak < ak+1 > ak+2 ... > am-1 > am > am+1 > ... > aN
                (2) ak+1 > ... > am > ak > am+1 > ... > aN holds
                (first number with ak < am, smallest number that is larget than ak)
            step3) sort(ak+1 ... aN) in ascending order as ak+1 < ... < aN

        N = 4
            2 1 3 4
            2 1 4 3

            3 2 1 4
            3 2 4 1
            ...
        N = 5
            2 1 3 4 5
            2 1 3 5 4
            3 2 4 1 5
            3 2 4 5 1
            3 2 5 1 4
            3 2 5 4 1
            ...
        N = 6
            3 1 2 4 5 6
            3 1 2 4 6 5
            3 1 2 5 4 6
            3 1 2 5 6 4
            ...
*/

const int MAX_NUM = 10'000;
int N;
int num;
vector<int> permutation;

void solve(){
    int len = permutation.size();
    if(len <= 1){
        cout << -1 << endl;
        return;
    }

    if(permutation[len-2] < permutation[len-1]){
        for(int idx=0; idx<=len-3; ++idx){
            cout << permutation[idx] << " ";
        }
        cout << permutation[len-1] << " " << permutation[len-2] << endl;
    }
    else{
        stack<int> stk;
        int prev_num = 0;
        int idx;
        for(idx=len-1; idx>=0; --idx){
            if(permutation[idx] > prev_num){
                stk.push(permutation[idx]);
                prev_num = permutation[idx];
            }
            else{
                prev_num = permutation[idx];
                break;
            }
        }
        // if(idx < 0){
        if(stk.size() >= N){
            cout << -1 << endl;
        }
        else{
            set<int> next;
            next.insert(prev_num);
            int start = MAX_NUM + 1;
            while(!stk.empty()){
                int num = stk.top();
                if(num > prev_num){
                    start = min(start, num);
                }
                next.insert(num);
                stk.pop();
            }
            next.erase(start);

            for(int pos=0; pos<idx; ++pos){
                cout << permutation[pos] << " ";
            }
            cout << start << " ";
            for(int num : next){
                cout << num << " ";
            }
            cout << endl;
        }
    }
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> num;
        permutation.push_back(num);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
