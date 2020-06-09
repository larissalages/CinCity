#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
#endif // STRUCT_H_INCLUDED

typedef struct bombeiro
{
    int custo_aquisicao;
    int custo_mensal;

}Bombeiro;

typedef struct policia
{
    int custo_aquisicao;
    int custo_mensal;

}Policia;

typedef struct ambulancia
{
    int custo_aquisicao;
    int custo_mensal;

}Ambulancia;

typedef struct entrada
{
    char nome_cidade[31];
    int populacao;
    float caixa;
    Bombeiro *pBombeiro;
    Policia *pPolicia;
    Ambulancia *pAmbulancia;
    int min_habitantes;
    int rest_semanas;

}Entrada;

typedef struct listaD //lista de Desastres
{
    char tipo[20]; ///Não precisa explicar ne?
    int semana; //armazena a semana que esta acontecendo o desastre
    float custo; //custo para resolver o problema
    int tempo; //marca o tempo(em semanas) que levou ate o problema ser resolvido
    struct listaD *prox; //ponteiro para o proximo elemento da lista


}ListaDesastres;

typedef struct listaC //lista de Crimes
{
    char tipo[20];
    int semana; //armazena a semana que esta acontecendo o crime
    float custo; //custo para resolver o problema
    int tempo; //marca o tempo(em semanas) que levou ate o problema ser resolvido
    struct listaC *prox; //ponteiro para o proximo elemento da lista

}ListaCrimes;

typedef struct incendio
{
    int PontosBomb;
    int PontosAmb;
    int SlotsBomb;
    int SlotsAmb;
    int Area;
    int CustoReparacao;

}Incendio;

typedef struct enchentes
{
    int PontosBomb;
    int PontosAmb;
    int SlotsBomb;
    int SlotsAmb;
    int Area;
    int CustoReparacao;
}Enchentes;

typedef struct meteoritos
{
    int PontosBomb;
    int SlotsBomb;
    int PontosAmb;
    int SlotsAmb;
    int PontosPolicia;
    int SlotsPolicia;
    int Area;
    int CustoReparacao;
}Meteoritos;

typedef struct alien
{
    int PontosBomb;
    int SlotsBomb;
    int PontosAmb;
    int SlotsAmb;
    int PontosPolicia;
    int SlotsPolicia;
    int Area;

}Alien;

typedef struct mst
{
    int PontosPolicia;
    int SlotsPolicia;
    int Area;
}mst;

typedef struct ip
{
    int PontosAmb;
    int SlotsAmb;
    int Area;
    int CustoReparacao;
}IP;

typedef struct assalto
{
    int PontosPolicia;
    int SlotsPolicia;
    int Area;
}Assalto;

typedef struct morte
{
    int PontosAmb;
    int SlotsAmb;
    int PontosPolicia;
    int SlotsPolicia;
    int Area;
}Morte;

typedef struct chacina
{
    int PontosAmb;
    int SlotsAmb;
    int PontosPolicia;
    int SlotsPolicia;
    int Area;
    int CustoReparacao;
}Chacina;





