// index 들이 서로소이면 ai != aj 이어야 함
// 그렇다면 서로소가 아니면 같아도 된다는 소리...
// a2=1로 시작했으므로 a_2n들은 모두 1이어도 된다는 뜻 
// 결국 a_2n+1들이 어떻게 될지를 생각해야 함...?


// IDEA: 
// 각 숫자를 소인수분해해서 가장 작은 소인수index와 동일한 값으로 해당 index의 값을 설정하면 됨
// -> 이를 위해 각 소수와 그 배수들마다 1, 2, 3, ... 으로 차례대로 값을 할당하고 (time complexity 조건을 맞추기 위해)값을 할당한 index의 개수가 n-1개가 되면 반복문을 종료하도록 한다

// 전체 원소의 개수를 세는 num 변수를 도입하여 time limit exceeded 해결 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int n;

int main(){
	IOS;

    cin >> n;
    int a[n+1] = {0};
    // n바퀴를 다 돌면 낭비되는 cnt값이 너무 많음... -> num값으로 모든 n-1개의 값들을 설정한 후에는 반복문을 종료하도록 해야 함 -> time limit 극복...!!
    int num = 0;
    for(int cnt=1; cnt<=n; cnt++){
        if(num == n-1){
            break;
        }
        int j = 1;
        for(int i=2; i<=n; i += j){
            if(a[i] == 0){
                a[i] = cnt;
                num++;
                if(j == 1){
                    j = i;
                }
            }
        }
    }

    for(int i=2; i<=n; i++){
        cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}

