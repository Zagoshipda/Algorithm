#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 10001
#define ROOT 1
int n;
vector<pair<int,int>> tree[SIZE];
vector<pair<int,int>> tree2[SIZE];

queue<pair<int,int>> nodes;
bool visited[SIZE];
int point1, point2;
int weight;
int diameter;

void initialize(){
    while(!nodes.empty()){
        nodes.pop();
    }

    for(int i=0; i<SIZE; ++i){
        visited[i] = false;
    }
}

void find_farthest_node(pair<int,int> start){
    nodes.push(start);
    visited[start.first] = true;

    while(!nodes.empty()){
        pair<int,int> current = nodes.front();
        nodes.pop();
        if(current.second > weight){
            weight = current.second;
            point1 = current.first;
        }
        for(pair<int,int> next : tree[current.first]){
            if(!visited[next.first]){
                next.second += current.second;
                nodes.push(next);
                visited[next.first] = true;
            }
        }
    }
}

void find_farthest_node_2(pair<int,int> start){
    nodes.push(start);
    visited[start.first] = true;

    while(!nodes.empty()){
        pair<int,int> current = nodes.front();
        nodes.pop();
        diameter = max(diameter, current.second);
        for(pair<int,int> next : tree2[current.first]){
            if(!visited[next.first]){
                next.second += current.second;
                nodes.push(next);
                visited[next.first] = true;
            }
        }
    }
}

void calculate_tree_diameter(){
    find_farthest_node(make_pair(ROOT, 0));

    initialize();

    find_farthest_node_2(make_pair(point1, 0));
}

int main(){
    IOS;

    cin >> n;
    int parent, child, edge_weight;
    for(int i=0; i<n-1; ++i){
        cin >> parent >> child >> edge_weight;
        tree[parent].push_back(make_pair(child, edge_weight));
        tree2[parent].push_back(make_pair(child, edge_weight));
        tree[child].push_back(make_pair(parent, edge_weight));
        tree2[child].push_back(make_pair(parent, edge_weight));
    }

    calculate_tree_diameter();

    cout << diameter << endl;

    return 0;
}
