/*
    https://www.acmicpc.net/problem/2252
    (partial line up)

    solution
        https://www.acmicpc.net/source/16730323
        (lighthouse97, 28 ms) : indegree + queue<>

        backward
            https://www.acmicpc.net/source/16413830
            (namespace, 24 ms) : dfs
            https://www.acmicpc.net/source/17573304
            (rlaxogml97, 24 ms) : dfs
            https://www.acmicpc.net/source/9851852
            (sjnam07, 24 ms) : dfs + stack<>
            https://www.acmicpc.net/source/18292740
            (YunGoon, 8 ms) : indegree + stack<>
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        DAG topological sort
*/

const int NUM_VERTEX = 32'000;  // 32 * 10^3
const int NUM_EDGE = 100'000;   // 10^5

int N, M;
int A, B;

vector<int> dag[NUM_VERTEX + 1];
bool visited[NUM_VERTEX + 1];
int indegree[NUM_VERTEX + 1];

list<int> li;
stack<int> stk;
void print_answer(){
    for(int e : li){
        cout << e << " ";
    }
    cout << endl;

    // while(!stk.empty()){
    //     cout << stk.top() << " ";
    //     stk.pop();
    // }
    // cout << endl;
}

void dfs(int node){
    for(int next : dag[node]){
        if(!visited[next]){
            visited[next] = true;
            dfs(next);
        }
    }

    li.push_front(node);
    // stk.push(node);
}

void solve_dfs(){
    for(int student=1; student<=N; ++student){
        if(!visited[student]){
            visited[student] = true;
            dfs(student);
        }
    }

    print_answer();
}

void solve_bfs(){
    queue<int> nodes;
    for(int vertex=1; vertex<=N; ++vertex){
        if(indegree[vertex] == 0){
            nodes.push(vertex);
        }
    }

    while(!nodes.empty()){
        int curr = nodes.front();
        nodes.pop();

        cout << curr << " ";

        for(int next : dag[curr]){
            --indegree[next];
            if(indegree[next] == 0){
                nodes.push(next);
            }
        }
    }
    cout << endl;
}

void solve(){
    // solve_bfs();

    solve_dfs();
}

void input(){
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> A >> B;
        dag[A].push_back(B);
        ++indegree[B];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
