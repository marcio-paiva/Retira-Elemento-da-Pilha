#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void FPVazia (TPilha* pPilha) {
    pPilha->pTopo = (TCelula*)malloc(sizeof(TCelula));
    pPilha->pFundo = pPilha->pTopo;
    pPilha->pTopo->pProx = NULL;
    pPilha->tamanho = 0;
}

int PVazia (TPilha* pPilha) {
    return (pPilha->pTopo == pPilha->pFundo);
}

int PTamanho (TPilha* pPilha) {
    return (pPilha->tamanho);
}

int Empilha (TPilha* pPilha, TItem* pItem) {
    TCelula* pNovo;
    pNovo = (TCelula*)malloc(sizeof(TCelula));
    pPilha->pTopo->item = *pItem;
    pNovo->pProx = pPilha->pTopo;
    pPilha->pTopo = pNovo;
    pPilha->tamanho++;
    return 1;
}

int Desempilha (TPilha* pPilha, TItem* pItem) {
    if (PVazia(pPilha)){
        printf("\nPilha vazia.\n\n");
        return 0;
    }
    TCelula* pAux; /* celula a ser removida */
    pAux = pPilha->pTopo;
    pPilha->pTopo = pAux->pProx;
    *pItem = pAux->pProx->item;
    free(pAux);
    pPilha->tamanho--;
    return 1;
}

int DesempilhaEspecial (TPilha* pPilha, TItem *pItem){
    if (PVazia(pPilha)){
        printf("\nPilha vazia.\n\n");
        return 0;
    }
    TPilha pAux;
    TItem x;
    FPVazia(&pAux);
    while(!PVazia(pPilha)){ //loop enquanto lista nao estiver vazia em busca do elemento informado
        Desempilha(pPilha, &x); //desempilha item a item da original
        if(x.Chave == pItem->Chave){ //testa se o item em quetão é igual ao elemento informado nos argumentos
            printf("Elemento retirado com sucesso.\n\n");           
        }else{
            Empilha(&pAux, &x);  //empilha item a item na auxiliar
        }
    }
    while(!PVazia(&pAux)){ //loop para voltar elementos da pilha auxiliar para a pilha original
        Desempilha(&pAux, &x); //desempilha item a item 
        Empilha(pPilha, &x);  //empilha item a item
    }
    return 1;
}

void Imprime (TPilha* pPilha) {
    if(PVazia(pPilha)){
        printf("\nPilha vazia.\n\n");
        return;
    }
    TCelula *pAux;
    pAux = pPilha->pTopo->pProx;
    while(pAux != NULL){  //auxiliar percorre a pilha até o primeiro elemento
        printf("%d ", pAux->item.Chave);  //imprime cada elemento
        pAux = pAux->pProx; //passa para o proximo elemento
    }
}