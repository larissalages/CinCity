#include "Crimes.h"
#include "PrepararViaturas.h"
#include "Combate.h"
#include "Declarar.h"
#ifndef OUTRASFUNCOES1_H_INCLUDED
#define OUTRASFUNCOES1_H_INCLUDED


void ler_entrada(char matriz_terreno[][17], Entrada *entrada_dados)
{
    FILE* entrada;
    char c;
    int i;
    int j;

    entrada = fopen("input.txt", "r");

    if (entrada == NULL)
    {
        printf("Nao foi possivel carregar o jogo\n");
        exit(1);
    }
    else
    {

        for (i=0 ; i<19 ; i++)
        {
            for (j=0 ; j<17 ; j++)
            {
                c = fgetc(entrada);

                matriz_terreno[i][j] = c;

                c = fgetc(entrada);
            }
        }
    }


    fscanf(entrada,"%s", entrada_dados->nome_cidade);

    fscanf(entrada, "%d", &entrada_dados->populacao);

    fscanf(entrada, "%f", &entrada_dados->caixa);

    fscanf(entrada, "%d", &entrada_dados->pBombeiro->custo_aquisicao);

    fscanf(entrada, "%d", &entrada_dados->pBombeiro->custo_mensal);

    fscanf(entrada, "%d", &entrada_dados->pPolicia->custo_aquisicao);

    fscanf(entrada, "%d", &entrada_dados->pPolicia->custo_mensal);

    fscanf(entrada, "%d", &entrada_dados->pAmbulancia->custo_aquisicao);

    fscanf(entrada, "%d", &entrada_dados->pAmbulancia->custo_mensal);

    fscanf(entrada, "%d", &entrada_dados->min_habitantes);

    fscanf(entrada, "%d", &entrada_dados->rest_semanas);



    fclose(entrada);
}

int qtde_residencias(char matriz_terreno[][17], int* pop_max)
{
    int cont=0;
    int i, j;

    for (i=0 ; i<19 ; i++)
    {
        for (j=0 ; j<17 ; j++)
        {
            if (matriz_terreno[i][j] == 'R')
            {
                cont++;
            }
        }
    }

    *pop_max = (cont*10); //População maxima

    return cont;
}

