#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N, S;
int arr[21];
int indices[21];
// int target[21];
bool visited[21];
// int sum[21];
int length;
int ans;

// consecutive partial sum.
// void calculate_consecutive_partial_sum(){
//     for(int length=1; length<=N; ++length){
//         int val = sum[length];
//         for(int start=1; start<=N-length+1; ++start){
//             if(val == S){
//                 ++ans;
//             }
//             val -= arr[start];
//             int end = start+length;
//             if(end <= N){
//                 val += arr[end];
//             }
//         }
//     }
// }

void calculate_partial_sum(int choice){
    if(choice > length){
        int sum = 0;
        for(int i=1; i<=length; ++i){
            sum += arr[indices[i]];
            // sum += target[i];
            // cout << indices[i] << " ";
            // cout << target[i] << " ";
        }
        // cout << endl;
        if(sum == S){
            ++ans;
        }

        return;
    }

    for(int i=1; i<=N; ++i){
        if(!visited[i] && indices[choice-1] < i){
            visited[i] = true;
            indices[choice] = i;
            // target[choice] = arr[i];
            calculate_partial_sum(choice + 1);
            visited[i] = false;
        }
    }
}

int main(){
    IOS;

    cin >> N >> S;

    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        // sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 1; i <= N; ++i){
        length = i;
        calculate_partial_sum(1);
    }

    cout << ans << endl;
    return 0;
}
