#include <stdio.h>
#include <stdlib.h>

int* registrar_vetor(int tamanho)
{
    int* v =(int*) malloc(tamanho*sizeof(int));

    if(v == NULL){
        return NULL;
    }
    printf("Digite os números dentro do vetor!\n");

    for(int i = 0;i<tamanho;i++){
        scanf("%d", &v[i]);
    }
    return v;
}
void resposta(int *vetor, int tamanho, int alvo)
{

    for(int i = 0; i < tamanho - 1; i++){


        for(int j = i + 1; j < tamanho; j++){


            if(vetor[i] + vetor[j] == alvo){
                printf("[ %d %d ]\n", i, j);

            }
        }
    }
    return;
}
int main()
{
    printf("Digite um número alvo:\n");
    int alvo;
    scanf("%d", &alvo);

    printf("Digite a quantidade de números do vetor:\n");

    int tamanho;
    scanf("%d", &tamanho);

    int* v = registrar_vetor(tamanho);

    printf("Os índices dos números que somados chegam no %d são:\n", alvo);
    resposta(v,tamanho,alvo);

    free(v);
    return 0;
}
