#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, K;
bool visited[100001];
int dist[100001];

queue<int> pos;
void bfs(int start, int end){
    visited[start] = true;
    dist[start] = 0;
    pos.push(start);

    int now, _pos;
    while(!pos.empty()){
        now = pos.front();
        pos.pop();

        if(now == end){
            break;
        }
        _pos = now - 1;
        if(0 <= _pos && _pos <= 100000 && !visited[_pos]){
            visited[_pos] = true;
            dist[_pos] = min(dist[_pos], dist[now] + 1);
            pos.push(_pos);
        }
        _pos = now + 1;
        if(0 <= _pos && _pos <= 100000 && !visited[_pos]){
            visited[_pos] = true;
            dist[_pos] = min(dist[_pos], dist[now] + 1);
            pos.push(_pos);
        }
        _pos = 2 * now;
        if(0 <= _pos && _pos <= 100000 && !visited[_pos]){
            visited[_pos] = true;
            dist[_pos] = min(dist[_pos], dist[now] + 1);
            pos.push(_pos);
        }
    }
}

int main(){
    IOS;

    cin >> N >> K;

    for(int i=0; i<100001; ++i){
        dist[i] = INT_MAX;
    }

    bfs(N, K);

    cout << dist[K] << endl;

    return 0;
}
