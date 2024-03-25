/*
    https://www.acmicpc.net/problem/1946
    (newbie)

    references
        why lis is NOT a solution
        https://www.acmicpc.net/board/view/1967
        https://www.acmicpc.net/board/view/6763

    similar problem
        https://www.acmicpc.net/problem/2565
        (wire 1)
        https://www.acmicpc.net/problem/1365
        (twisted wire)

    solutions
        https://www.acmicpc.net/source/26449672
        (joony94, 484 ms) : implemented in solve_greedy_vector()

        https://www.acmicpc.net/source/22542936
        (jthis, 392 ms) : implemented in solve_greedy_array()

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    N ~ 10^5
    brute force N^2 ~ 10^10
    test case 20 ~ 10^2
    total ~ 10^12

starting order
    1 4

    2 5

    3 6
    4 2

    5 7
    6 1

    7 3

finishing order
    6 1
    4 2

    7 3
    1 4

    2 5

    3 6

    5 7

1
7
1 4
2 7
3 6
4 5
5 3
6 2
7 1

// 4 (O)
// 6 (X)

*/

const int MAX_NUM = 100'000;    // 10^5
int T;
int N;
int a, b;
// pair<int, int> applicants[MAX_NUM + 1];
vector<pair<int, int> > applicants;

void solve_wrong(){
    sort(applicants.begin(), applicants.end(), less<pair<int, int> >());

    int cnt = N;
    for(int idx=0; idx<N-1; ++idx){
        if(applicants[idx].first < applicants[idx+1].first &&
            applicants[idx].second < applicants[idx+1].second){
            --cnt;
        }
    }
    cout << cnt << endl;
}

void solve_time_exceeded(){
    sort(applicants.begin(), applicants.end(), less<pair<int, int> >());

    for(int idx=1; idx<applicants.size(); ){
        bool is_erased = false;
        for(int jdx=0; jdx<idx; ++jdx){
            // cout << jdx << " " << idx << " " << applicants[jdx].first << "," << applicants[jdx].second << " / " << applicants[idx].first << "," << applicants[idx].second << endl;
            if(applicants[jdx].first < applicants[idx].first &&
                applicants[jdx].second < applicants[idx].second){
                applicants.erase(applicants.begin() + idx);
                is_erased = true;
                break;
            }
        }
        if(!is_erased){
            ++idx;
        }
    }
    cout << applicants.size() << endl;
}

void solve_lis_wrong(){
    sort(applicants.begin(), applicants.end(), greater<pair<int, int> >());

    vector<int> lis;
    lis.push_back(applicants[0].second);
    for(int idx=1; idx<N; ++idx){
        if(lis.back() < applicants[idx].second){
            lis.push_back(applicants[idx].second);
        }
        else{
            auto it = lower_bound(lis.begin(), lis.end(), applicants[idx].second);
            *it = applicants[idx].second;
        }
    }

    cout << lis.size() << endl;
}

void solve_greedy_vector(){
    sort(applicants.begin(), applicants.end(), less<pair<int, int> >());

    int cnt = 0;
    int prev = N + 1;   // NOTE : initialize
    for(auto it=applicants.begin(); it!=applicants.end(); ++it){
        if(it->second < prev){
            prev = it->second;
            ++cnt;
        }
    }
    cout << cnt << endl;
}

// NOTE : sort as the counting sort
int hashes[MAX_NUM + 1];
void solve_greedy_array(){
    int prev = N + 1;
    int cnt = 0;
    for(int idx=1; idx<=N; ++idx){
        if(hashes[idx] < prev){
            prev = hashes[idx];
            ++cnt;
        }
    }
    cout << cnt << endl;
}

void solve(){
    // solve_greedy_vector();

    solve_greedy_array();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        applicants.clear();
        for(int i=1; i<=N; ++i){
            // cin >> applicants[i].first >> applicants[i].second;
            cin >> a >> b;
            applicants.push_back({a, b});
            hashes[a] = b;
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
