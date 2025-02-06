#include <stdio.h> 
/*
    Maksud dari soalnya adalah dia ada 1 dipecah jadi 2 ama 3, dipecah lagi 4 5 6 7 dst

    3
    7
    1 2 3 4 5 6 7
    5
    1 2 3 4 5
    2
    3 3     

*/
void pohon(int A[], int N, int index, int sum){
    int counter = 0; // fungsinya untuk ngehitung pembuatan dari percabangan yang ada 

    sum = sum + A[index]; // misal sum nya 0 terus dia melewati 1, maka 0 + 1 jadi 1, terus kalau sumnya 1, indexnya 2, jadinya 3 

    if ( index * 2 <= N ){ // fungsinya untuk menghitung yang kiri 
        pohon(A, N, index * 2, sum); // ini buat yang genap, jadi 1 2 4 8 
        counter++; 
    }

    if ( index * 2 + 1 <= N ){ // fungsinya buat ngehitung yang kanan 
        pohon(A, N, index * 2 + 1, sum); // ini buat yang ganjil 1 3 7 
        counter++; 
    }

    if ( counter == 0 ){ // terus ini fungsinya adalah ketika nanti dia ga bercanbang dan ga sampe di maxnya, jadinya diri dia sendiri yang keprint
        printf("%d\n", sum); 
    }
}

int main(){
    int T; 
    scanf("%d", &T); 

    for ( int tc = 0; tc < T; tc++ ){
        int N; // mauu berapa banyak angka yang dimasukkan ke dalam array 
        scanf("%d", &N); 

        int A[105]; 
        for ( int i = 1; i <= N; i++ ){
            scanf("%d", &A[i]); // untuk menyimpan banyaknya value array yang ada 
        }

        int index = 1, sum = 0; // fungsi index itu karena daun pertamanya kan dimulai dari 1, kalau sumnya emang harus diinisialisasi dengan 0 biar kereset terus 
        printf("Case #%d:\n", tc+1); 
        pohon(A, N, index, sum);  
    }
}