#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1000
int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    char buffer[N];
    if ((fp1 = fopen("test.txt", "r")) == NULL)
    {
        printf("Ошибка при открытии файла.\n");
        exit(1);
    }
    else
        printf("Файл test.txt открыт.\n");
    if ((fp2 = fopen("test.html", "w"))==NULL)
    {
        printf("Ошибка при открытии файла.\n");
    }
    else
    printf("Файл test.html открыт.\n");

    while (fgets (buffer, N, fp1) != NULL)
    {
    	fputs(buffer,fp2);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}
