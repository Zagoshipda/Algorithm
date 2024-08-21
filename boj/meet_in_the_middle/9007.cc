/*
    https://www.acmicpc.net/problem/9007
    (canoe racer)

    solution
        implemented in solve_binary_search_1()
            https://www.acmicpc.net/source/77277396
            (gazebo1, 1972 ms) : vector<>.erase() + unique() + lower_bound()
            https://www.acmicpc.net/source/11965970
            (3587jjh, 1608 ms) : lower_bound()
            https://www.acmicpc.net/source/18229469
            (palilo, 1424 ms)

        implemented in solve_binary_search_2()
            https://www.acmicpc.net/source/642436
            (rkd628, 728 ms) : only sorting one sum vector<> + early stopping
            https://www.acmicpc.net/source/10095784
            (donghy9508, 1976 ms)
            https://www.acmicpc.net/source/4374547
            (danmuzi, 1892 ms)

        two pointer
            implemented in solve_two_pointer_2()
                https://www.acmicpc.net/source/68334394
                (sunghyeck17, 1444 ms)
                https://www.acmicpc.net/source/898408
                (dotorya, 1548 ms)
                https://www.acmicpc.net/source/79530953
                (gozipwang, 1132 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - best performance when the total weight of racers is "closest" to a specific value
        - the "smaller" sum is preferred for the canoe game


1
32 2
2 5
9 4
10 20
4 2

// 31 (O)
// 33 (X)
// 30 (X)

1
1000 1
1
1
5
5

// 12 (O)
// 0  (X)

1
1 1
5
5
1
1

// 12

1
300 4
60 52 80 40
75 68 88 63
48 93 48 54
56 73 49 75

// 297 (X)
// 301 (O)

*/

const int NUM_CLASS = 4;
const int ARR_SIZE = 1'000;     // 10^3
const int MAX_NUM = 10'000'000; // 10^7
const int MAX_TARGET = 40'000'000;  // 4 * 10^7

int T;
int k, n;
int arr[NUM_CLASS + 1][ARR_SIZE + 1];

int min_diff;
int min_sum;

void initialize(){
    min_diff = INT_MAX;
    min_sum = INT_MAX;
}

void update(int val_1, int val_2, int target){
    int curr_diff = abs(val_2 - target);
    if(curr_diff < min_diff || (curr_diff == min_diff && val_1 + val_2 < min_sum)){
        min_diff = curr_diff;
        min_sum = val_1 + val_2;
    }
}

void solve_binary_search_1(){
    vector<int> sum_1;
    vector<int> sum_2;

    for(int idx=1; idx<=n; ++idx){
        for(int jdx=1; jdx<=n; ++jdx){
            sum_1.push_back(arr[1][idx] + arr[2][jdx]);
            sum_2.push_back(arr[3][idx] + arr[4][jdx]);
        }
    }

    // sort(sum_1.begin(), sum_1.end(), less<int>());
    sort(sum_2.begin(), sum_2.end(), less<int>());

    for(int val_1 : sum_1){
        int target = k - val_1;
        int val_2;
        // front & back
        // val_2 = sum_2.back();
        // update(val_1, val_2, target);

        // val_2 = sum_2.front();
        // update(val_1, val_2, target);

        // middle : check for both values beside the boundary
        // auto it = lower_bound(sum_2.begin(), sum_2.end(), target);      // 772 ms
        auto it = upper_bound(sum_2.begin(), sum_2.end(), target);      // 768 ms
        if(it != sum_2.end()){
            val_2 = *it;
            update(val_1, val_2, target);
        }
        if(it != sum_2.begin()){
            val_2 = *(it - 1);
            update(val_1, val_2, target);
        }

        // auto jt = upper_bound(sum_2.begin(), sum_2.end(), target);
        // if(it + 1 < jt){
        //     if(jt != sum_2.end()){
        //         val_2 = *jt;
        //         update(val_1, val_2, target);
        //     }
        //     // if(jt != sum_2.begin()){
        //     //     val_2 = *(jt - 1);
        //     //     update(val_1, val_2, target);
        //     // }
        // }
        if(min_sum == k){
            break;
        }
    }

    cout << min_sum << endl;
}

