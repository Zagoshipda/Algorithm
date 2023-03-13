#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18



/*
6
10 20 10 30 20 50

10
1 100 2 50 60 3 5 6 7 8

*/


int N;
int A[1001];
int length[1001];
int sum[1001];
int max_length;
int max_sum;

void calculate_longest_increasing_subsequence_with_largest_sum(){
    for(int i=0; i<N; ++i){
        length[i] = 1;
        sum[i] = A[i];
        int value = 0;
        for(int j=0; j<i; ++j){
            if(A[j] < A[i]){
                if(length[j] + 1 > length[i]){
                    length[i] = length[j] + 1;
                    value = max(value, sum[j]);
                }
            }
        }
        sum[i] += value;
    }

    for(int i=0; i<N; ++i){
        // cout << sum[i] << " ";
        max_sum = max(max_sum, sum[i]);
    }
    // cout << endl;
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }

    calculate_longest_increasing_subsequence_with_largest_sum();

    cout << max_sum << endl;

    return 0;
}
