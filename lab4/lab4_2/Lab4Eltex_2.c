#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp1;
    FILE *fp2;
    char b;
    char c;

    if ((fp1 = fopen("test.txt", "r")) == NULL)
    {
        printf("Ошибка при открытии файла test.txt.\n");
        exit(1);
    }
    else
        printf("Файл test.txt открыт.\n");
    
    if ((fp2 = fopen("test.html", "w")) == NULL)
    {
        printf("Ошибка при открытии файла test.html.\n");
    }
    else
        printf("Файл test.html открыт.\n");
    
    printf("Какой символ из текста хотите удалить?\nВведите символ:");
    scanf("%c", &b);

    while ((c = fgetc (fp1))!= EOF)
    {
        if (c != b)
        {
            fputc(c, fp2);
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    return 0;
}
