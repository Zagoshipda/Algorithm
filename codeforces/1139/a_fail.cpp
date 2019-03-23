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
        // cout << input;
        // cout << input.at(0) << ' ' << input.at(1);
    int arr[n];
        // cout << input.at(0) << '\n';
        // cout << typeid(input.at(0)).name();
        // char c = 'a';
        // cout << typeid(c).name();
            // cout << atoi(input.at(0).c_str()) << '\n';  
    for(int i=0; i<n; i++){
        // cout << input.at(i) << ' ';
        // int a = (int)(input.at(i))-48;
        // cout << a << '\n';
        arr[i] = input.at(i)-48;
    }
        // for(int i=0; i<n; i++){
        //     cout << arr[i] << ' ';
        // }

    int cnt =0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int a = 10*arr[i]+arr[j];
            if(a % 2 == 0){
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}