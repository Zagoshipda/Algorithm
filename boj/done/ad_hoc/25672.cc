/*
    https://www.acmicpc.net/problem/25672
    (even and odd combinations)

    solution
        invert (nCk = nCn-k) except the nth item
            https://www.acmicpc.net/source/51496588
            (thenitromefan, 204 ms)
            https://www.acmicpc.net/source/62453684
            (yjyj1027, 104 ms)

        only considering kth item
            https://www.acmicpc.net/source/76983442
            (sahera5474, 12 ms) : vector<>
            https://www.acmicpc.net/source/66772276
            (greydra_k, 20 ms) : array[]

        only considering 1st item
            https://www.acmicpc.net/source/49772968
            (hjroh0315, 8 ms) : deque<>
            https://www.acmicpc.net/source/51077401
            (hibye1217, 8 ms) : deque<>
            https://www.acmicpc.net/source/61161274
            (luciaholic, 16 ms) : vector<>

        https://www.acmicpc.net/source/55641084
        (leeh18, 8 ms) : 2^50 bitset

    reference
        Ivan Kazmenko Contest 3
        https://ucup.ac/files/ucup/tutorials/tutorials-2-16.pdf
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Algorithm
        50C25 = 126'410'606'437'752 ~ O(10^14)

        nCk = n-1Ck-1 + n-1Ck
        k <-> k-1 ?

        n=2k-1
            nCk <-> nCn-k
            (observation) k, n-k parity always different
        n=2k
            ???

    Simulation
        n=2
            k=0
            ()
            k=1
            (1), (2)
            k=2
            (1,2)

        n=3
            k=0
                ()
            k=1
                (1) (2) (3)
            k=2
                (12) (13) (23)
            k=3
                (123)

        n=4
            k=0
                ()
            k=1
                (1) (2) (3) (4)
            k=2
                (12) (13) (14) (23) (24) (34)
            k=3
                (123) (124) (134) (234)
            k=4
                (1234)

        n=5
            k=0
                ()
            k=1
                (1) (2) (3) (4) (5)
            k=2 : 10
                (12) (13) (14) (15) (23) (24) (25) (34) (35) (45)
            k=3 : 10
                (123) (124) (125) (134) (135) (145) (234) (235) (245) (345)
            k=4 : 5
                (1234) (1235) (1245) (1345) (2345)
            k=5
                (12345)

*/

const int MAX_NUM = 50;

int t;
int n, k;
int arr[MAX_NUM + 1];

void solve(){
    if(k == 0){
        cout << n << " " << 1 << endl;
        cout << 1 << endl;
    }
    else{
        if(arr[1] > 1){
            cout << n << " " << k + 1 << endl;
            cout << 1 << " " << arr[1] << " ";
        }
        else{
            cout << n << " " << k - 1 << endl;
        }

        for(int idx=2; idx<=k; ++idx){
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
}

void input(){
    cin >> t;
    while(t--){
        cin >> n >> k;

        for(int idx=1; idx<=k; ++idx){
            cin >> arr[idx];
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
