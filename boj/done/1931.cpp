/*
    https://www.acmicpc.net/problem/1931
    (activity selection problem)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

#define MAX_ACTIVITY 100'000
int N;
pair<int, int> activities[MAX_ACTIVITY + 1];

struct cmp_activity{
    bool operator()(const pair<int, int>& activity_1, const pair<int, int>& activity_2){
        // NOTE : start time also matters
        if(activity_1.second == activity_2.second){
            return activity_1.first < activity_2.first;
        }
        else{
            return activity_1.second < activity_2.second;
        }
    }
};

void solve(){
    int cnt = 0;
    sort(activities+1, activities+1+N, cmp_activity());

    int prev_end = 0;
    for(int idx=1; idx<=N; ++idx){
        if(prev_end <= activities[idx].first){
            ++cnt;
            prev_end = activities[idx].second;
        }
    }

    cout << cnt << endl;
}

void input(){
    cin >> N;
    int start, end;
    for(int i=1; i<=N; ++i){
        cin >> start >> end;
        activities[i] = {start, end};
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
