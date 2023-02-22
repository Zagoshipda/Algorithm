#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, M;
int arr[9];
bool visited[9];

void dfs(int depth){
    if(depth == M){
        for(int i=0; i<M; ++i){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    for(int i=1; i<=N; ++i){
        if(!visited[i] && arr[depth-1] < i){
            visited[i] = true;
            arr[depth] = i;
            dfs(depth + 1);
            visited[i] = false;
            arr[depth] = 0;
        }
    }
}

int main(){
    IOS;

    cin >> N >> M;

    dfs(0);

    return 0;
}
