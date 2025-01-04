/*
    https://app.codility.com/programmers/lessons/8-leader/equi_leader/
    (equileader)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        A non-empty array A consisting of N integers is given.

        The leader of this array is the value that occurs in more than half of the elements of A.

        An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

        For example, given array A such that:
            A[0] = 4
            A[1] = 3
            A[2] = 4
            A[3] = 4
            A[4] = 4
            A[5] = 2
        we can find two equi leaders:
            - 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
            - 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.

        The goal is to count the number of equi leaders.

        Write a function:

            class Solution { public int solution(int[] A); }

        that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

        For example, given:
            A[0] = 4
            A[1] = 3
            A[2] = 4
            A[3] = 4
            A[4] = 4
            A[5] = 2
        the function should return 2, as explained above.

        Write an efficient algorithm for the following assumptions:
            - N is an integer within the range [1..100,000];
            - each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

    Algorithm
        find all possible positions of equi-leaders
        - find leader of array A
        - for each split position k = 0...N-2, count # of leaders in each subarray A[0...k], A[k+1...N-1] and check whether it is an equi-leader or not

        => need to find # of leaders in subarray A[l...r]
        => prefix sum ? / just sweep through it
*/

// #include <map>
#include <unordered_map>

const int ARR_SIZE = 100'000;       // 10^5
const int MIN_NUM = -1'000'000'000; // -10^9
const int MAX_NUM = +1'000'000'000; // +10^9

// map<int, int> hashes;
unordered_map<int, int> hashes;
int leader = -1;

bool check_equi(int len, int cnt){
    return (len < cnt * 2);
}

int solution(vector<int> &A) {
    // Implement your solution here

    int len = A.size();
    for(int num : A){
        ++hashes[num];
        if(check_equi(len, hashes[num])){
            leader = num;
        }
    }

    // sweeping
    int cnt = 0;
    int equis = 0;
    for(int ith=0; ith<len; ++ith){
        if(A[ith] == leader){
            ++cnt;
        }

        int prefix = ith + 1;
        int suffix = len - prefix;
        if(check_equi(prefix, cnt) && check_equi(suffix, hashes[leader] - cnt)){
            ++equis;
        }
    }

    return equis;
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