void solve_binary_search_2(){
    vector<int> sum_1;
    vector<int> sum_2;

    for(int idx=1; idx<=n; ++idx){
        for(int jdx=1; jdx<=n; ++jdx){
            sum_1.push_back(arr[1][idx] + arr[2][jdx]);
            sum_2.push_back(arr[3][idx] + arr[4][jdx]);
        }
    }

    // NOTE : 788 ms for not sorting sum_1 vector<>
    // sort(sum_1.begin(), sum_1.end(), less<int>());
    sort(sum_2.begin(), sum_2.end(), less<int>());

    int len = sum_2.size();
    for(int val_1 : sum_1){
        for(int left=0, right=len-1; left<=right; ){
            int middle = (left + right) >> 1;
            int sum = val_1 + sum_2[middle];
            int diff = abs(sum - k);

            if(sum < k){
                if(diff < min_diff){
                    min_diff = diff;
                    min_sum = sum;
                }
                else if(diff == min_diff){
                    min_sum = min(min_sum, sum);
                }

                left = middle + 1;
            }
            else if(sum > k){
                if(diff < min_diff){
                    min_diff = diff;
                    min_sum = sum;
                }
                else if(diff == min_diff){
                    min_sum = min(min_sum, sum);
                }

                right = middle - 1;
            }
            else{
                min_diff = diff;    // == 0
                min_sum = k;
                break;
            }
        }
        // early stopping
        if(min_sum == k){
            break;
        }
    }

    cout << min_sum << endl;
}

void solve_two_pointer_1(){
    vector<int> sum_1;
    vector<int> sum_2;

    for(int idx=1; idx<=n; ++idx){
        for(int jdx=1; jdx<=n; ++jdx){
            sum_1.push_back(arr[1][idx] + arr[2][jdx]);
            sum_2.push_back(arr[3][idx] + arr[4][jdx]);
        }
    }

    // sort(sum_1.begin(), sum_1.end(), less<int>());
    sort(sum_2.begin(), sum_2.end(), less<int>());

    int pos = sum_2.size() - 1;
    for(int val_1 : sum_1){
        int target = k - val_1;

        // while(0 <= pos && target < sum_2[pos]){     // WRONG
        // while(0 < pos && target < sum_2[pos]){      // AC, 1516 ms
        while(0 < pos && target <= sum_2[pos]){     // AC, 1508 ms
            --pos;
        }
        // if(pos < 0){
        //     pos = 0;
        // }
        // pos = lower_bound(sum_2.begin(), sum_2.begin() + pos, target) - sum_2.begin();

        int val_2 = sum_2[pos];
        update(val_1, val_2, target);

        if(pos + 1 < sum_2.size()){
            val_2 = sum_2[pos + 1];
            update(val_1, val_2, target);
        }
        // if(0 < pos){
        //     val_2 = sum_2[pos - 1];
        //     update(val_1, val_2, target);
        // }

        if(min_sum == k){   // 1440 ms
            break;
        }
    }

    cout << min_sum << endl;
}

void solve_two_pointer_2(){
    vector<int> sum_1;
    vector<int> sum_2;

    for(int idx=1; idx<=n; ++idx){
        for(int jdx=1; jdx<=n; ++jdx){
            sum_1.push_back(arr[1][idx] + arr[2][jdx]);
            sum_2.push_back(arr[3][idx] + arr[4][jdx]);
        }
    }

    sort(sum_1.begin(), sum_1.end(), less<int>());
    sort(sum_2.begin(), sum_2.end(), less<int>());

    // two-pointer
    for(int left=0, right=sum_2.size()-1; left<sum_1.size() && 0<=right; ){
        int sum = sum_1[left] + sum_2[right];

        // update(sum_1[left], sum_2[right], k - sum_1[left]);
        if(abs(k - sum) < abs(k - min_sum) || abs(k - sum) == abs(k - min_sum) && sum < min_sum){
            min_sum = sum;
        }

        if(sum < k){
            ++left;
        }
        else if(sum > k){
            --right;
        }
        else{
            min_sum = k;
            break;
        }
    }

    cout << min_sum << endl;
}

void solve(){
    initialize();

    solve_binary_search_1();
    // solve_binary_search_2();

    // solve_two_pointer_1();
    // solve_two_pointer_2();
}

void input(){
    cin >> T;
    while(T--){
        cin >> k >> n;
        for(int type=1; type<=NUM_CLASS; ++type){
            for(int idx=1; idx<=n; ++idx){
                cin >> arr[type][idx];
            }
        }

        solve();
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    // solve();

    return 0;
}
