// by, kmjp

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll n, a[404040];

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i], a[i+n] = a[i]; // 좋은 테크닉 -> 아래 for문을 돌릴때 index 조건검사가 필요없음
    }
    int ret=0, cur=0;
    for(int i=0; i<2*n; i++){   // 역시나 2바퀴 돌리겠다는 뜻. 단, 위에서 배열을 애초에 2배 길이로 정의하고 값또한 초기화했으므로 index overflow가 발생하지 않는다
        if(a[i]) cur++;     // int값 자체를 true/false boolean 조건으로 넣는 것은 역시나 좋은 테크닉. 0이면 false 1이면 true -> 현재 rest가 1이므로 그냥 사용. 만약 rest가 0이었으면 !a[i]로 사용했으면 될듯
        else cur =0;
        ret = max(ret, cur);    //현재값과 새로 증가시킨 값중 더 큰 값으로 매 턴마다 value update
    }
    cout << ret;
}