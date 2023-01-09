#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, K;
bool visited[100001];
int cnt[100001];
int dist[100001];

// memory overflow.
queue<int> pos;
void bfs(int start, int end){
    cnt[start] = 1;
    pos.push(start);
    dist[start] = 0;

    int now;
    while(!pos.empty()){
        now = pos.front();
        pos.pop();
        visited[now] = true;

        if(dist[now] >= dist[end]){
            break;
        }

        int next[3] = { now - 1, now + 1, 2 * now };
        for(int i=0; i<3; ++i){
            int _next = next[i];

            if(0 <= _next && _next <= 100000 && !visited[_next]){
                // pos.push(_next);

                if(dist[_next] == INT_MAX){
                    pos.push(_next);
                    dist[_next] = dist[now] + 1;
                    cnt[_next] = 1;
                }
                else{
                    if(dist[now] + 1 < dist[_next]){
                        pos.push(_next);
                        dist[_next] = dist[now] + 1;
                        cnt[_next] = 1;
                    }
                    else if(dist[now] + 1 == dist[_next]){
                        pos.push(_next);
                        cnt[_next] += 1;
                    }
                }
            }
        }
    }
}

void initialize(){
    for(int i=0; i<100001; ++i){
        dist[i] = INT_MAX;
        cnt[i] = 0;
    }
}

int main(){
    IOS;

    cin >> N >> K;

    initialize();

    bfs(N, K);

    cout << dist[K] << endl;
    cout << cnt[K] << endl;

    return 0;
}
