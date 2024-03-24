/*
    https://www.acmicpc.net/problem/10431
    (height ordering) : insertion sort

    solutions
        https://www.acmicpc.net/source/55465515
        (imda95, 0 ms) : implemented in solve_insertion()

        implemented in solve_bubble()
            https://www.acmicpc.net/source/64544118
            (dlalswp25, 0 ms)
            https://www.acmicpc.net/source/427148
            (portableangel, 0 ms)
*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        - line up in height order (shortest at the front of the line)
        - One student would be selected to be the first person in line.
        - Another student is selected and would find the first person in the line that is taller than him, and stand in front of that person

        >>> all the students behind him to "step back" to make room <<<

        - If there is no student that is taller, then he would stand at the end of the line.
        - (correctness check) This process continues, one student at-a-time, until all the students are in line, at which point the students will be lined up in height order.

        Q. calculates the total number of "steps taken back" during the ordering process

    Algorithm
        1. simulate
        2. insertion sort : count the # of bigger elements that are ahead

*/

const int ARR_SIZE = 20;
int P;
int K;
int arr[ARR_SIZE + 1];
int steps;

void solve_bubble(){
    steps = 0;  // NOTE : initialize
    for(int idx=2; idx<=ARR_SIZE; ++idx){
        // NOTE : find the first larger element
        for(int jdx=1; jdx<idx; ++jdx){
            if(arr[idx] < arr[jdx]){
                for(int pos=idx; pos>jdx; --pos){
                    swap(arr[pos-1], arr[pos]);
                    ++steps;
                }
            }
        }
    }
    cout << K << " " << steps << endl;
}

void solve_insertion(){
    steps = 0;
    for(int idx=1; idx<=ARR_SIZE; ++idx){
        for(int jdx=1; jdx<idx; ++jdx){
            if(arr[jdx] > arr[idx]){
                ++steps;
            }
        }
    }
    cout << K << " " << steps << endl;
}

void solve(){
    // solve_bubble();

    solve_insertion();
}

void input(){
    cin >> P;
    while(P--){
        cin >> K;
        for(int i=1; i<=ARR_SIZE; ++i){
            cin >> arr[i];
        }
        solve();
    }
}

int main(){
    IOS;

    input();

    // solve();

    return 0;
}
