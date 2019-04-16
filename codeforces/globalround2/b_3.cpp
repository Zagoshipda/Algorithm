#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

//input test case
//10 10
//7 2 2 2 2 2 2 2 2 2 

int n, h;   //num of bottles, height of the fridge
int k;  //maximum integer : k bottles in the fridge at the same time 
  
// input: array with input height sequences, num of bottles
// output: if possible to put all num bottles in the fridge return true, else return false
bool fridge(int b[], int num){
    int cnt = 0;
    sort(b+1, b+num+1);   //sorting 하고 앞에서부터 꺼내는 것은 안됨 -> 그냥 큰것부터, 뒤에서부터 꺼내는 것이 오히려 됨;;; 거꾸로 생각했네
    int hleft = h;
    
    // (1 <= b[i] <= h) -> at least one bottle can be put in the fridge
    for(int i=num; i>0; i = i-2){
    // for(int i=num; i>0 && hleft>0; i = i-2){
        if(i == 1){
            if(hleft >= b[i]){
                cnt++;
            }
            break;
        }
        if(hleft < b[i]){
            if(i-1>0 && hleft >= b[i-1]){
                cnt++;
                break;
            }else{
                break;
            }
        }else{
            cnt = cnt+2;
            hleft -= b[i];        
        }
    }
    if(cnt == num){
        return true;
    }else{
        return false;
    }
}


int main(){
	IOS;
    
    cin >> n >> h;

    int a[n+1] = {0, };
    for(int i=1; i<n+1; i++){
        cin >> a[i];
    }
    // input----------------------------------------

    for(int i=1; i<n+1; i++){
        if(fridge(a, i)){    //a, n, h
            k = i;
        }else{
            break;
        }
    }
    
    cout << k;

    return 0;
}

