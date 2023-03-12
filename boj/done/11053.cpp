#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
INPUT
==============================================================
8
3 5 7 9 2 1 4 8
==============================================================
OUTPUT
5
==============================================================
7
3 2 5 2 3 1 4
3
*/

int N;
int A[1001];
int length[1001];
int lis[1001];
int lis_size;
int max_length = INT_MIN;

void calculate_length_of_longest_increasing_subsequence_n2(){
    length[0] = 1;
    for(int i=1; i<N; ++i){
        for(int j=0; j<i; ++j){
            if(A[j] < A[i]){
                if(length[j] > length[i]){
                    length[i] = length[j];
                }
            }
        }
        if(length[i] > 0){
            length[i] += 1;
        }
        else{
            length[i] = 1;
        }
    }


    for(int i=0; i<N; ++i){
        if(length[i] > max_length){
            max_length = length[i];
        }
    }
}

void calculate_length_of_longest_increasing_subsequence_nlogn(){
    lis[0] = A[0];
    lis_size = 1;
    for(int i=1; i<N; ++i){
        // cout << i << "th" << endl;
        if(lis[lis_size-1] < A[i]){
            lis[lis_size] = A[i];
            ++lis_size;
        }
        else{
            int position = lower_bound(lis, lis+lis_size, A[i]) - lis;
            lis[position] = A[i];
            // cout << "position : " << position << endl;
        }
        // for(int j=0; j<lis_size; ++j){
        //     cout << lis[j] << " ";
        // }
        // cout << endl;
    }

    max_length = lis_size;
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    calculate_length_of_longest_increasing_subsequence_n2();
    // calculate_length_of_longest_increasing_subsequence_nlogn();

    cout << max_length << endl;

    return 0;
}
