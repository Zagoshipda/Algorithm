#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long

int t;
int n;

int main(void){
    IOS;

    cin >> t;
    while(t--){
        int k = 0;
        int l1[2] = {0, 0}, l2[2] = {0, 0};

        cin >> n;
        vector<int> a(n);

        int max = 0;
        for(int i=0; i<n; ++i){
            cin >> a[i];
            if(a[i] > max){
                max = a[i];
            }
        }

        // 1st iteration
        bool skip1 = false, skip2 = false;
        vector<bool> temp(max, true); 
        for(int i=0; i<max; ++i){
            if(a[i] <= max && temp[a[i]-1]){
                temp[a[i]-1] = false;
            }
            else{
                skip1 = true;
                break;
            }
        }
        if(!skip1){
            vector<bool> temp2(n-max, true); 
            for(int i=max; i<n; ++i){
                if(a[i] <= n - max && temp2[a[i]-1]){
                    temp2[a[i]-1] = false;
                }
                else{
                    skip2 = true;
                    break;
                }
            }
        }
        if(!skip1 && !skip2){
            k++;
            l1[k-1] = max;
            l2[k-1] = n-max;
        }

        // 2nd iteration
        bool skip3 = false, skip4 = false;
        vector<bool> temp3(n-max, true); 
        for(int i=0; i<n-max; ++i){
            if(a[i] <= n - max && temp3[a[i]-1]){
                temp3[a[i]-1] = false;
            }
            else{
                skip3 = true;
                break;
            }
        }
        if(!skip3){
            vector<bool> temp4(max, true); 
            for(int i=n-max; i<n; ++i){
                if(a[i] <= max && temp4[a[i]-1]){
                    temp4[a[i]-1] = false;
                }
                else{
                    skip4 = true;
                    break;
                }
            }
        }
        if(!skip3 && !skip4){
            k++;
            l1[k-1] = n-max;
            l2[k-1] = max;
        }

        if(k > 0 && max == n-max){
            k--;
        }
        cout << k << endl;
        for(int i=0; i<k; ++i){
            cout << l1[i] << ' ' << l2[i] << endl;
        }
 

    }


    return 0;
}
