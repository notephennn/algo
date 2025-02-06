#include <stdio.h> 
#include <string.h> 

int main(){ 
    int T; 
    scanf("%d", &T); 
    getchar();

    for (int tc = 1; tc <= T; tc++)
    {
        char kata[1005]; // funngsinya buat masukin kalimatnya
        scanf("%[^\n]", &kata); 
        getchar();

        int len = strlen(kata);  
        printf("Case %d: ", tc);
        for (int i = 0; i < len; i++)
        {
            printf("%d", kata[i]); // mengubah ke asciinya 
            if (i < len - 1)
            {
                printf("-");
            }
            
        }
        printf("\n");
    }
    
}