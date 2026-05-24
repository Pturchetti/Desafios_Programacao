#include <stdio.h>

#define MAX_L 100
#define MAX_C 100
#define MAX_P_RESPOSTA 500

void def_resposta(int x,int y,int picos_x[],int picos_y[],int *ponteiro_contador)
{

    int indice = *ponteiro_contador;

    picos_x[indice] = x;
    picos_y[indice] = y;

    (*ponteiro_contador)++;

}

int verificador(int analise[])
{
    for(int i = 0;i<8;i++){
        if(analise[i] !=1){
            return 0;
        }
    }
    return 1;
}

int analise_pico(int matriz[MAX_L][MAX_C], int i, int j, int linhas, int colunas)
{
    int analise[8] ={0,0,0,0,0,0,0,0};

    if (i-1<0 || matriz[i][j]>matriz[i-1][j]){
        analise[0] = 1;
    }
    if(i+1>=linhas || matriz[i][j]>matriz[i+1][j]){
        analise[1] = 1;
    }
    if(j+1>=colunas || matriz[i][j]>matriz[i][j+1]){
        analise[2] = 1;
    }
    if(j-1<0 || matriz[i][j]>matriz[i][j-1]){
        analise[3] = 1;
    }
    if(i-1<0 || j-1<0 || matriz[i][j]>matriz[i-1][j-1]){
        analise[4] = 1;
    }
    if(i+1>=linhas || j+1>=colunas || matriz[i][j]>matriz[i+1][j+1]){
        analise[5] = 1;
    }
    if(i+1>=linhas || j-1<0 || matriz[i][j]>matriz[i+1][j-1]){
        analise[6] = 1;
    }
    if(i-1<0 || j+1>=colunas || matriz[i][j]>matriz[i-1][j+1]){
        analise[7] = 1;
    }

    int analise_final = verificador(analise);

    if (analise_final == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int m[MAX_L][MAX_C];
    for (int i = 0;i<linhas;i++){
        for(int j = 0;j<colunas;j++){
            scanf("%d", &m[i][j]);
        }
    }

    int contador = 0;
    int picos_i[MAX_P_RESPOSTA];
    int picos_j[MAX_P_RESPOSTA];

    for(int i = 0;i<linhas;i++){
        for(int j = 0;j<colunas;j++){
            int vizinho = analise_pico(m,i,j,linhas,colunas);
            if (vizinho == 1){

                def_resposta(i,j,picos_i,picos_j, &contador);
            }
        }
    }
    printf("%d\n", contador);

    for(int i = 0;i<contador;i++){
        printf("%d %d\n", picos_i[i],picos_j[i]);
    }
    return 0;
}