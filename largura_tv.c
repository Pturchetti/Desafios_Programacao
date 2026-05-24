#include <stdio.h>


int main()
{
    int numeros;
    int altura = 1;
    int largura = 0;
    char quebra;
    int descobrindo_largura = 1;
    
    while(scanf("%d", &numeros) == 1){
        if(numeros == 3){
            break;
        }

        if(descobrindo_largura == 1){
            largura++;
        }

        scanf("%c", &quebra);

        if(quebra == '\n'){
            descobrindo_largura = 0;
            altura++;
        }

    }

    printf("%d %d", altura, largura);
    return 0;

}