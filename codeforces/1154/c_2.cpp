#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long; range : -9*10^18~9*10^18

//int : 2 g(10억, 21억...)

int a[4];
int input[4];
int week[7] = {1,2,3,1,3,2,1};
int main(){
	IOS;

    cin >> input[1] >> input[2] >> input[3];
    int num = input[1]+input[2]+input[3];   //<= 21*10^8

    int a[4] = {0, input[1], input[2], input[3]};

    int cnt2 = 0;
    int tempsum = 0;
    if(input[1] >= 3 && input[2] >= 2 && input[3] >= 2){
        int temp[4] = {0};
        while(input[1] >= 3){
            input[1] -= 3;
            temp[1]++;
        }
        while(input[2] >= 2){
            input[2] -= 2;
            temp[2]++;
        }
        while(input[3] >= 2){
            input[3] -= 2;
            temp[3]++;
        }
        sort(temp, temp+4);
        cnt2 = temp[1];
        tempsum = 7*cnt2;
    }
    a[1] -= cnt2*3;
    a[2] -= cnt2*2;
    a[3] -= cnt2*2;

        // for(int k=1; k<4; k++){
        //     cout << a[k] << ' ';
        // }
        // cout << endl;
        // cout << tempsum << endl;

    int cntmax = 0;
    for(int i=0; i<7; i++){
        int b[4] = {0, a[1], a[2], a[3]};
        int cnt = 0;
        for(int j=0; j<num; j++){
            int x = (i+j)%7;    //0~6
            int y = week[x];    //1~3
            if(b[y]<=0){
                break;  
            }else{
                b[y]--;
                cnt++;
            }
        }   
        if(cnt > cntmax){
            cntmax = cnt;
        }
    }
    
    cntmax += tempsum;
    
    cout << cntmax;


    return 0;
}

