// https://blog.myungwoo.kr/32
// Falling ants

// 착각한 점: id가 작은 개미가 더 먼저 떨어지는데 id의 절댓값이 작은 개미가 더 먼저 떨어진다는 것으로 생각해서 오히려 더 어렵게 생각해버렸다.... 그나저나 절댓값이 작은 개미가 더 먼저 떨어진다고 해도 알고리즘을 충분히 짤 수 있을 것이다. 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAXN 100005	// max num of ants 

int T, N, L, K;	// T: # test cases, N: # ants, L: length, K: find kth

struct {
	int p, id;
} A[MAXN];	// # MAXN ants  

struct Z{
	int p, id;
	bool operator < (const Z &z) const{	// operator overloading
		// 크기 비교는 position이 우선이고 이동거리가 같다면 더 가벼운 것id 이 먼저 
		return (p != z.p) ? (p < z.p) : (id < z.id);
	}
} C[MAXN]; 

int main(){
	int i = 0; 	//반복문에 사용할 i 변수는 미리 선언해서 불필요한 중복 선언 할당을 하지 않도록 하고, 동시에 다른 변수들에 중복해서 사용하는 일 또한 방지하도록 한다.

	for(scanf("%d", &T); T--;){	// for 문에서 마지막 증감 변화를 없애고, 대신 증감을 조건확인 부분에 넣어서 2가지 실행을 동시에 처리할 수 있다. 0(false) 나머지(true) 이므로 0이 될 때까지 반복되는 조건임을 알 수 있음
	// for(scanf("%d", &T); T>0; T--){	// 이렇게 마지막 증감조건을 넣어주면 조건검사 또한 해야하는데 사실 이것이 조금 더 일반적인 코딩, 아니 내가 사용하는 방법이긴 하다
		scanf("%d %d %d", &N, &L, &K);
		for (i=1; i<=N; i++){
			scanf("%d %d", &A[i].p, &A[i].id);

			// *** algorithm idea 
			if(A[i].id < 0){	// - left
				C[i].p = A[i].p;
			}else{				// + right 
				C[i].p = L - A[i].p;
			} 
			C[i].id = A[i].id / abs(A[i].id);	// -1 left, +1 right
		}
		sort(C+1, C+N+1);	// sort C[1...N], sorting based on operator overloading above(position, id value)
		cout << endl;
		for(i=1; i<=N; i++){
			cout << C[i].p << ' ' << C[i].id << endl;
		}
		cout << endl;

		int s = 1, e = N;	// leftmost, rightmost ant position 
		int out = 0;	//output
		for(i=1; i<=K; i++){	// find Kth falling ant
			if(i < N && C[i].p == C[i+1].p){	// C index 를 비교하기 위해 i<N 조건 필요 
				if(A[s].id > A[e].id){	// 이 부분이 필요한 이유는 주석처리를 한후 실행시켜보면 바로 알 수 있는데, 바로 C를 sorting 할 때 무조건 -1 < 1 이므로 left 방향이 먼저 우선순위를 가지도록 정렬되었기 때문이다. 그러나 반복문을 진행하다가 leftmost ant 가 빠지면 position 대소관계는 맞을지라도 id 대소관계는 달라질 수 있으므로 이를 다시 확인해서 순서를 바꾸어주는 것이다....??
					swap(C[i], C[i+1]);
				}
			}
			if(C[i].id < 0){	// -1 left
				out = A[s++].id;
			}else{				// +1 right 
				out = A[e--].id;
			} 
		}
		printf("%d \n", out);
	}

	return 0;
}