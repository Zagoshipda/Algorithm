/*
    https://www.acmicpc.net/problem/2605
    (line up)

    solutions
        https://www.acmicpc.net/source/342068
        (annemeier, 0 ms) : array implementation
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 100;

int N;
int numbers[MAX_NUM + 1];
void solve(){
    vector<int> students;
    for(int i=1; i<=N; ++i){
        students.push_back(i);
    }

    for(int idx=1; idx<=N; ++idx){
        for(int jdx=idx-1, cnt=1; cnt<=numbers[idx]; ++cnt, --jdx){
            swap(students[jdx-1], students[jdx]);
        }
    }

    for(int student : students){
        cout << student << " ";
    }
    cout << endl;
}

void input(){
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> numbers[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
