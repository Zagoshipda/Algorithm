#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int A[12];
bool visited[12];
int act[5];
int max_value = INT_MIN, min_value = INT_MAX;

void dfs(int depth, int value){
    if(depth >= N){
        max_value = max(value, max_value);
        min_value = min(value, min_value);
        return;
    }

    for(int i=1; i<5; ++i){
        if(act[i] > 0){
            --act[i];
            if(i == 1){
                dfs(depth + 1, value + A[depth + 1]);
            }
            else if(i == 2){
                dfs(depth + 1, value - A[depth + 1]);
            }
            else if(i == 3){
                dfs(depth + 1, value * A[depth + 1]);
            }
            else if(i == 4){
                dfs(depth + 1, value / A[depth + 1]);
            }
            ++act[i];
        }
    }
}

int main(){
    IOS;

    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> A[i];
    }
    for(int i=1; i<5; ++i){
        cin >> act[i];
    }

    dfs(1, A[1]);

    cout << max_value << endl;
    cout << min_value << endl;

    return 0;
}
