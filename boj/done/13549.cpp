#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

// SIZE do NOT have to be bigger than 100001 (this value is optimal)
// refer to (https://www.acmicpc.net/board/view/93293)
#define SIZE 100001
int N, K;
bool visited[SIZE];
int fastest_time[SIZE];
queue<int> node;
// int MAX_POSITION = 20;
int MAX_POSITION = SIZE-1;

// time exceeded (for loop examination all the time is expected to take too much time)
void calculate_fastest_time_bfs(){
    for(int position=N; position<=MAX_POSITION; position *= 2){
        if(!visited[position]){
            node.push(position);
            visited[position] = true;
            fastest_time[position] = 0;
        }
    }

    while(!node.empty()){
        int current = node.front();
        node.pop();
        // cout << "current : " << current << endl;

        if(current == K){
            break;
        }

        if(0 <= current-1 && !visited[current-1]){
            // time exceeded
            for(int position=current-1; position<=MAX_POSITION; position *=2){
                if(!visited[position]){
                    node.push(position);
                    visited[position] = true;
                    fastest_time[position] = fastest_time[current] + 1;
                }
                else{
                    continue;
                }
            }
        }

        if(current+1 <= MAX_POSITION && !visited[current+1]){
            // time exceeded
            for(int position=current+1; position<=MAX_POSITION; position *=2){
                if(!visited[position]){
                    node.push(position);
                    visited[position] = true;
                    fastest_time[position] = fastest_time[current] + 1;
                }
                else{
                    continue;
                }
            }
        }
    }
}

deque<int> nodes;
void calculate_fastest_time_dequeue(){
    nodes.push_front(N);
    visited[N] = true;
    fastest_time[N] = 0;

    while(!nodes.empty()){
        int current = nodes.front();
        nodes.pop_front();

        if(current == K){
            break;
        }

        int next[3] = { 2*current, current-1, current+1 };
        for(int i=0; i<3; ++i){
            if(0 <= next[i] && next[i] <= MAX_POSITION && !visited[next[i]]){
                visited[next[i]] = true;
                if(i <= 0){
                    nodes.push_front(next[i]);
                    fastest_time[next[i]] = fastest_time[current];
                }
                else{
                    nodes.push_back(next[i]);
                    fastest_time[next[i]] = fastest_time[current] + 1;
                }
            }
        }
    }
}

int main(){
    IOS;

    cin >> N >> K;

    // MAX_POSITION = min(MAX_POSITION, 2*K);

    // calculate_fastest_time_bfs();
    calculate_fastest_time_dequeue();

    // for(int i=1; i<=15; ++i){
    //     cout << fastest_time[i] << " ";
    // }
    // cout << endl;

    cout << fastest_time[K] << endl;

    return 0;
}
