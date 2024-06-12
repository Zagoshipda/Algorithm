/*
    https://www.acmicpc.net/problem/1182
    (sum of subarray/subsequence 1)

    similar problem
        https://www.acmicpc.net/problem/1208
        (sum of subarray/subsequence 2)
        https://www.acmicpc.net/problem/14225
        (sum of subarray)

    solution
        https://www.acmicpc.net/source/24502820
        (minsiwon00, 0 ms)
        https://www.acmicpc.net/source/1042797
        (wkdgudcjf, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 20
#define MAX_TARGET 1'000'000
int N, S;
int arr[SIZE + 1];

int indices[SIZE + 1];
// int target[21];
bool visited[SIZE + 1];
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

void recursive_1(int choice){
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
            recursive_1(choice + 1);
            visited[i] = false;
        }
    }
}

void recursive_2(int nth, int sum){
    if(nth > N){
        if(sum == S){
            ++ans;
        }
        return;
    }

    recursive_2(nth+1, sum + arr[nth]);
    recursive_2(nth+1, sum);
}

void solve(){
    // 492 ms
    // for(int i = 1; i <= N; ++i){
    //     length = i;
    //     recursive_1(1);
    // }

    // 4 ms
    recursive_2(1, 0);
    if(S == 0){
        // NOTE : exclude the case when not taking any element
        --ans;
    }

    cout << ans << endl;
}

void input(){
    cin >> N >> S;

    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        // sum[i] = sum[i-1] + arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
