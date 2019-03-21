#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int cnt=0;

    int out=0;
    int ones=0;
    int bef=1;
    int in;
    int first;
    while(cnt < n+1){
        if(cnt == n){
            in = first;
        }else{
            cin >> in;
            if(cnt == 0){
                first = in;
            }
        }
        if(in == 0){
            bef = in;
            ones = 0;
            continue;
        }else{  //in == 1
            if(bef == 1){
                ones++;
                bef = in;
                if(ones > out){
                    out = ones;
                }
            }
        }
        cnt++;
    }

    cout << out;
}