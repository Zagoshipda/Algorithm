/*
    https://app.codility.com/demo/take-sample-test/
    (Codility Demo Test)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    [30 minutes for 1 task]

    This is a demo task.

    Write a function:
        class Solution { public int solution(int[] A); }

    that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

    For example,
        given A = [1, 3, 6, 4, 1, 2], the function should return 5.
        Given A = [1, 2, 3], the function should return 4
        Given A = [−1, −3], the function should return 1.

    Write an efficient algorithm for the following assumptions:
        - N is an integer within the range [1..100,000];
        - each element of array A is an integer within the range [−1,000,000..1,000,000].

*/

const int ARR_SIZE = 100'000;   // 10^5
const int MIN_NUM = -1'000'000; // -10^6
const int MAX_NUM = +1'000'000; // +10^6
int hashes[MAX_NUM << 2];

int solution(vector<int> &A) {
    // Implement your solution here

    for(int num : A){
        if(num > 0){
            ++hashes[num];
        }
    }

    for(int num=1; num<=MAX_NUM; ++num){
        if(hashes[num] <= 0){
            return num;
        }
    }

    return 1;
}

void solve(){

}

void input(){

}

void debug(){

}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    // debug();

    input();

    solve();

    return 0;
}
