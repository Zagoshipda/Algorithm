/*
    https://www.acmicpc.net/problem/13904
    (assignment)

    solutions
        https://www.acmicpc.net/source/69928467
        (using sort) implemented bewlow (solve_array)

        https://www.acmicpc.net/source/18659299
        (using sort & priority queue) implemented below (solve_pq)

        https://www.acmicpc.net/source/30906395
        https://www.acmicpc.net/source/29571392
        (without any sort or priority queue or visited flag) implemented below (solve_naive)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define NUM_N 1'000
#define RANGE_DAY 1'000
#define RANGE_SCORE 100
int N;
int d, w;
int max_score = 0;
int max_deadline = 0;
pair<int, int> task[NUM_N + 1]; // (deadline, score)

// sort by score first, deadline second, in an ascending order
struct cmp_ascending_score{
    bool operator()(const pair<int, int>& task_1, const pair<int, int>& task_2){
        if(task_1.second == task_2.second){
            return task_1.first < task_2.first;
        }
        else{
            return task_1.second < task_2.second;
        }
    }
};

const int INITIAL_VALUE = 0;
// int scores[RANGE_DAY + 1];
bool visited[RANGE_DAY + 1];
void solve_array(){
    sort(task+1, task+1+N, cmp_ascending_score());

    for(int idx=N; idx>=1; --idx){
        int current_deadline = task[idx].first;
        int current_score = task[idx].second;
        for(int pos=current_deadline; pos>=1; --pos){
            // if(scores[pos] <= INITIAL_VALUE){
            //     scores[pos] = current_score;
            //     break;
            // }
            if(!visited[pos]){
                max_score += current_score;
                visited[pos] = true;
                break;
            }
        }
    }

    // for(int i=1; i<=max_deadline; ++i){
    //     max_score += scores[i];
    // }
    cout << max_score << endl;
}

priority_queue<int, vector<int>, less<int> > pq_max;
void solve_pq(){
    sort(task+1, task+1+N, less<pair<int, int> >());

    for(int deadline=max_deadline, idx=N; deadline>=1; --deadline){
        while(task[idx].first>=deadline && idx>=1){
            pq_max.push(task[idx].second);
            --idx;
        }
        if(!pq_max.empty()){
            max_score += pq_max.top();
            pq_max.pop();
        }
    }

    cout << max_score << endl;
}

void solve_naive(){
    for(int deadline=max_deadline; deadline>=1; --deadline){
        int score = 0;
        int pos = 0;
        for(int idx=1; idx<=N; ++idx){
            // if(task[idx].first >= deadline && !visited[idx]){
            if(task[idx].first >= deadline){
                if(task[idx].second > score){
                    score = task[idx].second;
                    pos = idx;
                }
            }
        }
        // if(score > 0){
            max_score += score;
            task[pos].first = 0;    // remove deadline record
            // task[pos].second = 0;    //remove score record
            // visited[pos] = true;
        // }
    }

    cout << max_score << endl;
}

void solve(){
    // solve_array();

    // solve_pq();

    solve_naive();
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> d >> w;
        task[i] = {d, w};
        max_deadline = max(max_deadline, d);
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
