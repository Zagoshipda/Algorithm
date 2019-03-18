#include <iostream>
using namespace std;

//그럼 동적으로 배열을 생성한 후 함수의 인자로 넘겨주는 방법은?

void swap(int A[], int a, int b);
void quickSort(int A[], int p, int r);
int partition(int A[], int p, int r);

int main(){
        // //swap test
        // int A[] = {1,2};
        // cout <<"before\n";
        // for(int i=0; i<sizeof(A)/sizeof(*A); i++){
        //     cout << "A[" << i <<"]:" << A[i] << '\n';
        // }
        // swap(A, 0, 1);
        // cout << "After\n";
        // for(int i=0; i<sizeof(A)/sizeof(*A); i++){
        //     cout << "A[" << i <<"]:" << A[i] << '\n';
        // }
    int A[] = {3,6,1,9,7,2,8,4,5};
    quickSort(A,0,sizeof(A)/sizeof(*A));
    for(int i=0; i<sizeof(A)/sizeof(*A); i++){
        cout << A[i] << ' ';
    }
}

void swap(int A[], int a, int b){
    int c = A[a];
    A[a] = A[b];
    A[b] = c;
}
// to sort an entire array A, the initial call is quickSort(A, 1, A.length)
void quickSort(int A[], int p, int r){
    if(p < r){  //사실상 이 조건에 맞도록 p, r이 들어오므로 거의 무의미한 조건 검사라 볼 수 있겠다...?? -> 그렇지 않음 아래 else 내용 주석을 제거하고 실행시켜보라. 
        int q = partition(A, p, r);
        quickSort(A, p, q-1);   //left half
        quickSort(A, q+1, r);   //right half
    }
    // else{
    //     cout << "range error" << "\n"; 
    // }
}

int partition(int A[], int p, int r){
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j]<=x){
            i = i+1;
            swap(A, i, j);
        }
    }
    swap(A, i+1, r);
    return i+1;
}