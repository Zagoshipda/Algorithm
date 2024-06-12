/*
    https://www.acmicpc.net/problem/3163
    (falling ants)
*/

#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
// int 4 G(십억) : -2*10^9 ~ 2*10^9

// idea: 매 step마다 한 칸씩 움직이는 것으로 하고 서로 지나치는 경우 우선 한 칸씩 진행시킨 다음에 pi ai 값을 서로 바꾸어주는 작업을 하고 이후 마지막에 다다른 개미가 있다면 서로 값을 비교해서 더 작은 ai값을 가진 개미부터 꺼내고 이때 k와 일치하는 순서의 개미의 ai를 print 하도록 하면 되...려나?


int T;
int N, L, K;

int main(void){
    IOS;

    cin >> T;
    for(int i=0; i<T; i++){
        cin >> N >> L >> K;

        int p[N] = {0}; // position
        int a[N] = {0}; // id
        for(int j=0; j<N; j++){
            cin >> p[j] >> a[j];
        }
        for(int j=0; j<N; j++){
            if(a[j]>0 && a[j+1]<0){
                for(int k=0; k<=j; k++){
                    a[k] *= (-1) * a[k];
                }
            }
        }


    }




    return 0;
}