/*
    https://www.acmicpc.net/problem/24435
    (card game)

    solutions
        https://www.acmicpc.net/source/62719591
        (pizzaroot, 20 ms) : implemented in solve_permutation_1()

        https://www.acmicpc.net/source/65287622
        (xiaowuc1, 0 ms) : implemented in solve_permutation_2()

        https://www.acmicpc.net/source/54221204
        (eunlin, 12 ms) : implemented in backtracking_int()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    n ~ 10
    => brute force


1
3
323
334

// 43

*/

const int NUM_CARD = 8;
const int MIN_NUM = 1;
const int MAX_NUM = 9;
string INITIAL_VALUE = "0";

int T;
int n;
string bob;
string alice;

string target_str;
int target;

string max_num_str;
int max_num;
int cnt;
bool used[NUM_CARD + 1];
void initialize(){
    for(int i=0; i<=NUM_CARD; ++i){
        used[i] = false;
    }

    max_num_str = INITIAL_VALUE;
    max_num = 0;
}

void backtracking_string(int nth, string num){
    if(nth >= cnt){
        if(stoi(max_num_str) < stoi(num) && stoi(num) < stoi(target_str)){
            max_num_str = num;
        }
        return;
    }

    for(int idx=0; idx<n; ++idx){
        if(!used[idx]){
            used[idx] = true;
            backtracking_string(nth+1, num + alice[idx]);
            used[idx] = false;
        }
    }
}

void backtracking_int(int nth, int num){
    if(nth >= cnt){
        if(max_num < num && num < target){
            max_num = num;
        }
        return;
    }

    for(int idx=0; idx<n; ++idx){
        if(!used[idx]){
            used[idx] = true;
            backtracking_int(nth + 1, num * 10 + alice[idx]-'0');
            used[idx] = false;
        }
    }
}

void solve_backtracking(){
    string bob_1 = bob;
    string bob_2 = bob;
    reverse(bob_2.begin(), bob_2.end());
    target_str = min(bob_1, bob_2);
    target = stoi(target_str);

    // sort(alice.begin(), alice.end(), less<char>());
    for(cnt=n; cnt>=n-1; --cnt){
        initialize();
        // backtracking_string(0, ""); // 92 ms
        backtracking_int(0, 0);     // 16 ms
        // if(max_num_str > INITIAL_VALUE){
        if(max_num > 0){
            // cout << max_num_str << endl;
            cout << max_num << endl;
            break;
        }
    }

    // cout << max_num_str << endl;
}

void solve_permutation_1(){
    string bob_1 = bob;
    string bob_2 = bob;
    reverse(bob_2.begin(), bob_2.end());
    target = stoi(min(bob_1, bob_2));

    sort(alice.begin(), alice.end(), less<char>());
    max_num = 0;    // NOTE : initialize
    do{
        for(int idx=0; idx<n; ++idx){
            int curr = stoi(alice.substr(0, idx+1));
            if(max_num < curr && curr < target){
                max_num = curr;
            }
        }
    }while(next_permutation(alice.begin(), alice.end()));

    cout << max_num << endl;
}

void solve_permutation_2(){
    string bob_1 = bob;
    string bob_2 = bob;
    reverse(bob_2.begin(), bob_2.end());
    target = stoi(min(bob_1, bob_2));

    sort(alice.begin(), alice.end(), less<char>());
    max_num = 0;
    do{
        int curr = 0;
        for(int idx=0; idx<n; ++idx){
            curr *= 10;
            curr += alice[idx] - '0';
            if(curr < target){
                max_num = max(max_num, curr);
            }
        }
    }while(next_permutation(alice.begin(), alice.end()));

    cout << max_num << endl;
}

void solve(){
    // solve_backtracking();

    // solve_permutation_1();
    solve_permutation_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> n;
        cin >> bob;
        cin >> alice;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