void aviso_compra_viatura(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_compra = load_bitmap("viatura_comprada.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_compra, 544, 8);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>633 && mouse_x<686 && mouse_y>203 && mouse_y<239)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_compra);

}

void aviso_compra_ambulancia(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_compra = load_bitmap("ambulancia_comprada.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_compra, 544, 8);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>633 && mouse_x<686 && mouse_y>203 && mouse_y<239)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_compra);

}

void Decrementando_viatura(Fila* viatura)
{
    ListaCarros* aux = viatura->ini;
    while (aux != NULL)
    {
        aux->conservacao -= 2;
        aux = aux->prox;
    }
}

void refazer_matriz(char matriz_terreno[][17], int *aux, char letra_atual, char letra_nova)
{
    int i, j;

    for (i=0; i<19; i++)
    {
        for (j=0 ; j<17 ; j++)
        {
            if (matriz_terreno[i][j] == letra_atual)
            {
                matriz_terreno[i][j] = letra_nova;
            }
        }
    }

    *aux = 0;
}

int opcoes(Entrada *entrada_dados, float imposto, int *cont_impostos, int *aux_construcao, int *aux_destruicao, char matriz_terreno[][17], Fila *bomb, Fila *policia, Fila *amb, char matriz_desastre_aux[][17], int contCasaDesastre[6], int contFlorestaDesastre[6], int contAguaDesastre[6], int contCasaCrime[3], int contFlorestaCrime[3], int contAguaCrime[3], ListaDesastres *desastre_relatorio, int *qualDesastre, int *qualCrime, int PassouSemana)
{
    int cont = 0;
    int prob;
    //cont vai coordenar a questão dos botões, para que funcione corretamente
    ListaDesastres *aux;

    //Para apertar nos botões 'Contratar', 'Campanhas, 'Construtor'
    ///É necessario ser um laço, no allegro tudo é laço


    while ((mouse_b&1 && mouse_x>577 && mouse_x<727 && mouse_y>278 && mouse_y<339) || key[KEY_F1])
    {
        cont = 1;
    }
    while ((mouse_b&1 && mouse_x>577 && mouse_x<728 && mouse_y>357 && mouse_y<417) || key[KEY_F2])
    {
        cont = 2;
    }
    while ((mouse_b&1 && mouse_x>577 && mouse_y<720 && mouse_y>440 && mouse_y<498) || key[KEY_F3])
    {
        cont = 3; //Construtor
    }
    while ((mouse_b&1 && mouse_x>574 && mouse_x<779 && mouse_y>524 && mouse_y<573) || key[KEY_F12])
    {
        cont =  4; //Passar semanas
        PassouSemana = 1;
    }

    //A verificação dos outros cont's é feita na main
    if (cont == 4)
    {
        /*O 'if' a seguir testa se a quantidade de semanas ainda pode ser decrementada, para isso a qtde de
        semanas tem que ser positiva e para que o jogo continue ainda deve haver dinheiro em caixa*/
        if (entrada_dados->rest_semanas>=1 && entrada_dados->caixa > 0)
        {
            entrada_dados->rest_semanas = entrada_dados->rest_semanas - 1; //Decrementar o numero de semanas
            (*cont_impostos)++;      //cont_impostos vai ser incrementado para saber quando já tiver passado um mês, assim os impostos serão aplicados

            if ((*cont_impostos) == 4)
            {
                (*cont_impostos)=0;  //cont_impostos é zerado para fazer a verificação correta no próximo mês
                entrada_dados->caixa = (entrada_dados->caixa) + imposto;
                entrada_dados->caixa = (entrada_dados->caixa) - ((entrada_dados->pPolicia->custo_mensal) + (entrada_dados->pAmbulancia->custo_mensal) + (entrada_dados->pBombeiro->custo_mensal));

                //decrementar as viaturas em 2%
                //bombeiro
                Decrementando_viatura(bomb);

                //policia
                Decrementando_viatura(policia);

                //ambulância
                Decrementando_viatura(amb);

            }
        }
        else
        {
            ///Ajeitar esse printf (colocar um aviso com imagens e além disso fazer a verificação pra saber se a pessoa ganhou ou perdeu)
            printf("O Jogo acabou\n");

            exit(0);
        }


        /*Ajeita as imagens de construir/destruir(os if's abaixo vão verificar os valores de aux_construir e
        aux_destruir para assim substituir a matriz_terreno pelos caracteres corretos e assim bitmaps corretos)*/

        //chamar a função que vai substituir a os itens alterados na matriz pelo item original

        if (*aux_construcao == 1)
        {
            //De construção para residência
            refazer_matriz(matriz_terreno, aux_construcao, 'C', 'R');
        }
        else if (*aux_construcao == 2)
        {
            //De construcao para floresta
            refazer_matriz(matriz_terreno, aux_construcao, 'C', 'V');
        }
        else if (*aux_construcao == 3)
        {
            //De construcao para agua
            refazer_matriz(matriz_terreno, aux_construcao, 'C', 'A');
        }

        if (*aux_destruicao == 1)
        {
            //De destruicao(residencia) para terra
            refazer_matriz(matriz_terreno, aux_destruicao, 'D', 'T');
        }
        else if (*aux_destruicao == 2)
        {
            //De destruicao(floresta) para terra
            refazer_matriz(matriz_terreno, aux_destruicao, 'D', 'T');
        }
        else if (*aux_destruicao == 3)
        {
            //De detruicao(agua) para terra
            refazer_matriz(matriz_terreno, aux_destruicao, 'D', 'T');
        }


        //Vai trabalhar com o índice de desastres agora
        //temos que considerar que há metade de chance de não ocorrer nada, a relação entre os desastres e a paz na cidade é metade, metade, e o mesmo para crimes

        prob = rand()%4;

        if (prob == 1)
        {
            aux = desastre_relatorio;
            desastre_relatorio = (ListaDesastres*) malloc(sizeof(ListaDesastres));
            desastre_relatorio->prox = aux;
            Desastres(entrada_dados, matriz_terreno, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, contAguaDesastre, pInc, pEnch, pMeteoro, pAlienigena, pInvMST, pProva, pAssalto, pMorte, pChacina, desastre_relatorio, qualDesastre);
        }
        if (prob == 2)
        {
            Crimes(matriz_terreno, matriz_desastre_aux, contCasaCrime, contFlorestaCrime, contAguaCrime, qualCrime);
        }
        //Se o numero sorteado for 0 não ocorre nem crimes nem desastres
    }

    return cont;
}

#endif // OUTRASFUNCOES1_H_INCLUDED
