#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

typedef struct{
    char nama[100]; 
    char password[100]; 
} User; 

void encrypt_password(const char *plain_password, char *encrypted_password) {
    int i = 0;
    while (plain_password[i] != '\0') {
        encrypted_password[i] = plain_password[i] + 1;
        i++;
    }
    encrypted_password[i] = '\0';
}

int binary_search(User daftarUser[], int left, int right, const char *to_search) {
    if (left > right) return -1;

    int mid = (left + right) / 2;

    if (strcmp(daftarUser[mid].nama, to_search) == 0) return mid;
    if (strcmp(daftarUser[mid].nama, to_search) < 0) return binary_search(daftarUser, mid + 1, right, to_search);
    
    return binary_search(daftarUser, left, mid - 1, to_search);
}

int main(){
    int N; 
    scanf("%d", &N); 

    User daftarUser[N];
    char pass_temp[50];	

    for ( int i = 0; i < N; i++ ) {
    	scanf("%s %s", daftarUser[i].nama, pass_temp); 
    	int length = strlen(pass_temp);
    	
    	for (int j = 0; j < length; j++){
    		pass_temp[j] += j+1;
		}
		
		strcpy(daftarUser[i].password, pass_temp);
	}


//    quick_sort_recursion(daftarUser, 0, N-1); 

    int Q; 
    scanf("%d", &Q); 

    for ( int i = 0; i < Q; i++ ){
        char input_username[50], input_password[50];
        scanf("%s %s", input_username, input_password);

        char encrypted_password[50];
        encrypt_password(input_password, encrypted_password);

        int idx = binary_search(daftarUser, 0, N - 1, input_username);

        if (idx == -1) {
            printf("Case #%d: User not found!\n", i + 1);
        } else if (strcmp(daftarUser[idx].password, input_password) == 0) {
            printf("Case #%d: Login success!\n", i + 1);
        } else {
            printf("Case #%d: Wrong password!\n", i + 1);
        }
    }
}