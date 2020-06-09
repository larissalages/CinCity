#ifndef VIATURAS_H_INCLUDED
#define VIATURAS_H_INCLUDED
#include <string.h>


typedef struct listaCarros //lista de viaturas
{
    char nome[30];
    int conservacao;
    int qtd_chamadas; //quantas vezes ele ja foi chamado (ocorrencia)
    struct listaCarros *prox; //proximo elemento da lista

}ListaCarros;

typedef struct fila
{
   ListaCarros* ini;
   ListaCarros* fim;

}Fila;

Fila* cria_ambulancia()
{
    Fila* amb = (Fila*) malloc(sizeof(Fila));
    amb->ini = amb->fim = NULL;

    return amb;
}

Fila* cria_policia()
{
    Fila* policia = (Fila*) malloc(sizeof(Fila));
    policia->ini = policia->fim = NULL;

    return policia;
}

Fila* cria_bombeiro()
{
    Fila* bomb = (Fila*) malloc(sizeof(Fila));
    bomb->ini = bomb->fim = NULL;

    return bomb;
}

int fila_vazia(Fila* viatura) //verificar se a fila ta vazia
{
    return (viatura->ini == NULL); //se retornar 1 a fila ta vazia, se retornar 0 ela nao esta
}

void novoCarro(Fila *viatura, char nome[]) //adc um nome carro
{
    ListaCarros* novo = (ListaCarros*) malloc (sizeof(ListaCarros));

    novo->prox = NULL; //novo passa a ser o ultimo

    if(!fila_vazia(viatura)) //Se a fila nao estiver vazia
    {
        viatura->fim->prox = novo;
    }
     else
    {
        viatura->ini = novo;
        viatura->fim = novo;
    }

    strcpy(novo->nome, nome);
    novo->conservacao = 100;
    novo->qtd_chamadas = 0;

}

void inserir_carro(Fila* viatura, ListaCarros* no) //insere um ponteiro pra fila e um no ja criado
{
    no->prox = NULL; //vai inserir no final, o novo passa a ser o ultimo
    if(!fila_vazia(viatura)) //Se a fila nao estiver vazia
    {
        viatura->fim = no;
    }
    else
    {
        viatura->ini = no;
    }

    viatura->fim = no;
}

void ferro_velho(Fila* viatura) //so vai pro ferro_velho se o estado de conservação for menor que 15
{                               //O carro é realmente destruido
    ListaCarros* t;
    t = viatura->ini;
    if(t->conservacao < 15)
    {
        viatura->ini = t->prox;
    }
     free(t);
}

ListaCarros* remover(Fila* viatura) //remove da lista quando acontecer um desastre
{
    if(fila_vazia(viatura))
    {
        return NULL;
    }

    ListaCarros* aux = viatura->ini;
    viatura->ini = aux->prox;
    if(viatura->ini == NULL)
    {
        viatura->fim = NULL;
    }

    return aux;
}

void percorrer(Fila *viatura) ///FUNÇÃO DESNECESSARIA
{
  ListaCarros *aux;
  aux = viatura->ini;

  while(aux->prox != NULL)
  {
      aux = aux->prox;
  }
}

void liberar_fila(Fila* f) //desalocar as filas
{
    ListaCarros* q = f->ini;
    while(q != NULL)
    {
        ListaCarros* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
}

void imprimir_filas(Fila* viatura) ///FUNÇÃO DE USO PESSOAL NOSSO, SO PRA TESTAR SE AS COISAS AINDA DÃO CERTO, APAGAR ISSO DEPOIS
{
    ListaCarros* aux;
    aux = viatura->ini;

    while(aux != NULL)
    {
        printf("%s ",aux->nome);
        printf("%d ",aux->conservacao);
        aux = aux->prox;

    }
}

#endif // VIATURAS_H_INCLUDED
