/*
    https://www.acmicpc.net/problem/2407
    (combination)

    solutions
    2 possible implementations for big numbers : string or int array(vector)
        https://www.acmicpc.net/source/12967586
        (pch6789, 0 ms) used string, implemented in solve_3()

        https://sneakstarberry.github.io/posts/nojam2407/
            top-down approach with recursive call
        https://www.acmicpc.net/source/11271483
        (ehcks304, 0 ms) used string, bottom-up approach, implemented in solve_4()

        https://www.acmicpc.net/source/69762
        (yhkim89, 0 ms)

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*
    (n >= m)
    nCm = n(n-1)...(n-(m-1)) / m(m-1)...1
        = n-1Cm + n-1Cm-1
    NOTE : NOT n-1Cm > n-1Cm-1
        n-1Cm-1 > n-1Cm also possible (combination symmetry)

    1C1 = 1
    2C0 = 1
    2C1 = 1C1 + 1C0 = 2
    2C2 = 1
    3C0 = 1
    3C1 = 2C1 + 2C0 = 3
    3C2 = 2C2 + 2C1 = 3
    3C3 = 1
    5C2 = 4C2 + 4C1 = 6 + 4 = 1,0
    6C2 = 5C2 + 5C1 = 1,0 + 5 = 1,5

    6C4 = 5C4 + 5C3

    7C2 = 6C2 + 6C1 = 15 + 6 = 21
    11C2 = 10C2 + 10C1 = 4,5 + 1,0 = 5,5

    8C5 = 7C5 + 7C4
    8C6 = 7C6 + 7C5

    9C6 = 8C6 + 8C5
    10C6 = 9C6 + 9C5
    20C6 = 19C6 + 19C5

    10 9 8 7  / 6
    4 3 2 1   / 5
*/

const int MAX_NUM = 100;
int n, m;
// NOTE : index
vector<int> comb[MAX_NUM + 1][MAX_NUM + 2];  // comb[n][m] = nCm

void solve_wrong_1(){
    if(n == m){
        cout << 1 << endl;
        return;
    }

    // 1. initialize
    for(int num=1; num<=n; ++num){
        comb[num][0].push_back(1);
        comb[num][num].push_back(1);
    }

    // 2. recursive calcualtion
    for(int num=2; num<=n; ++num){
        int limit = (num >= n) ? m : num-1;
        for(int mum=1; mum<=limit; ++mum){
            int len_1 = comb[num-1][mum].size();
            int len_2 = comb[num-1][mum-1].size();
            // cout << "len_1 len_2 : " << len_1 << " " << len_2 << endl;
            int sum = 0;
            int carry = 0;
            int idx;
            for(idx=0; idx<len_2; ++idx){
                sum = carry + comb[num-1][mum][idx] + comb[num-1][mum-1][idx];
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }
                else{
                    carry = 0;
                }
                comb[num][mum].push_back(sum);
            }
            for( ; idx<len_1; ++idx){
                sum = carry + comb[num-1][mum][idx];
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }
                else{
                    carry = 0;
                }
                comb[num][mum].push_back(sum);
            }
            if(carry){
                comb[num][mum].push_back(carry);
            }
        }
    }

    // 3. output
    // for(int row=1; row<=n; ++row){
    //     for(int col=0; col<=n)
    // }
    int len = comb[n][m].size();
    cout << len << endl;
    // for(auto it=comb[n][m].rbegin(); it!=comb[n][m].rend(); --it){
    //     cout << *it;
    // }
    for(int idx=len-1; idx>=0; --idx){
        cout << comb[n][m][idx];
    }
    cout << endl;
}

