/*
    https://www.acmicpc.net/problem/28346
    (XOR necklace)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - for each "pair of consecutive beads" in the necklace, take XOR of their numbers
        - A programmer’s score is defined as the sum of all those sums
            sum(Ai^Aj) = A1^A2 + A2^A3 + ... + AN-1^AN + AN^A1
        - The programmer with the lowest score loses
        - operation : removing zero or more beads to maximize the score
        - cannot reorder the beads, nor leave one or less beads in a necklace (N >= 2)
        => what is the maximum score if you are allowed to remove some of the beads in a given necklace

    Algorithm
        N ~ 500 ~ O(10^3)
        brute force ?
            for Ai, can remove Ai+1...Ai-2 : O(10^3)

        0 ^ 0 = 0 : initialize to 0
        0 ^ 1 = 1 : initialize to 0
        1 ^ 0 = 1
        1 ^ 1 = 0

        when to remove ?
            Ai-1 Ai Ai+1 => Ai-1 Ai+1
            Ai-1^Ai + Ai^Ai+1 < Ai-1^Ai+1
        only removing 1 element ?
        (observation) possible to remove k (> 1) consecutives ?
            Ai-1 Ai Ai+1 Ai+2 => Ai-1 Ai+2 ?
            not Ai-1^Ai + Ai^Ai+1 < Ai-1^Ai+1,
            but Ai-1^Ai + Ai^Ai+1 + Ai+1^Ai+2 < Ai-1^Ai+2 ?

            Ai Ai+1 ... Ai+k Ai+k+1 => Ai Ai+k+1 (removing k elements in between)

        proof.
            suppose a >= b, Ai=a, Ai+1=c, Ai+2=b
            a^c + c^b >=< a^b ?
            by comparing bitwise,
            if aj == bj
                then always aj^bj = 0
                if cj == (aj == bj)
                    aj^bj = aj^cj = cj^bj = 0 (all xor = 0)
                    => aj^cj + cj^bj = aj^bj
                else
                    aj^cj = 1, cj^bj = 1
                    => aj^cj + cj^bj > aj^bj

            else aj != bj
                then always aj^bj = 1
                for any choice of cj=0 or 1
                always {aj^cj, cj^bj} = {0, 1}
                => aj^cj + cj^bj >= aj^bj

            therefore, aj^cj + cj^bj >= aj^bj
            hence a^c + c^b >= a^b for any choice of Ai=a, Ai+1=c, Ai+2=b

            by mathematical induction, always true for removing any k consecutives


        closed form solution
            by using the fact that A^B = A+B - 2A&B
            a^c + c^b = (a+c - 2a&c) + (c+b - 2c&b)
                      = a+b + (c - 2a&c) + (c - 2c&b)
                      >= a+b
                      >= a+b - 2a&b
                      = a^b

1
3
1 2 3

*/

const int ARR_SIZE = 500;
const int MAX_NUM = 1'000'000'000;  // 10^9

int T;
int N;

ll arr[ARR_SIZE+ 2];
ll xors[ARR_SIZE + 2];
ll prefix_sum[ARR_SIZE + 2];

int get_index(int index){
    if(index > N){
        return index - N;
    }
    else if(index < 1){
        return index + N;
    }
    else{
        return index;
    }
}
void solve_wrong(){
    if(N <= 2){
        cout << (arr[1] ^ arr[2]) << endl;
        return;
    }

    ll max_sum = 0;
    for(int start=1; start<=N; ++start){
        for(int end=start; get_index(end + 2) != start; ++end){
            // remove start...end
            ll sum = prefix_sum[N+1];
            ll subtract = 0;
            if(end <= N){
                subtract += prefix_sum[end+1] - prefix_sum[get_index(start-1)];
            }
            else{
                subtract += prefix_sum[N+1] - prefix_sum[get_index(start-1)];
                subtract += prefix_sum[end+1] - prefix_sum[1];
            }
            sum -= subtract;
            sum += (arr[get_index(start-1)] ^ arr[get_index(end+1)]);
            max_sum = max(max_sum, sum);
        }
    }
    cout << max_sum << endl;
}

void solve_1(){
    cout << prefix_sum[N+1] - prefix_sum[1] << endl;
}

void solve(){
    solve_1();
}

void input(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int idx=1; idx<=N; ++idx){
            cin >> arr[idx];
            xors[idx] = arr[idx-1] ^ arr[idx];
            prefix_sum[idx] = 0;
            prefix_sum[idx] = prefix_sum[idx-1] + xors[idx];
        }
        // circular
        xors[N+1] = arr[N] ^ arr[1];
        prefix_sum[N+1] = 0;
        prefix_sum[N+1] = prefix_sum[N] + xors[N+1];

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
