//templates for codeforces...

#include<bits/stdc++.h>
#include <typeinfo>
using namespace std;

#define ll long long

// ll n, a[10], b[10]= {5,3,1,6,2, 9,8,7,4,0}, ans, s=1e18; 

int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); 
	cout.tie(0);
    
    cin >> n;
    string input;
    cin >> input;
    int arr[n];
        
    for(int i=0; i<n; i++){
        arr[i] = input.at(i)-48;
    }

    int cnt =0;
    for(int i=0; i<n; i++){
        if(arr[i] %2 == 0){
            cnt += i+1;
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=i; j<n; j++){
    //         if(arr[j])
    //         int a = 10*arr[i]+arr[j];
    //         if(a % 2 == 0){
    //             cnt++;
    //         }
    //     }
    // }

    cout << cnt;
    return 0;
}