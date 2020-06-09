#ifndef CAMPANHAS_H_INCLUDED
#define CAMPANHAS_H_INCLUDED
#include "PrepararViaturas.h"
#include "Viaturas.h"

void Manutencao_viatura(Fila* viatura)
{
   ListaCarros* aux = viatura->ini;
   while(aux != NULL)
   {
	aux->conservacao += 15;
	aux = aux->prox;
   }
}

int campanhas(BITMAP *tela)
{
    BITMAP* campanhas = load_bitmap("campanhas.bmp", NULL);
    BITMAP* buffer = create_bitmap(800,600);
    BITMAP* mouse = load_bitmap("mouse2.bmp",NULL);
    int cont;


    while (!mouse_b&1)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, campanhas, 540, 9);
        draw_sprite(buffer,mouse,mouse_x,mouse_y);
        draw_sprite(screen,buffer,0,0);

        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>96 && mouse_y<130)
        {
            //manutenção bombeiros
            cont=1;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>157 && mouse_y<190)
        {
            //manutencao ambulancias
            cont=2;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>215 && mouse_y<247)
        {
            //manutencao policias
            cont=3;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>276 && mouse_y<308)
        {
            //propaganda da cidade
            cont=4;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>333 && mouse_y<367)
        {
            //infra-estrutura
            cont=5;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>391 && mouse_y<426)
        {
            //promessas politicas
            cont=6;
            mouse_x = -50;
        }
        if (mouse_b&1 && mouse_x>565 && mouse_x<740 && mouse_y>450 && mouse_y<483)
        {
            //impostos
            cont=7;
            mouse_x = -50;
        }
    }


    destroy_bitmap(campanhas);
    destroy_bitmap(mouse);
    destroy_bitmap(buffer);

    return cont;
}

void efetivar_campanha(int aux_campanha,Fila* bomb, Fila* amb, Fila* policia, Entrada* entrada_dados, float* taxa_imposto)
{

    if (aux_campanha == 1)
    {
        //manutenção bombeiros
         Manutencao_viatura(bomb);
         imprimir_filas(bomb); ///TIRAR ISSO AQUI DEPOIS

         entrada_dados->caixa = entrada_dados->caixa - 1500;  //decrementa o custo da campanha do caixa
    }
    else if (aux_campanha == 2)
    {
        //manutençao ambulancias
         Manutencao_viatura(amb);

         entrada_dados->caixa = entrada_dados->caixa - 1850;
    }
    else if (aux_campanha == 3)
    {
        //manutenção policia
        Manutencao_viatura(policia);

        entrada_dados->caixa = entrada_dados->caixa - 1000;
    }
    else if (aux_campanha == 4)
    {
        //propaganda da cidade
        ///falta ajustar a taxa de imigração
        entrada_dados->caixa = entrada_dados->caixa - 4000;
    }
    else if (aux_campanha == 5)
    {
        //infra-estrutura
        ///falta ajustar a taxa de imigração
        entrada_dados->caixa = entrada_dados->caixa - 3000;
    }
    else if (aux_campanha == 6)
    {
        //promessas políticas
        *taxa_imposto = *taxa_imposto + 0.05;
        entrada_dados->caixa = entrada_dados->caixa - 1000;
    }
    else if (aux_campanha == 7)
    {
        //redução impostos
        *taxa_imposto = *taxa_imposto - 0.05;
        entrada_dados->caixa = entrada_dados->caixa - 200;
    }


}

#endif // CAMPANHAS_H_INCLUDED
