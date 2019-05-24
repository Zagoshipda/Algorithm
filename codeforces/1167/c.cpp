// c. news distribution
// accepted....!!! -> tree union & merge(union)를 이용하는 문제였음 
// 정답판 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;   //num of users, num of groups 
int i;
int p[500005];       //p[1...n], parent(group) of i
int cnt[500005];     //cnt[1...n], num of elements in group of i

//find a group where n is included
int find(int n){
    return n == p[n] ? n : (p[n] = find(p[n])); 
}

// merge m into n (as a group)
void merge(int n, int m){
    int fn = find(n);
    int fm = find(m);
    if(fn == fm){       
        return;
    }
    p[fm] = fn;
    cnt[fn] += cnt[fm];
    return;
}

int main(){
	IOS;
    cin >> n >> m;
    for(i=1; i<=n; i++){
        p[i] = i;
        cnt[i] = 1; 
    }

        // 1. 바로 이전 element와 merge 하기 
        // for(i=0; i<m; i++){
        //     int k =0;
        //     cin >> k;
        //     int pre = 0, cur = 0;
        //     for(int j=0; j<k; j++){
        //         cin >> cur;
        //         if(pre != 0){
        //             merge(pre, cur);
        //         }
        //         pre = cur;
        //     }
        // }

    // 2. 가장 첫 번째 element와 merge 하기 -> 이 방법이 pre값을 매번 바꾸어주지 않아도 되서 더 효율적
    for(i=0; i<m; i++){
        int k =0;
        cin >> k;
        if(!k){
            continue;
        }
        int first, cur;
        cin >> first;
        for(int j=0; j<k-1; j++){   
            cin >> cur;
            merge(first, cur);
        }
    }
    
    for(i=1; i<=n; i++){
        cout << cnt[find(i)] << ' ';
    }
    
    return 0;
}

