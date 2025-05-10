/*
    https://www.acmicpc.net/problem/14719
    (rainwater)
*/

#include <iostream>
#include <vector>
#include <stack>

#define endl '\n'

/*

*/

const int MAX_HEIGHT = 500;
const int MAX_WIDTH = 500;


int H, W;
std::vector<int> blocks;
int block;

void solve_stack(){
    std::stack<std::pair<int, int> > stk;   // (block, index)
    int ans = 0;
    for(int ith=0; ith<W; ++ith){
        if(stk.empty()){
            stk.push({blocks[ith], ith});
            continue;
        }

        if(stk.top().first >= blocks[ith]){
            stk.push({blocks[ith], ith});
        }
        else{
            int height;
            int idx;
            while(!stk.empty() && stk.top().first < blocks[ith]){
                height = stk.top().first;
                idx = stk.top().second;
                stk.pop();
            }
            if(stk.empty()){
                ans += (ith - idx) * height;
            }
            else{
                ans += (ith - stk.top().second) * blocks[ith];
            }
        }
    }

    std::cout << ans << endl;
}

void solve_brute_force(){
    int ans = 0;
    for(int ith=0; ith<W; ++ith){
        int left = ith - 1;
        int right = ith + 1;
        int max_left = 0, max_right = 0;

        while(0 <= left){
            max_left = std::max(max_left, blocks[left]);
            --left;
        }
        while(right < W){
            max_right = std::max(max_right, blocks[right]);
            ++right;
        }

        ans += std::max(0, std::min(max_left, max_right) - blocks[ith]);
    }
    std::cout << ans << endl;
}

void solve(){
    solve_brute_force();
}

void input(){
    std::cin >> H >> W;
    for(int ith=0; ith<W; ++ith){
        std::cin >> block;
        blocks.push_back(block);
    }
}

int main(){

    input();

    solve();

    return 0;
}
