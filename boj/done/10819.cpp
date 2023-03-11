#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

int N;
int arr[9];
int arr_permute[9];
bool visited[9];
int max_value = INT_MIN;

int calculate_value(){
    int value = 0;
    for(int i=0; i<N-1; ++i){
        value += abs(arr_permute[i] - arr_permute[i+1]);
    }
    return value;
}

void calculate_max_value(int order){
    if(order >= N){
        int value = calculate_value();
        if(value > max_value){
            max_value = value;
        }
        return;
    }

    for(int i=0; i<N; ++i){
        if(!visited[i]){
            visited[i] = true;
            arr_permute[order] = arr[i];
            calculate_max_value(order + 1);
            visited[i] = false;
        }
    }
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    calculate_max_value(0);

    cout << max_value << endl;

    return 0;
}
