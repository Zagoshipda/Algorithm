// c. news distribution
// accepted....!!! -> tree union & merge(union)를 이용하는 문제였음
// 정답 해설판 

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

int n, m;   //num of users, num of groups 
int i;
int p[500005];       //p[1...n], parent(group) of i
int cnt[500005];     //cnt[1...n], num of elements in group of i

//find a group where n is included
//***parent를 update하지 않고 p[n]만 return하면 time limit exceeded에 걸린다 (time limit exceeded 4) 이 작업의 효과는? -> n의 parent인 p[n]을 tree 가장 상위의 parent로 바로 연결함으로써(path compression) tree의 깊이를 단축, find의 탐색시간을 줄이고, 이로부터 merge의 소요시간 또한 효과적으로 줄일 수 있음 
// -> equivalence class problem : are 2 elements in the same tree? -> solve it by using a parent pointer + path compression (for efficient running time of FIND)/ implement FIND and UNION operation
int find(int n){
    return n == p[n] ? n : (p[n] = find(p[n])); 
    // return n == p[n] ? n : p[n];    //without path compression
}

// merge m into n (as a group)
void merge(int n, int m){
    //merge를 위한 parent 찾기. 어느 group에 속해있는지를 확인하기
    int fn = find(n);
    int fm = find(m);
    //***fn == fm 일 때는 merge를 할 필요가 없음. (처음에 이것을 빼먹었음 -> wrong answer 3)
    if(fn == fm){       
        return;
    }
    //merge 과정 
    p[fm] = fn;
    cnt[fn] += cnt[fm];
    return;
}

int main(){
	IOS;
        // scanf("%d %d", &n, &m);
    cin >> n >> m;
    // parent 와 cnt 초기화. 처음에는 element 각각이 자기 자신의 parent인 것으로 간주한다
    for(i=1; i<=n; i++){
        p[i] = i;
        cnt[i] = 1; 
    }

    //merge과정... 아래는 앞의 것과 바로 전 것을 비교했지만 가장 처음 원소와 현재 원소를 merge하는 방법도 가능 (아래 주석 참고)
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

    // 2. 가장 첫 번째 element와 merge 하기 -> 이 방법이 pre값을 매번 바꾸어주지 않아도 되서 더 효율적이다 
    for(i=0; i<m; i++){
        int k =0;
        cin >> k;
        if(!k){
            continue;
        }
        int first, cur;
        cin >> first;
        //첫 번째 원소를 제외한 나머지 k-1개의 원소들을 input으로 받아서 first원소와 merge한다
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

