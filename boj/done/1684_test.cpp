/*

*/

#include <bits/stdc++.h>

using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ll long long    // range : -9*10^18 ~ 9*10^18

/*

*/

const int MAX_NUM = 1'000;
const int MAX_VAL = 1'000'000;

const int n = 4;
int T = 20;
random_device rd;
mt19937 gen(rd());
// uniform_int_distribution<> distribution(10, 30);
normal_distribution<> distribution(10, 10);

ofstream fout;
ifstream fin;
void solve(){
    fout.open("./1684.in");
    fout << T << endl;
    while(T--){
        fout << n << endl;
        for(int ith=1; ith<=n; ++ith){
            fout << ceil(distribution(gen)) << " ";
        }
        fout << endl;
    }

    fout.close();
}

void input(){

}

int main(){
    IOS;

    // input();

    solve();

    return 0;
}
