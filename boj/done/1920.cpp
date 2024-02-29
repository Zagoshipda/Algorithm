/*
    https://www.acmicpc.net/problem/1920
    (finding a number)

    references
        https://www.acmicpc.net/source/27238589
        (gnues, 20 ms) : using lower_bound(), essentially the same implementation as binary_search()
        https://blockdmask.tistory.com/167

        https://www.acmicpc.net/source/16988473
        (moonyy7012, 48 ms)

    test case
        https://www.acmicpc.net/board/view/86485    (off by one error)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 100'000
int N;
int arr[SIZE];
int M;
int num;

// binary search target among elements in arr, of range [start, end)
// bool binary_search_recursive_1(int* arr, int start, int end, int target){
bool binary_search_recursive_1(int arr[], int start, int end, int target){
    if(start + 1 >= end){
        return arr[start] == target;
    }
    else{
        int middle = (start + end) / 2;
        if(arr[middle] == target){
            return true;
        }
        else if(arr[middle] < target){
            return binary_search_recursive_1(arr, middle, end, target);
        }
        else /*if(target <= arr[middle])*/ {
            return binary_search_recursive_1(arr, start, middle, target);
        }
    }
}

bool binary_search_iterative_1(int arr[], int a, int b, int target){
    int start = a;
    int end = b;
    bool ans = false;
    while(true){
        if(start > end){
            break;
        }
        int middle = (start + end) / 2;
        if(arr[middle] == target){
            ans = true;
            break;
        }
        else if(arr[middle] < target){
            start = middle + 1;
        }
        else /*if(target < arr[middle])*/ {
            end = middle - 1;
        }
    }
    return ans;
}

bool binary_search_iterative_2(int arr[], int a, int b, int target){
    int start = a;
    int end = b;
    bool ans = false;
    while(true){
        if(start >= end){
            break;
        }
        int middle = (start + end) / 2;
        if(arr[middle] == target){
            ans = true;
            break;
        }
        else if(arr[middle] < target){
            start = middle + 1;
        }
        else /*if(target < arr[middle])*/ {
            // end = middle - 1;    // wrong answer
            end = middle;
        }
    }
    return ans;
}

void binary_search_iterative_3(){
    // NOTE : set loop invariant as (start <= end)
    for(int start=0, end=N-1; 0<=start && start<=end && end<N; ){
        // cout << " " << start << " " << end << endl;
        int pos = (start + end) >> 1;
        if(arr[pos] == num){
            cout << 1 << endl;
            return;
        }
        else if(arr[pos] < num){
            start = pos + 1;
        }
        else if(num < arr[pos]){
            end = pos - 1;
        }
    }

    cout << 0 << endl;
}

void binary_search_recursive_2(int left, int right){
    // when loop invariant condition fails
    if(right < left){
        cout << 0 << endl;
        return;
    }

    int pos = (left + right) >> 1;
    if(arr[pos] == num){
        cout << 1 << endl;
        return;
    }
    else if(arr[pos] < num){
        binary_search_recursive_2(pos+1, right);
    }
    else if(num < arr[pos]){
        binary_search_recursive_2(left, pos-1);
    }
}

void solve(){
    // int is_exist = binary_search(arr, arr+N, num);

    // int is_exist = binary_search_recursive_1(arr, 0, N, num);
    // int is_exist = binary_search_iterative_1(arr, 0, N-1, num);
    // int is_exist = binary_search_iterative_2(arr, 0, N, num);

    // cout << is_exist << endl;

    // binary_search_iterative_3();
    binary_search_recursive_2(0, N-1);

    // auto res = lower_bound(arr, arr+N, num);
    // cout << ((res-arr < N) && (*res == num)) << endl;

    // cout << "pos : " << res-arr << " / value : " << *res << endl;
    // cout << "end position : " << end(arr) - arr << endl;
    // cout << (res == end(arr)) << endl;
    // cout << ((res != end(arr)) && (*res == num)) << endl;   // wrong answer
}

void input(){
    cin >> N;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    cin >> M;
    for(int i=0; i<M; ++i){
        cin >> num;

        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
