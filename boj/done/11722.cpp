#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int A[1001];
int length[1001];
int lds[1001];
int lds_size;
int max_length;

void calculate_length_of_longeset_decreasing_subsequence_n2(){
    for(int i=0; i<N; ++i){
        length[i] = 1;
        for(int j=0; j<i; ++j){
            if(A[j] > A[i]){
                length[i] = max(length[j] + 1, length[i]);
            }
        }
    }

    for(int i=0; i<N; ++i){
        max_length = max(max_length, length[i]);
    }
}

void calculate_length_of_longeset_decreasing_subsequence_nlogn(){
    lds[0] = A[0];
    lds_size = 1;
    for(int i=1; i<N; ++i){
        if(lds[lds_size-1] < A[i]){
            lds[lds_size] = A[i];
            ++lds_size;
        }
        else{
            int position = lower_bound(lds, lds+lds_size, A[i]) - lds;
            lds[position] = A[i];
        }
    }

    max_length = lds_size;
}

int main(){
    IOS;

    cin >> N;
    // for(int i=0; i<N; ++i){
    //     cin >> A[i];
    // }

    // calculate_length_of_longeset_decreasing_subsequence_n2();

    for(int i=N-1; i>=0; --i){
        cin >> A[i];
    }

    calculate_length_of_longeset_decreasing_subsequence_nlogn();

    cout << max_length << endl;

    return 0;
}
