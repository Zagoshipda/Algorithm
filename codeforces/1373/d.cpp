#include<bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
	IOS;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);       // odd element
        vector<int> preva(n);
        vector<int> b(n);       // even element
        vector<int> prevb(n);
        int start, end;
        int input;
        int ai = 0, bi = 0;    
        for(int i=0; i<n; ++i){
            cin >> input;
            if(i % 2){
                a[ai] = input;
                preva[ai] += a[ai];
                ++ai;
            }
            else{
                b[bi] = input;
                prevb[bi] += b[bi];
                ++bi;
            }
        }
        
        int maxVal = INT_MIN;
        for(int i=0; i<n; ++i){
            for(int j=2; i+j<n; j=j+2){
                int amount = j/2;
                int val1 = preva[amount] - preva[i/2];  // odd sum
                int val2 = prevb[amount] - prevb[i/2];  // even sum
                int diff = val2 - val1;
            }
        }

    }
    
    return 0;
}
