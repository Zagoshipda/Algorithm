// c. news distribution
// 다른 방법으로 풀기(사실 가장 인간다운 알고리즘으로 푸는 방법이라고 생각함) -> merge 과정에서 cnt값을 계산하는 것이 아닌 모든 merge 과정을 끝마친 후 가장 마지막 단계에서 각 숫자들이 어느 그룹에 속해있는지를 count하는 방법
// 이 방법으로 하면 merge 과정에서 fn == fm 인지의 여부에 상관 없이 그냥 일단 fm의 parent를 fn으로 설정하기만 하면 됨 -> path compression은 FIND에서 처리 
// cnt 값을 가장 마지막에 처리하므로 UNION operation이 더 간단해졌고, 그떄 그때 cnt값을 변화시키면서 가지고 다니는 것이 아닌 마지막에 한꺼번에 처리하므로 더욱 인간이 생각하는 사고의 방식과 비슷한 코드 처리라 할 수 있음. 
// -> 직관적으로도 우선 input에 따라 각 숫자들을 모두 그룹화한 뒤에 가장 마지막에 해당 그룹의 element 개수를 세어주는 것이 인간의 방법이다. 매 순간마다 group을 짜고 merge할 때마다 count를 적당하게 계산하는 것이 오히려 computer만이 가능한, computer적 사고가 아닐까. 그런 의미에서 아주 좋은 방법이라 하겠다

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
        // if(fn == fm){       
        //     return;
        // }
    p[fm] = fn;
        // cnt[fn] += cnt[fm];
    return;
}

int main(){
	IOS;
    cin >> n >> m;
    for(i=1; i<=n; i++){
        p[i] = i;
            // cnt[i] = 1; 
    }
    // 2. 가장 첫 번째 element와 merge 하기 
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
    // 숫자 i 가 속해있는 그룹의 element 개수 구하기 
    // 각 숫자 i가 속해 있는 그룹을 찾아 해당 그룹의 cnt를 하나씩 증가시킨다 (cnt배열은 전역으로 선언했으므로 이미 각 element가 0으로 초기화되어있는 상태임을 주목)
    for(i=1; i<=n; i++){
        cnt[find(i)]++;
    }
    for(i=1; i<=n; i++){
        cout << cnt[find(i)] << ' ';
    }
    
    return 0;
}

