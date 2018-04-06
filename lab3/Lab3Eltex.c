//Программа сортирует сотрудников по году рождения
#include <stdio.h>
#include <stdlib.h>
#define N 8
struct rab{
  char fam[50];//фамилия
  int god;//год рождения
  int nomer;//номер отдела
  int oklad;//оклад
};

typedef struct rab sotrudniki;

void vvodSotrud(sotrudniki *sotr){
    printf("Введите фамилию:");
    scanf("%s", sotr->fam);
    printf("Введите год рождения:");
    scanf("%d", &sotr->god);
    printf("Введите номер отдела:");
    scanf("%d", &sotr->nomer);
    printf("Введите оклад:");
    scanf("%d", &sotr->oklad);
}

static int cmp(const void *p1, const void *p2){
    sotrudniki * st1 = *(sotrudniki**)p1;
    sotrudniki * st2 = *(sotrudniki**)p2;
    return st2->god - st1->god;
}

int main(int argc, char **argv){
    int count;
    printf("Введите кол-во сотрудников:");
    scanf("%d", &count);
    sotrudniki** sotr = (sotrudniki**)malloc(sizeof(sotrudniki**)*count);
    for (int i = 0; i < count ; i++)
    {
        sotr[i] = (sotrudniki*) malloc (sizeof(sotrudniki));
        vvodSotrud(sotr[i]);
    } 
    qsort(sotr, count, sizeof(sotrudniki*), cmp);
    printf("Фамилия сотрудника:%s\n", sotr[0]->fam);
    printf("Год рождения:%d\n", sotr[0]->god);
    
    for (int i = 0; i < count; ++i)
    {
    	printf("Фамилия сотрудника:%s\n", sotr[i]->fam);
    	printf("Год рождения:%d\n", sotr[i]->god);
    	printf("Номер отдела:%d\n",  sotr[i]->nomer);
    	printf("Оклад:%d\n",  sotr[i]->oklad);
    }

    for (int i = 0; i < count; i++)
    {
    	free(sotr[i]);
    }
    free(sotr);
    return 0;
}