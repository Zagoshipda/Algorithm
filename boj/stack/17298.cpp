/*
    https://www.acmicpc.net/problem/17298
    (next greater element)

    similar problem
        https://www.acmicpc.net/problem/2493
        (tower)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

const int ARR_SIZE = 1'000'000; // 10^6
const int MAX_NUM = 1'000'000;  // 10^6

int N;
int arr[ARR_SIZE + 1];
int nge[ARR_SIZE + 1];  // next greater element

void print_nge(){
    for(int ith=0; ith<N; ++ith){
        cout << nge[ith] << " ";
    }
    cout << endl;
}

void calculate_right_bigger_number_forwards(){
    stack<int> stk; // idx
    for(int ith=0; ith<N; ++ith){
        while(!stk.empty()){
            if(arr[stk.top()] < arr[ith]){
                nge[stk.top()] = arr[ith];
                stk.pop();
            }
            else{
                break;
            }
        }
        stk.push(ith);
    }

    while(!stk.empty()){
        nge[stk.top()] = -1;
        stk.pop();
    }

    // int size = stk.size();
    // for(int ith=0; ith<size; ++ith){
    //     nge[stk.top()] = -1;
    //     stk.pop();
    // }

    // for(int ith=0; ith<N; ++ith){
    //     if(nge[ith] <= 0){
    //         nge[ith] = -1;
    //     }
    // }

    print_nge();
}

void calculate_right_bigger_number_backwards(){
    stack<int> stk; // idx
    for(int ith=N-1; ith>=0; --ith){
        while(!stk.empty()){
            if(stk.top() <= arr[ith]){
                stk.pop();
            }
            else{
                break;
            }
        }

        if(stk.empty()){
            nge[ith] = -1;
        }
        else{
            nge[ith] = stk.top();
        }

        stk.push(arr[ith]);
    }

    print_nge();
}

using p_ii = pair<int, int>;

void initialize(){
    for(int ith=0; ith<N; ++ith){
        nge[ith] = -1;
    }
}

void solve_1(){
    initialize();

    stack<p_ii> stk;    // (val, idx)
    for(int ith=0; ith<N; ++ith){
        while(!stk.empty()){
            auto [val, idx] = stk.top();
            if(val < arr[ith]){
                nge[idx] = arr[ith];
                stk.pop();
            }
            else{
                break;
            }
        }
        stk.push({arr[ith], ith});
    }

    print_nge();
}

int main(){
    IOS;

    cin >> N;
    for(int ith=0; ith<N; ++ith){
        cin >> arr[ith];
        // while(!stk.empty()){
        //     if(arr[stk.top()] < arr[ith]){
        //         nge[stk.top()] = arr[ith];
        //         stk.pop();
        //     }
        //     else{
        //         break;
        //     }
        // }
        // stk.push(ith);
    }

    // while(!stk.empty()){
    //     nge[stk.top()] = -1;
    //     stk.pop();
    // }

    // print_nge();

    calculate_right_bigger_number_forwards();

    // calculate_right_bigger_number_backwards();

    // solve_1();

    return 0;
}
