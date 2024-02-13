#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main(){
    TPilha x, aux;
    int opcao, temp;
    TItem a, b, c; //variaveis temporarias para enfileirar e desenfileirar.

    FPVazia(&x);
    FPVazia(&aux);

    do{
        printf("Escolha a opcao desejada: \n\n\t1 - Incluir novo elemento na pilha. \n\t2 - Retirar ultimo elemento da pilha. \n\t3 - Imprimir o conteudo da pilha. \n\t4 - Imprimir o tamanho da pilha. \n\t5 - Desenfileira item especifico. \n\t0 - Sair.\n");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("\nInforme o elemento: ");
                scanf("%d", &temp);
                a.Chave = (TChave) temp;
                Empilha(&x, &a);
                printf("\n");
                break;
            case 2:
                if(Desempilha(&x, &b)){ //se a fila nao estiver vazia, retornará 1, e o valor retirado será impresso
                    printf("\nElemento retirado da pilha: %d\n", b);
                }
                break;
            case 3:
                printf("\n---------PILHA-----------\n");
                Imprime(&x);
                printf("\n\n");
                break;
            case 4:
                printf("\nTamanho da pilha: %d\n\n", PTamanho(&x));
                break;
            case 5:
                printf("\nInforme o elemento: ");
                scanf("%d", &temp);
                c.Chave = (TChave) temp;
                DesempilhaEspecial(&x, &c);
                break;
            default:
                break;
        }
    }while(opcao != 0);

    system("pause");
    return 0;
}