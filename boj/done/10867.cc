/*
    https://www.acmicpc.net/problem/10867
    (sort without duplicates)

    solution
        https://www.acmicpc.net/source/74819322
        (jms020820, 12 ms) : vector<> sort() unique() erase()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int ARR_SIZE = 100'000;    // 10^5
const int MIN_NUM = -1'000;    // - 10^3
const int MAX_NUM = +1'000;    // + 10^3

int N;
int num;

vector<int> num_vec;
void solve_vector(){
    sort(num_vec.begin(), num_vec.end(), less<int>());
    // NOTE : unique returns iterator
    num_vec.erase(unique(num_vec.begin(), num_vec.end()), num_vec.end());
    for(int n : num_vec){
        cout << n << " ";
    }
    cout << endl;
}

set<int> num_set;
void solve_set(){
    for(int number : num_set){
        cout << number << " ";
    }
    cout << endl;
}

bool hashes[MAX_NUM << 2];
void solve_counting_sort(){
    for(int idx=0; idx<=(MAX_NUM<<1); ++idx){
        if(hashes[idx]){
            cout << idx - MAX_NUM << " ";
        }
    }
    cout << endl;
}

void solve(){
    // solve_set();

    // solve_vector();

    solve_counting_sort();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> num;
        // num_vec.push_back(num);
        // num_set.insert(num);
        hashes[num + MAX_NUM] = true;
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
