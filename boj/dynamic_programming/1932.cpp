#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

#define SIZE 501
int N;
vector<int> triangle[SIZE];
int triangle_sum[SIZE][SIZE];
int max_triangle_sum;

void calculate_max_sum(){
    triangle_sum[0][0] = triangle[0][0];

    for(int row=1; row<N; ++row){
        for(int col=0; col<=row; ++col){
            if(col == 0){
                triangle_sum[row][col] = triangle_sum[row-1][col] + triangle[row][col];
            }
            else if(col == row){
                triangle_sum[row][col] = triangle_sum[row-1][col-1] + triangle[row][col];
            }
            else{
                triangle_sum[row][col] = max(triangle_sum[row-1][col-1], triangle_sum[row-1][col]) + triangle[row][col];
            }
        }
    }

    for(int i=0; i<N; ++i){
        // cout << triangle_sum[N-1][i] << " ";
        max_triangle_sum = max(max_triangle_sum, triangle_sum[N-1][i]);
    }
    // cout << endl;
}

int main(){
    IOS;

    cin >> N;
    int number;
    for(int i=0; i<N; ++i){
        for(int j=0; j<=i; ++j){
            cin >> number;
            triangle[i].push_back(number);
        }
    }

    calculate_max_sum();

    cout << max_triangle_sum << endl;

    return 0;
}
