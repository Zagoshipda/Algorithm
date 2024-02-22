/*
    https://www.acmicpc.net/problem/10816
    (number card 2)

    similar problem
        https://www.acmicpc.net/problem/10815
        (number card)

    solutions
        https://www.acmicpc.net/source/22527886
        (paldad, 280 ms) : array implementation

        https://www.acmicpc.net/source/4427131
        (goooora, 188 ms) : binary search

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MIN_NUM = -10'000'000;
const int MAX_NUM = 10'000'000;
const int NUM_CARD = 500'000;
int N;
int card;
int M;
int target;


// time exceeded
multiset<int> cards_set;
void solve_multiset(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> card;
        cards_set.insert(card);
    }
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> target;
        cout << cards_set.count(target) << " ";
    }
    cout << endl;
}

map<int, int> cards_map;
void solve_map(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> card;
        cards_map[card] += 1;
    }
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> target;
        cout << cards_map[target] << " ";
    }
    cout << endl;
}

unordered_map<int, int> cards_hash;
void solve_hash(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> card;
        cards_hash[card] += 1;
    }
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> target;
        cout << cards_hash[target] << " ";
    }
    cout << endl;
}

int cards_array[MAX_NUM - MIN_NUM + 1];
void solve_array(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> card;
        cards_array[card - MIN_NUM] += 1;
    }
    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> target;
        cout << cards_array[target - MIN_NUM] << " ";
    }
    cout << endl;
}

void solve(){
    // solve_multiset();

    // solve_map();

    // solve_hash();

    solve_array();
}

void input(){

}

int main(){
    IOS;

    // input();

    solve();

    return 0;
}
