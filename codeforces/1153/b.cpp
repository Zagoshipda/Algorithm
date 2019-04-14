#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //range : -9*10^18~9*10^18

// int n, a[10], s=1e18; 
// string s;

int main(){
	IOS;

    int n, m, h;    //세로, 가로, 높이 
    cin >> n >> m >> h;

    int a[n+1], b[m+1];
    int c[n+1][m+1] = {0};
    int out[n+1][m+1] = {0};

    for(int i=1; i<m+1; i++){
        cin >> b[i];
    }
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cin >> c[i][j];
        }
    }

    // for(int i=1; i<n+1; i++){
    //     for(int j=1; j<m+1; j++){
    //         cout << c[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(c[i][j]==1){
                out[i][j] = a[i] < b[j] ? a[i] : b[j];
            }
        }
    }

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cout << out[i][j] << ' ';
        }
        cout << endl;
    }



    return 0;
}

