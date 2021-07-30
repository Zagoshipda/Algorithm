#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int t;
int n, k;

int main(){
    IOS;

    cin >> t;
    while(t--){
        cin >> n >> k;
        vector<bool> points(2*n+1);
        int x, y;
        vector<pair<int,int>> chords;
        for(int i=0; i<k; ++i){
            cin >> x >> y;
            if(x > y){
                swap(x, y);
            }
            // cout << "x y " <<  x << ' ' << y << endl;
            chords.push_back(make_pair(x, y));
            points[x] = true;
            points[y] = true;
        }

        vector<int> leftover;
        int points_size = points.size();
        for(int i=1; i<points_size; ++i){
            if(!points[i]){
                leftover.push_back(i);
            }
        }

        int leftover_size = leftover.size()/2;  // n-k
        for(int i=0; i<leftover_size; ++i){
            x = leftover[i];
            y = leftover[i+leftover_size];
            if(x > y){
                swap(x, y);
            }
            // cout << "x y " <<  x << ' ' << y << endl;
            chords.push_back(make_pair(x, y));
        }

        int ans = 0;
        pair<int,int> one;
        pair<int,int> two;
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; ++j){
                one = chords[i];
                two = chords[j];
                if(chords[i].first > chords[j].first){
                    swap(one, two);                    
                }
                if(two.first < one.second && one.second < two.second){
                    ++ans;
                }
            }
        }
        cout << ans << endl;

    }

    return 0;
}
