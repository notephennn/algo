#include <stdio.h> 
#include <string.h> 

int main(){
    int T; 
    scanf("%d", &T); getchar(); 

    for (int tc = 1; tc <= T; tc++)
    {
        char message[1005]; 
        scanf("%[^\n]", &message); 
        getchar();

        int len = strlen(message); 
        int outputArr[1000];
		for (int i = 0; i < len; i++)
		{
			char temp;
			if (message[i] >= 'A' && message[i] <= 'D')
			{
				temp = 'A';
			}
			else if (message[i] >= 'E' && message[i] <= 'H')
			{
				temp = 'E';
			}
			else if (message[i] >= 'I' && message[i] <= 'N')
			{
				temp = 'I';
			}
			else if (message[i] >= 'O' && message[i] <= 'T')
			{
				temp = 'O';
			}
			else if (message[i] >= 'U' && message[i] <= 'Z')
			{
				temp = 'U';
			}
			
			outputArr[i] = message[i] - temp; // fungsinya buat mbandingin ascii nya aja, biar bisa dikurangin
			message[i] = temp;

        }
        printf("Case #%d:\n", tc);
		printf("%s\n", message);
		for (int i = 0; i < len; i++)
			printf("%d", outputArr[i]);
		    printf("\n");
    }
    
}