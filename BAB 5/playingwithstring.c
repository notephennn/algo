#include <stdio.h> 
#include <string.h>

int main(){
    int T; 
    scanf("%d", &T); getchar();

    for (int tc = 1; tc <= T; tc++)
    {
        char kata[1005]; 
        scanf("%[^\n]", kata); getchar(); 

        int len = strlen(kata);

        int M; 
        scanf("%d", &M); 
        getchar(); 
        for (int i = 0; i < M; i++)
        {
            char awal, berubah; 
            scanf("%c %c", &awal, &berubah); 
            getchar(); 
            for (int j = 0; j < len; j++)
            {
                if (kata[j]  == awal) kata[j] = berubah;
            }
            
        }
        printf("Case #%d: %s\n", tc, kata);
    }
    
}