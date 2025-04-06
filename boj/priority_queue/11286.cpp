/*
    https://www.acmicpc.net/problem/11286
    (min-absolute value & min-value heap)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_OPERATION 100'000
int N;
int x;

struct cmp{
    bool operator()(int num1, int num2) const{
        if(abs(num1) == abs(num2)){
            return num1 > num2;
        }
        else{
            return abs(num1) > abs(num2);
        }
    }
};

priority_queue<int, vector<int>, cmp > pq_min_abs;
void solve(){
    if(x){
        pq_min_abs.push(x);
    }
    else{
        if(pq_min_abs.empty()){
            cout << 0 << endl;
        }
        else{
            cout << pq_min_abs.top() << endl;
            pq_min_abs.pop();
        }
    }
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> x;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
