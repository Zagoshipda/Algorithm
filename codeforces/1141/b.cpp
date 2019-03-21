
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int out =0;
    int cnt =0;
    for(int i=0; i<2*n; i++){   //2바퀴 돌리는 것으로 문제해결 
        if(i < n){
            if(arr[i] == 0){
                cnt = 0;
            }else{  //arr[i] == 1
                cnt++;
                if(cnt > out){
                    out = cnt;
                }
            }
        }else{ //i >= n
            if(arr[i-n] == 0){
                cnt = 0;
            }else{  //arr[i] == 1
                cnt++;
                if(cnt > out){
                    out = cnt;
                }
            }
        }
        
    }

    cout << out;

}