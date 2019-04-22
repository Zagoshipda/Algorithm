// by, tourist

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;   //num of rows and columns

int main(){
	IOS;

    cin >> n >> m;
    int A[n+1][m+1]={0}, B[n+1][m+1]={0};

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cin >> A[i][j];
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cin >> B[i][j];
        }
    }
    
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < m+1; j++) {
            if (A[i][j] != B[i][j]) {
                if (i == n || j == m) {
                cout << "No" << '\n';
                return 0;
                }
                A[i][j] ^= 1;
                A[i + 1][j] ^= 1;
                A[i][j + 1] ^= 1;
                A[i + 1][j + 1] ^= 1;
            }
        }
    }
    cout << "Yes" << '\n';


    return 0;
}

