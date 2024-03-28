/*
    https://www.acmicpc.net/problem/16165
    (idol master)

    solutions
        https://www.acmicpc.net/source/10381630
        (henry1214, 0 ms) : only 1 hash [member -> group]
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int NUM_GROUP = 100;
const int NUM_MEMBER = 100;
// const int HASH_SIZE = (NUM_GROUP * NUM_MEMBER) << 1;

struct IDOL{
    string name;
    int cnt;
    string members[NUM_MEMBER + 1];
};

enum TYPES{
    type_team = 0,
    type_member = 1,
};

int N, M;
string group_name;
int group_size;
string member_name;
int type;
string name;
// IDOL groups[NUM_GROUP + 1];
map<string, set<string> > groups;   // (group, members)
map<string, string> hashes;         // (a member, group)

void solve(){

}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        // cin >> groups[i].name;
        // cin >> groups[i].cnt;
        cin >> group_name;
        cin >> group_size;
        for(int ith=1; ith<=group_size; ++ith){
            // cin >> groups[i].members[ith];
            cin >> member_name;
            groups[group_name].insert(member_name);
            hashes[member_name] = group_name;
        }
    }

    for(int i=1; i<=M; ++i){
        cin >> name;
        cin >> type;
        if(type == type_team){
            for(string member : groups[name]){
                cout << member << endl;
            }
        }
        else{
            cout << hashes[name] << endl;
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
