/*
    https://www.acmicpc.net/problem/27878
    (permutation cycle query)

    solution
        https://www.acmicpc.net/source/57509547
        (cozyyg, 3916 ms)

        https://www.acmicpc.net/source/75450536
        (jinhan814, 2440 ms)
            (following permutation pointer) rather than (calculating modular in cycle)

        faster modular
            https://www.acmicpc.net/source/57423197
            (tlsdydaud1, 1604 ms)
            https://www.acmicpc.net/source/57531290
            (hijkl2e, 2620 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        operation ~ 10^1'000 ~ 10^3^7 ~ 2^10^7 ~ 2^70

        sparse table ?
            converting to binary representation required

        permutation cycle decomposition
            modular m

        (observation) for each swap(i, j) cycle may cut into 2 subcycles or not
*/

const int ARR_SIZE = 100'000;   // 10^5
const int MAX_BIT = 1'000;      // 10^3


int n;
string m;
int perm[ARR_SIZE + 1];
int q;
int type;

ll result[ARR_SIZE + 1];

int cache[ARR_SIZE + 1];    // caching remainders ? divisor ~ 10^5
int calculate_remainder(int divisor){
    if(!cache[divisor]){
        int len = m.size();
        int num = 0;
        for(int idx=0; idx<len; ++idx){     // MAX_BIT ~ O(10^3)
            num *= 10;      // AC
            num += (m[idx] - '0');
            num %= divisor;
            // num *= 10;   // WRONG
        }

        cache[divisor] = num;
    }

    return cache[divisor];
}

ll sum;
bool is_updated;
bool visited[ARR_SIZE + 1];
void calculate_permutation(){
    // sum = 0;
    for(int ith=1; ith<=n; ++ith){      // n ~ O(10^5)
        if(!visited[ith]){
            vector<int> cycle;
            int pos = ith;
            // while(!visited[pos]){
            //     visited[pos] = true;
            //     cycle.push_back(pos);
            //     pos = perm[pos];
            // }

            // only updating cycles from elements which has been swapped
            while(perm[pos] != ith){
                visited[pos] = true;
                cycle.push_back(pos);
                pos = perm[pos];
            }
            visited[pos] = true;
            cycle.push_back(pos);

            int len = cycle.size();
            int remainder = calculate_remainder(len);

            // 1440 ms
            for(int idx=0; idx<len; ++idx){
                result[cycle[idx]] = cycle[(idx + remainder) % len];
                // sum += cycle[idx] * cycle[(idx + remainder) % len];
            }

            // 1668 ms
            // int curr = cycle[0];
            // int next = cycle[remainder % len];
            // for(int idx=0; idx<len; ++idx){
            //     result[curr] = next;
            //     curr = perm[curr];
            //     next = perm[next];
            // }
        }
    }
}

void calculate_convolution(){
    if(is_updated){
        is_updated = false;

        calculate_permutation();

        sum = 0;
        for(int ith=1; ith<=n; ++ith){  // n ~ O(10^5)
            sum += ith * result[ith];
        }
    }

    cout << sum << endl;
}

void solve(){
    is_updated = true;

    cin >> q;
    while(q--){
        cin >> type;
        if(type == 1){
            int idx, jdx;
            cin >> idx >> jdx;

            swap(perm[idx], perm[jdx]); // NOTE : cycle may cut into 2 subcycles
            visited[idx] = false;
            visited[jdx] = false;
            // calculate_permutation(); // time exceeded
            is_updated = true;
        }
        else{
            calculate_convolution();
        }
    }
}

void input(){
    cin >> n >> m;
    for(int ith=1; ith<=n; ++ith){
        cin >> perm[ith];
    }
}

int main(){
    IOS;

    // freopen("_.in", "rt", stdin);
    // freopen("_.out", "wt", stdout);

    input();

    solve();

    return 0;
}
