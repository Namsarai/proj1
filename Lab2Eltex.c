#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h> /* для mtrace */
#include <string.h>
#define MAX_LEN 1024 /* максимальная длина строки */

char** readMas(int n){
	char buffer[MAX_LEN];
	char **mas;  //указатель на массив указателей на строки
	mas = (char **)malloc(sizeof(char *)*n);// выделяем память для массива указателей
    printf("Ваши строки:\n");
    for (int i = 0; i < n ; i++){
        scanf("%s", buffer); // читаем строку в буфер
        mas[i] = (char *)malloc(sizeof(char)*strlen(buffer)); //выделяем память для строки
        strcpy(mas[i], buffer); //копируем строку из буфера в массив указателей
    }
    return mas; 
}

char* perest(char *mas[],int N,int *p_k, int *p_min_len){	
	
	char *tmp;

	for(int j=0;j<N-1;j++){
		for (int i=0;i<N-1;i++){
			if(strlen(mas[i])>strlen(mas[i+1])){
				tmp=mas[i];
				mas[i]=mas[i+1];
				mas[i+1]=tmp;		
				*p_k=*p_k+1;
			}
		}
	}
	*p_min_len=strlen(mas[N-1]);
}

void vivod(char **mas, int n,int *p_k, int *p_min_len){
	printf("Отсортированный массив:\n");
    for (int i=0;i<n;i++)
        printf("%s\n",mas[i]);
	printf("\nКоличество перестановок - %d\nМаксимальная длина - %d\n", *p_k,*p_min_len);
}

void freeMas(char **mas, int n){
	
	for (int i = 0; i < n; i++){
        free(mas[i]); // освобождаем память для отдельной строки
    }
    free(mas); // освобождаем памать для массива указателей на строки
}

int main(){
	int min_len;
	int *p_min_len=&min_len;
	int k;
	int *p_k=&k;
	char **mas = NULL;
	int n;
	printf("Введите количество строк:");
	scanf("%d", &n);
	mas = readMas(n);
	perest(mas,n,p_k,p_min_len);
	vivod(mas,n,p_k,p_min_len);
	freeMas(mas, n);
}