void solve_wrong_2(){

    for(int row=1; row<=n; ++row){
        comb[row][1].push_back(row);

        int limit = row==n ? m : row;
        for(int col=2; col<=limit; ++col){
            cout << "   row col " << row << " " << col << endl;
            // comb[row][col] = comb[row-1][col-1] + comb[row-1][col];
            if(col < row){
                cout << comb[row-1][col-1].size() << " : ";
                for(int num : comb[row-1][col-1]){
                    cout << num << " ";
                }
                cout << endl;
                cout << comb[row-1][col].size() << " : ";
                for(int num : comb[row-1][col]){
                    cout << num << " ";
                }
                cout << endl;

                int len_1 = comb[row-1][col-1].size();
                int len_2 = comb[row-1][col].size();
                int idx;
                int sum, carry = 0;
                for(idx=0; idx<len_1; ++idx){
                    sum = carry + comb[row-1][col-1][idx] + comb[row-1][col][idx];
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    }
                    else{
                        carry = 0;
                    }
                    comb[row][col].push_back(sum);
                }
                for( ; idx<len_2; ++idx){
                    sum = carry + comb[row-1][col][idx];
                    if(sum > 9){
                        carry = 1;
                        sum -= 10;
                    }
                    else{
                        carry = 0;
                    }
                    comb[row][col].push_back(sum);
                }
                if(carry){
                    comb[row][col].push_back(carry);
                }
            }
            else{
                comb[row][row].push_back(1);
            }
        }
    }


    for(auto it=comb[n][m].rbegin(); it!=comb[n][m].rend(); ++it){
        cout << *it;
    }
    cout << endl;
}

void solve_3(){

    comb[0][0].push_back(1);
    comb[0][1].push_back(0);

    for(int row=1; row<=n; ++row){
        comb[row][0].push_back(1);

        for(int col=1; col<=row; ++col){
            int len_1 = comb[row-1][col-1].size();
            int len_2 = comb[row-1][col].size();
            vector<int> longer, shorter;
            if(len_1 > len_2){
                longer = comb[row-1][col-1];
                shorter = comb[row-1][col];
            }
            else{
                shorter = comb[row-1][col-1];
                longer = comb[row-1][col];
            }

            int idx;
            int sum, carry = 0;
            len_1 = shorter.size();
            len_2 = longer.size();
            for(idx=0; idx<len_1; ++idx){
                sum = carry + shorter[idx] + longer[idx];
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }
                else{
                    carry = 0;
                }
                comb[row][col].push_back(sum);
            }
            for( ; idx<len_2; ++idx){
                sum = carry + longer[idx];
                if(sum > 9){
                    carry = 1;
                    sum -= 10;
                }
                else{
                    carry = 0;
                }
                comb[row][col].push_back(sum);
            }
            if(carry){
                comb[row][col].push_back(carry);
            }
        }

        comb[row][row+1].push_back(0);
    }

    // cout << comb[n][m].size() << endl;
    for(auto it=comb[n][m].rbegin(); it!=comb[n][m].rend(); ++it){
        cout << *it;
    }
    cout << endl;
}

void solve_4(){

    for(int row=0; row<=n; ++row){
        for(int col=0; col<=row; ++col){
            // cout << row << " " << col << endl;
            if(col==0 || col==row){
                comb[row][col].push_back(1);
            }
            else{
                int sum = 0, carry = 0;
                vector<int> num_1 = comb[row-1][col-1];
                vector<int> num_2 = comb[row-1][col];
                while(carry || !num_1.empty() || !num_2.empty()){
                    int val_1 = 0, val_2 = 0;
                    if(!num_1.empty()){
                        val_1 = num_1.back();
                        num_1.pop_back();
                    }
                    if(!num_2.empty()){
                        val_2 = num_2.back();
                        num_2.pop_back();
                    }
                    sum = carry + val_1 + val_2;
                    if(sum > 9){
                        sum -= 10;
                        carry = 1;
                    }
                    else{
                        carry = 0;
                    }
                    comb[row][col].push_back(sum);
                }

                reverse(comb[row][col].begin(), comb[row][col].end());
            }
            // for(int len=0; len<comb[row][col].size(); ++len){
            //     cout << comb[row][col][len];
            // }
            // cout << endl;
        }
    }
    // cout << comb[n][m].size() << endl;
    for(int num : comb[n][m]){
        cout << num;
    }
    cout << endl;
}

void solve(){
    // solve_wrong_1();

    // solve_wrong_2();

    // solve_3();

    solve_4();
}

void input(){
    cin >> n >> m;
}

int main(){
    IOS;

    input();

    solve();

    return 0;
}
