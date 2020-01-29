#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n;

int main(){
    IOS;

    cin >> t;
    for(int i=0; i<t; i++){
        
        cin >> n;
        vector<pair<int, int>> arr;
        int a=0, b=0;
        for(int j=0; j<n; j++){
            cin >> a >> b;
            pair<int, int> input = make_pair(a, b);
            arr.push_back(input);
        }
        
        sort(arr.begin(), arr.end());

        bool skip = false;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[j].second > arr[k].second){
                    cout << "NO" << endl;
                    skip = true;
                    break;
                }
            }
            if(skip){
                break;
            }
        }
        if(skip){
            continue;
        }
        cout << "YES" << endl;
        int x = 0, y = 0;
        for(int j=0; j<n; j++){
            int numR = arr[j].first - x;
            int numU = arr[j].second - y;
            // cout << "here" << numR << ' ' << numU << endl;
            for(int k=0; k<numR; k++){
                cout << 'R';
            }
            for(int k=0; k<numU; k++){
                cout << 'U';
            }
            x = arr[j].first;
            y = arr[j].second;
        }
        cout << endl;

    }
    

    return 0;
}
