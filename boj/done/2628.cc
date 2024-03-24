/*
    https://www.acmicpc.net/problem/2628
    (cut the paper)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_LENGTH = 100;

int width, height;
int N;
int a, b;
vector<int> cuts_row = { 0 };
vector<int> cuts_col = { 0 };

void solve(){
    sort(cuts_row.begin(), cuts_row.end(), less<int>());
    sort(cuts_col.begin(), cuts_col.end(), less<int>());
    cuts_row.push_back(height);
    cuts_col.push_back(width);

    int max_width = 0;
    int max_height = 0;
    int len = cuts_col.size();
    for(int idx=1; idx<len; ++idx){
        max_width = max(max_width, cuts_col[idx] - cuts_col[idx-1]);
    }
    len = cuts_row.size();
    for(int idx=1; idx<len; ++idx){
        max_height = max(max_height, cuts_row[idx] - cuts_row[idx-1]);
    }

    cout << max_width * max_height << endl;
}

void input(){
    cin >> width >> height;
    cin >> N;
    for(int i=1; i<=N; ++i){
        cin >> a >> b;
        if(a){
            cuts_col.push_back(b);
        }
        else{
            cuts_row.push_back(b);
        }
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
