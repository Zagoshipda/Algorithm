#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18)

int n, m, k;
int outnum;
string outseq;

int main(){
    IOS;

    cin >> n >> m >> k;

    // actually NO need inputs below.
    pair<int, int> pos1[k];
    pair<int, int> pos2[k];
    int input1, input2;
    for(int i=0; i<k; ++i){
        cin >> input1 >> input2;
        pos1[i] = make_pair(input1, input2);
    }
    for(int i=0; i<k; ++i){
        cin >> input1 >> input2;
        pos2[i] = make_pair(input1, input2);
    }

    outnum += n-1;
    for(int i=1; i<=n-1; ++i){
        outseq += 'U';
    }
    outnum += m-1;
    for(int i=1; i<=m-1; ++i){
        outseq += 'L';
    }
    for(int i=0; i<=n-1; ++i){
        outnum += m-1;
        if(i % 2 == 0){
            for(int j=1; j<=m-1; ++j){
                outseq += 'R';
            }
        }
        else{
            for(int j=1; j<=m-1; ++j){
                outseq += 'L';
            }
        }
        if(i < n-1){
            outnum += 1;
            outseq += 'D';
        }
    }

    cout << outnum << endl;
    cout << outseq << endl;


    return 0;
}
