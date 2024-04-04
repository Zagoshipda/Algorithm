/*
    https://www.acmicpc.net/problem/28449
    (who wins)

    solutions
        https://www.acmicpc.net/source/65012325
        (jhuni, 36 ms) : equal_range(), implemented in solve_binary_search_2()

        https://www.acmicpc.net/source/65405702
        (cheetose, 32 ms) : conting sort, implemented in solve_counting_sort()

        https://www.acmicpc.net/source/65011981
        (edenooo, 32 ms) : two pointer, implemented in solve_two_pointer()
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    NOTE : N * M matches ~ 10^10
        => int range fails...
*/

const int NUM_TEAM = 100'000;   // 10^5
const int MAX_NUM = 100'000;    // 10^5
int N, M;
int team_1[NUM_TEAM + 1];
int team_2[NUM_TEAM + 1];

// int wins, losses, draws;    // WRONG
ll wins, losses, draws;     // AC

void print_answer(){
    cout << wins << " " << losses << " " << draws << endl;
}

void solve_binary_search_1(){
    sort(team_1+1, team_1+1+N, less<int>());
    sort(team_2+1, team_2+1+M, less<int>());

    for(int idx=1; idx<=N; ++idx){
        int val = team_1[idx];
        ll left = lower_bound(team_2+1, team_2+1+M, val) - team_2;
        ll right = upper_bound(team_2+1, team_2+1+M, val) - team_2;
        // NOTE : sums up to M (1...M elements in team_2 array)
        wins += (left - 1);
        draws += (right - left);
        losses += (M - right + 1);
    }

    print_answer();
}

void solve_binary_search_2(){
    sort(team_1+1, team_1+1+N, less<int>());
    sort(team_2+1, team_2+1+M, less<int>());

    for(int idx=1; idx<=N; ++idx){
        auto [it_1, it_2] = equal_range(team_2+1, team_2+1+M, team_1[idx]);
        ll left = it_1 - team_2;
        ll right = it_2 - team_2;
        wins += (left - 1);
        draws += (right - left);
        losses += (M - right + 1);
    }

    print_answer();
}

// NOTE : since number range ~ 10^5 not so big, can use counting sort
int counting[MAX_NUM + 1];
void solve_counting_sort(){
    for(int idx=1; idx<=M; ++idx){
        ++counting[team_2[idx]];
    }
    // prefix sum
    for(int idx=1; idx<=MAX_NUM; ++idx){
        counting[idx] += counting[idx-1];
    }

    for(int idx=1; idx<=N; ++idx){
        wins += counting[team_1[idx]-1];
        draws += counting[team_1[idx]] - counting[team_1[idx]-1];
        losses += counting[MAX_NUM] - counting[team_1[idx]];
        // losses += M - counting[team_1[idx]];
    }

    print_answer();
}

void solve_two_pointer(){
    sort(team_1+1, team_1+1+N, less<int>());
    sort(team_2+1, team_2+1+M, less<int>());

    // NOTE : left, right pointers always increase or stay the same (never decrease)
    int left=1, right=1;
    for(int idx=1; idx<=N; ++idx){
        while(left <= M && team_2[left] < team_1[idx]){
            ++left;
        }
        while(right <= M && team_2[right] <= team_1[idx]){
            ++right;
        }
        // cout << left << " " << right << endl;

        wins += left - 1;
        draws += right - left;
        losses += M - right + 1;
    }

    print_answer();
}

void solve(){
    // solve_binary_search_1();
    // solve_binary_search_2();

    // solve_counting_sort();

    solve_two_pointer();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> team_1[i];
    }
    for(int i=1; i<=M; ++i){
        cin >> team_2[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
