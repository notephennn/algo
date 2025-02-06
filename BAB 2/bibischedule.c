#include <stdio.h> 

int main(){ 
    char matkul1[10], matkul2, matkul3, matkul4, matkul5;
    float jam1, menit1, jam2, menit2;

    for (int  i = 0; i <= 4; i++)
    {
    scanf("%s %f:%f-%f:%f", &matkul1, &jam1, &menit1, &jam2, &menit2); 
    printf("%s %02.0f:%02.0f-%02.0f:%02.0f\n", matkul1, jam1-1, menit1, jam2-1, menit2); 
    }
}