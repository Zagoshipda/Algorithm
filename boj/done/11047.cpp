#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100'000'001
int N, K;
int A[10];
int cnt;

int main(){
    IOS;

    cin >> N >> K;
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    for(int i=N-1; i>=0; --i){
        while(K >= A[i]){
            K -= A[i];
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
