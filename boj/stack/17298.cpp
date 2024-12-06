/*
    https://cocoon1787.tistory.com/347
    https://gamedoridori.tistory.com/76
    https://velog.io/@wxxhyeong/%EB%B0%B1%EC%A4%80-17298.-%EC%98%A4%ED%81%B0%EC%88%98
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 1'000'001
int N;
int arr[SIZE];
int nge[SIZE];

stack<int> stk;

void print_nge(){
    for(int i=0; i<N; ++i){
        cout << nge[i] << " ";
    }
    cout << endl;
}

void calculate_right_bigger_number_forwards(){
    for(int i=0; i<N; ++i){
        while(!stk.empty()){
            if(arr[stk.top()] < arr[i]){
                nge[stk.top()] = arr[i];
                stk.pop();
            }
            else{
                break;
            }
        }
        stk.push(i);
    }

    while(!stk.empty()){
        nge[stk.top()] = -1;
        stk.pop();
    }

    // int size = stk.size();
    // for(int i=0; i<size; ++i){
    //     nge[stk.top()] = -1;
    //     stk.pop();
    // }

    // for(int i=0; i<N; ++i){
    //     if(nge[i] <= 0){
    //         nge[i] = -1;
    //     }
    // }

    print_nge();
}

void calculate_right_bigger_number_backwards(){
    for(int i=N-1; i>=0; --i){
        while(!stk.empty()){
            if(stk.top() <= arr[i]){
                stk.pop();
            }
            else{
                break;
            }
        }

        if(stk.empty()){
            nge[i] = -1;
        }
        else{
            nge[i] = stk.top();
        }

        stk.push(arr[i]);
    }

    print_nge();
}

int main(){
    IOS;

    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
        // while(!stk.empty()){
        //     if(arr[stk.top()] < arr[i]){
        //         nge[stk.top()] = arr[i];
        //         stk.pop();
        //     }
        //     else{
        //         break;
        //     }
        // }
        // stk.push(i);
    }

    // while(!stk.empty()){
    //     nge[stk.top()] = -1;
    //     stk.pop();
    // }

    // print_nge();

    // calculate_right_bigger_number_forwards();

    calculate_right_bigger_number_backwards();

    return 0;
}
