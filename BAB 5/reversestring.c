#include <stdio.h> 
#include <string.h> 

int main(){
    int T; 
    scanf("%d", &T); 
    getchar(); 
    for (int tc = 1; tc <= T; tc++)
    {
        char input[1005]; 
        scanf("%[^\n]", &input); 
        getchar(); 

        int len = strlen(input); 
        printf("Case #%d : ", tc); 
        for (int i = len - 1; i >= 0; i--)
        {
            printf("%c", input[i]);
        }
        printf("\n");
    }
    
}