/*
    https://app.codility.com/programmers/lessons/7-stacks_and_queues/stone_wall/
    (stonewall)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    Specification
        You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.

        The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.

        Write a function:

        class Solution { public int solution(int[] H); }

        that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.

        For example, given array H containing N = 9 integers:
            H[0] = 8    H[1] = 8    H[2] = 5
            H[3] = 7    H[4] = 9    H[5] = 8
            H[6] = 7    H[7] = 4    H[8] = 8
        the function should return 7. The figure shows one possible arrangement of seven blocks.

        Write an efficient algorithm for the following assumptions:

        - N is an integer within the range [1..100,000];
        - each element of array H is an integer within the range [1..1,000,000,000].

    Algorithm
        greedy (cut by height / width) works...?
            8 8 5 7 9 8 7 4 8

        8 5 7 9 8 4 8 : just remove duplicates ? NO
            ex. 1 2 1 2 => 3 blocks required

        (idea) definitely need 1 block for each mountain shape
            => just count # of mountains + remaining blocks

*/

#include <stack>

const int ARR_SIZE = 100'000;   // 10^5
const int MIN_NUM = 1;  // 10^0
const int MAX_NUM = 1'000'000'000;  // 10^9

int solution(vector<int> &H) {
    // Implement your solution here

    stack<int> stk;
    stk.push(0);
    int blocks = 0;

    for(int height : H){
        while(!stk.empty() && stk.top() > height){
            stk.pop();
            ++blocks;
        }

        if(stk.empty() || stk.top() < height){
            stk.push(height);
        }
    }
    // cout << blocks << endl;
    // cout << stk.size() << endl;

    return blocks + stk.size() - 1;     // excluding the first 0
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
