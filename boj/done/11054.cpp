#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int A[1001];
int A_reversed[1001];
int left_length[1001];
int right_length[1001];
int max_length;

void calculate_length_of_longest_bitonic_subsequence(){
    for(int center=0; center<N; ++center){
        int max_left = 0;
        int max_right = 0;

        for(int left=0; left<=center; ++left){
            left_length[left] = 1;
            for(int j=0; j<left; ++j){
                if(A[j] < A[left]){
                    left_length[left] = max(left_length[j] + 1, left_length[left]);
                }
            }
        }

        for(int right=0; right<=N-1-center; ++right){
            right_length[right] = 1;
            for(int j=0; j<right; ++j){
                if(A_reversed[j] < A_reversed[right]){
                    right_length[right] = max(right_length[j] + 1, right_length[right]);
                }
            }
        }

        for(int i=0; i<=center; ++i){
            max_left = max(max_left, left_length[i]);
            // cout << left_length[i] << " ";
        }
        // cout << endl;

        for(int i=0; i<=N-1-center; ++i){
            max_right = max(max_right, right_length[i]);
            // cout << right_length[i] << " ";
        }
        // cout << endl;

        max_length = max(max_length, max_left + max_right - 1);
    }
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> A[i];
    }
    for(int i=N-1, j=0; i>=0; --i, ++j){
        A_reversed[i] = A[j];
    }

    calculate_length_of_longest_bitonic_subsequence();

    cout << max_length << endl;

    return 0;
}
