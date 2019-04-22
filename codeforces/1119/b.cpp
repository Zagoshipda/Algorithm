#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long;

//문제 잘못이해함... 
//아래와 같이하면 그냥 전체 n개 중 순서를 고려하지 않고, 최대한으로 넣을 수 있는 k개를, 그나마도 잘못된 방법으로 구하게 됨... -> 왜 잘못된 방법인지는 b_3.cpp 참고

int n, h;
int k;  //maximum integer : k bottles in the fridge at the same time 

int main(){
	IOS;

    cin >> n >> h;
    int a[n+1] = {0, };
    
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    sort(a+1, a+n+1);
        // int b[] = {0,3,1,2,4,5,7,9,8,6};    //b[10] = b[0...9]
        // sort(b+1, b+10);
        // for(int i=1; i<10; i++){
        //     cout << b[i] << ' ';
        // }

    // 1 <= a[i] <= h
    int left = h;
    // for i = 1
    k++; //for a[1], at least one bottle can be put in the fridge
    if(left < a[2]){
        goto HERE;
    }else{
        left -= a[2], k++;
    }
    for(int i=3; i<n+1; i = i+2){
        if(left < a[i]){
            break;
        }else{
            k++;
            if(left < a[i+1]){
                break;
            }else{
                left -= a[i+1];
                k++;
            }
        }
    }

    HERE:
    cout << k;

    return 0;
}

