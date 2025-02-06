#include <stdio.h> 
#include <stdlib.h> 

/*
   3 2
   1 2 3
   1 2 -> 1 2
   4 2
   1 3 5 5
   100 5 -> -1 3
*/

int binary_search(int arr[], int left, int right, int value){
   if ( left > right ) return -1; // kalau pencarian ga ditemuin, langsung return -1; 

   int middle = left + ( right - left ) / 2; // template nya gini 

   if ( arr[middle] == value ){
      if ( middle == 0 || arr[middle - 1] != value ){ // ngecek apakah ini elemen pertma yang muncul 
         return middle; // indeks pertama dari elemen yang ada 
      } else {
         return binary_search(arr, left, middle-1, value); // cari semakin kekiri 
      }
   } else if ( arr[middle] >= value ){ // mau lebih besar sama dengan atau ngga hasilnya sama ja 
      return binary_search(arr, left, middle-1, value); // cari di bagian kekiri 
   } else {
      return binary_search(arr, middle+1, right, value); // cari disisi kanan 
   }
}

int main(){
   int N, M; 
   scanf("%d %d", &N, &M); 

   int A[N]; 
   for ( int i = 0; i < N; i++ ){
      scanf("%d", &A[i]); 
   }

   for ( int i = 0; i < M; i++ ){
      int Q; 
      scanf("%d", &Q); 

      int search = binary_search(A, 0, N-1, Q); // untuk mengakses indeks pertama, dan indeks terakhir dari sebuah array 
      printf("%d\n", search == -1 ? search : search + 1); 
   }
}