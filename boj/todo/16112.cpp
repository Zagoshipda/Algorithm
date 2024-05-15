// 5차 전직 ... 메이플이라니 메이플이라니 

#include <cstdio>

// 정렬이 필요할듯

int sw(int a, int b){
    int c = b;
    b = a;
    a = c;
}
int swap(int* a, int* b){
    int c = *b;
    *b = *a;
    *a = c;
}

// // rearranges the subarray A[p ... r] in place
// int partition(int[] A, int p, int r){
//     int x = A[r];   //last element
//     int i = p-1; //one before starting position
//     for(int j=p; j<r; j++){ //for j=p to r-1
//         if(A[j] <= x ){
//             i++;
//             A[i] 
//         } 
//     }

// }

// int quickSort(int[] A, int p, int r){
//     if(p < r){
//         int q = partition(A, p, r); //compute index q as a part of this partitioning process
//         quickSort(A, p, q-1);
//         quickSort(A, q+1, r);
//     }
// }


int main(){
    // int n, k;   //총 n개의 퀘스트(아케인스톤), 최대 k개 스톤이 동시에 활성화
    // scanf("%d %d", &n, &k);
    
    // int* arr = new int[n];
    
   

}