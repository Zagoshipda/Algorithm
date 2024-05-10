/*
    https://www.acmicpc.net/problem/2003
    (sum of numbers 2)

    similar problem
        https://www.acmicpc.net/problem/2015
        (sum of numbers 4)
        ttps://www.acmicpc.net/problem/19566
        (segment mean)

    solution
        https://www.acmicpc.net/source/12142361
        (ydk1104, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - # of subarray sum == M
        - all numbers are positive integers
            => can use two pointers algorithm

    Algorithm
        time limit ~ 0.5s

        N ~ 10^4
        N^2 ~ 10^8 <= 0.5s
*/

const int ARR_SIZE = 10'000;    // 10^4
const int MAX_NUM = 30'000;     // 3 * 10^4
const int MAX_TARGET = ARR_SIZE * MAX_NUM;  // 300'000'000 = 3 * 10^8
int N, M;
// NOTE : array size large enough for ERROR in solve_1()
// int arr[ARR_SIZE + 1];
int arr[ARR_SIZE + 2];
int prefix_sum[ARR_SIZE + 1];

void solve_brute_force(){
    int cnt = 0;
    for(int idx=1; idx<=N; ++idx){
        for(int jdx=idx; jdx<=N; ++jdx){
            int sum = 0;
            for(int pos=idx; pos<=jdx; ++pos){
                sum += arr[pos];
            }
            if(sum == M){
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}

void solve_prefix_sum(){
    int cnt = 0;
    for(int start=1; start<=N; ++start){
        for(int end=start; end<=N; ++end){
            if(prefix_sum[end] - prefix_sum[start-1] == M){
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}

int array_sum;
void solve_1(){
    int cnt = 0;
    bool toggle = true;
    int start=0, end=0;
    while(true){    // start<=N && end<=N
        if(toggle){
            ++start;
            ++end;
            if(start > N){
                break;
            }
            array_sum += arr[end];
            while(end<=N){
                // cout << start << " " << end << " " << array_sum << endl;
                if(array_sum == M){
                    ++cnt;
                }
                ++end;
                // ERROR : N < end
                array_sum += arr[end];
            }
            --end;
            toggle = !toggle;
        }
        else{
            array_sum -= arr[start];
            ++start;
            if(start > N){
                break;
            }
            while(start<=end){
                // cout << start << " " << end << " " << array_sum << endl;
                if(array_sum == M){
                    ++cnt;
                }
                array_sum -= arr[end];
                --end;
            }
            ++end;
            toggle = !toggle;
        }
    }

    cout << cnt << endl;
}

void solve_2(){
    int cnt = 0;
    int sum = 0;
    for(int start=1, end=N; start<=N; ++start){
        for(int pos=start; pos<=end; ++pos){
            sum += arr[pos];
            if(sum == M){
                ++cnt;
            }
        }

        sum -= arr[start];
        ++start;

        for(int pos=end; pos>=start; --pos){
            if(sum == M){
                ++cnt;
            }
            sum -= arr[pos];
        }
    }
    cout << cnt << endl;
}

void solve_two_pointer_1(){
    int cnt = 0;
    int left = 1;
    for(int right=1; left<=right && right<=N+1; ){
        // cout << left << " " << right << " " << array_sum << endl;
        if(array_sum == M){
            ++cnt;
            array_sum -= arr[left];
            ++left;
        }
        else if(array_sum > M){
            array_sum -= arr[left];
            ++left;
        }
        else if(array_sum < M){
            array_sum += arr[right];
            ++right;
        }
        else{
            // ERROR
        }
    }
    cout << cnt << endl;
}

void solve_two_pointer_2(){
    int cnt = 0;
    int sum = 0;
    for(int left=1, right=1; right<=N+1; ){
        if(sum < M){
            sum += arr[right];
            ++right;
        }
        else if(sum > M){
            sum -= arr[left];
            ++left;
        }
        else{
            ++cnt;
            sum -= arr[left];
            ++left;
        }
    }
    cout << cnt << endl;
}

// TOO MUCH
void solve_segment_tree(){

}

void solve(){
    // solve_brute_force();    // time exceeded

    // solve_prefix_sum();     // 36 ms

    // solve_1();  // 40 ms
    // solve_2();  // 40 ms
    // solve_two_pointer_1();  // 0 ms
    solve_two_pointer_2();

    // solve_segment_tree();
}

void input(){
    cin >> N >> M;
    for(int i=1; i<=N; ++i){
        cin >> arr[i];
        // array_sum += arr[i];
        // prefix_sum[i] = prefix_sum[i-1] + arr[i];
    }
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
