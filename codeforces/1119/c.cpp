// by, tourist

#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

// 이러한 꼴의 matrix 문제는 매우 많이 나오는 유형인 것 같은데 아직도 그 해답을 스스로의 머가리로는 못찾겠다 ;;; 

/* solution: 먼저 A와 B에서 값이 다른 부분들의 위치를 찾는다. 
(1) 그리고 해당하는 위치들이 i ...i+k  
                           j ...j+k 꼴인지를 확인하고, 
(2)각 위치의 값들이 reverse(0-1) 인 관계인지를 확인한다 ...?
-> 이 과정을 recursive 하게 진행하면 될듯 
언제까지? 만약 진행하다가 서로 다른 값을 가지는 부분이 4개 미만(3개 이하)로 떨어진다면 불가능한 transformation 이 될 것이다. 
혹은 4개 이상 다른 부분들이 있더라도 위 (1) 과 (2)의 관계를 만족하는 pair 가 더 이상 존재하지 않는다면 역시나 불가능한 transformation임을 알 수 있다.

가능한 transformation은 위 (1), (2)를 사용한 결과, A가 B로 완벽하게 변환되는 경우만 가능할 것이라 생각할 수 있다.

print Yes or No 
*/


int n, m;   //num of rows and columns

int main(){
	IOS;

        // int a =1, b =0;
        // a ^= 1, b ^=1;
        // int c = a^b;
        // cout << a << ' '<< b << ' ' << c;   // 0 1, bitwise xor 
        // int n = 1;
        // int m = 1;
        // cout << (n^m);  //10

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

