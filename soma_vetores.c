#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int somar_vetores(int vetor1, int vetor2, int **soma_vetores, int tamanho1,int tamanho2)
{

}



int escanear_listas(char *str1, char *str2, int **v1, int **v2, int *tamanho1, int *tamanho2)
{
    scanf("%s", str1);
    scanf("%s", str2);

    *tamanho1 = strlen(str1);
    *tamanho2 = strlen(str2);

    int diferenca = 0;

    if(*tamanho1 > *tamanho2){
        *v1 = (int*) malloc((*tamanho1) * sizeof(int));
        *v2 = (int*) malloc((*tamanho1) * sizeof(int));
        diferenca = *tamanho1 - *tamanho2;
    }
    else{
        *v1 = (int*) malloc((*tamanho2) * sizeof(int));
        *v2 = (int*) malloc((*tamanho2) * sizeof(int));
        diferenca = *tamanho2 - *tamanho1;
    }

    if(*v1 == NULL || *v2 == NULL){
        return 0;
    }

    if(*tamanho1 > *tamanho2){
        for(int i = 0; i < *tamanho1; i++){
            (*v1)[i] = str1[i] - '0';
        }

        for(int i = 0; i < *tamanho1; i++){
            if(i >= *tamanho2){
                (*v2)[i] = 0;
            }
            else{
               (*v2)[i] = str2[i] - '0';
            }
        }
    }
    else{
        for(int i = 0; i < *tamanho2; i++){
            if(i >= *tamanho1){
                (*v1)[i] = 0;
            }
            else{
                (*v1)[i] = str1[i] - '0';
            }
        }

        for(int i = 0; i < *tamanho2; i++){
               (*v2)[i] = str2[i] - '0';
        }
    }

    if(*tamanho1 > *tamanho2) {
        *tamanho2 = *tamanho1;
    } else {
        *tamanho1 = *tamanho2;
    }

    return 1;
}
int main()
{
    char = str1[100];
    char = str2[100];

    int *v1 = NULL;
    int *v2 = NULL;
    int tamanho1 = 0, tamanho2 = 0;

    escanear_listas(str1,str2,&v1, &v2,&tamanho1,&tamanho2);

    *vetor_soma = NULL;

    somar_vetores(v1,v2, &vetor_soma, tamanho1,tamanho2);
}
