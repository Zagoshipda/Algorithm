#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    //using ll = long long;

// 전략: 앞에서부터 하나씩 넣어서 더 이상 넣을 수 없을 때까지 하기 
// --> 이것도 전략이 틀림... 가장 높이가 작은 것들을 먼저 고려하였는데, 사실 따지고 보면 가장 높이가 큰 것들을 먼저 고려하는 것이 k의 최댓값을 구할 수 있는 방법임

bool fridge(int b[], int n, int h){
    int k = 0;
    sort(b+1, b+n+1);
    int hleft = h;
            // 1 <= b[i] <= h
    k++;    // i = 1, for b[1], at least one bottle can be put in the fridge
    if(n >= 2){
        if(hleft < b[2]){
            goto HERE;
        }else{
            hleft -= b[2], k++;
        }
    }
    for(int i=3; i<n+1; i = i+2){
        if(hleft < b[i]){
            break;
        }else{
            k++;
            if(n >= i+1 && hleft >= b[i+1]){
                hleft -= b[i+1];
                k++;
            }else{
                break;
            }            
        }
    }
    HERE:
    if(k == n){
        return true;
    }else{
        return false;
    }
}


int main(){
	IOS;
    
    int n, h;   //num of bottles, height of the fridge
    int k;  //maximum integer : k bottles in the fridge at the same time 
    cin >> n >> h;

    int a[n+1] = {0, };
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    // input----------------------------------------

    for(int i=1; i<n+1; i++){
        if(fridge(a, i, h)){    //a, n, h
            k = i;
        }else{
            break;
        }
    }
    
    cout << k;

    return 0;
}

