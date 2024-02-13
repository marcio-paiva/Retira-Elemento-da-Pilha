typedef int TChave;

typedef struct {
    TChave Chave;
}TItem;

typedef struct TCelulaEst {
    TItem item;
    struct TCelulaEst* pProx;
}TCelula;

typedef struct {
    TCelula* pFundo;
    TCelula* pTopo;
    int tamanho;
}TPilha;

void FPVazia (TPilha* pPilha);

int PVazia (TPilha* pPilha);

int PTamanho (TPilha* pPilha);

int Empilha (TPilha* pPilha, TItem* pItem);

int Desempilha (TPilha* pPilha, TItem* pItem);

int DesempilhaEspecial (TPilha* pPilha, TItem* pItem);

void Imprime(TPilha* pPilha);