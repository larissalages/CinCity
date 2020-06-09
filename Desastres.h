#ifndef DESASTRES_H_INCLUDED
#define DESASTRES_H_INCLUDED
#endif // DESASTRES_H_INCLUDED
#include "Combate.h"
#include "Declarar.h"
#include <string.h>

void zeraVetor(int vetorI[10], int vetorJ[10])
{
    int i, j;

    for (i=0 ; i<10 ; i++)
    {
        vetorI[i] = 0;
    }

    for (j=0 ; j<10 ; j++)
    {
        vetorJ[i] = 0;
    }
}

void incendio(char matriz_terreno[][17], int *area_incendio, char matriz_desastres_aux[][17], int contCasa[6], int contFloresta[6], int vetorI[10], int vetorJ[10])
{
    int a;    //vai auxiliar no laço para a impressão das outras sprites de fogo no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que o incendio vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento do fogo, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites do fogo
    if (matriz_terreno[inicio_y][inicio_x] == 'V' ||  matriz_terreno[inicio_y][inicio_x] == 'R'  ||   matriz_terreno[inicio_y][inicio_x] == 'E' ||   matriz_terreno[inicio_y][inicio_x] == 'T')
    {

        if (matriz_terreno[inicio_y][inicio_x] == 'V')
        {
            contFloresta[0]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'R')
        {
            contCasa[0]++;
        }

        matriz_desastres_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'F';
        (*area_incendio)++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;


        for (a=0 ; a<(Area-1) ; a++,b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'V' ||  matriz_terreno[i][j] == 'R'  ||   matriz_terreno[i][j] == 'E' ||   matriz_terreno[i][j] == 'T')
            {
                if (matriz_terreno[i][j] == 'V')
                {
                    contFloresta[0]++;
                }
                else if (matriz_terreno[i][j] == 'R')
                {
                    contCasa[0]++;
                }

                matriz_desastres_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'F';
                (*area_incendio)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }

    }
}

void enchentes(char matriz_terreno[][17], int *area_enchente, char matriz_desastre_aux[][17], int contCasa[6], int contFloresta[6], int vetorI[10], int vetorJ[10])
{
    int a;    //vai auxiliar no laço para a impressão das outras sprites de enchente no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que a enchente vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento da enchente, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites do enchente
    if (matriz_terreno[inicio_y][inicio_x] == 'V' ||  matriz_terreno[inicio_y][inicio_x] == 'R'  ||   matriz_terreno[inicio_y][inicio_x] == 'E' ||   matriz_terreno[inicio_y][inicio_x] == 'T')
    {
        if (matriz_terreno[inicio_y][inicio_x] == 'V')
        {
            contFloresta[1]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'R')
        {
            contCasa[1]++;
        }


        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'N';   //pois, 'E' já é estrada
        (*area_enchente)++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;


        for (a=0 ; a<(Area-1) ; a++, b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'V' ||  matriz_terreno[i][j] == 'R'  ||   matriz_terreno[i][j] == 'E' ||   matriz_terreno[i][j] == 'T')
            {
                if (matriz_terreno[i][j] == 'V')
                {
                    contFloresta[1]++;
                }
                else if (matriz_terreno[i][j] == 'R')
                {
                    contCasa[1]++;
                }

                matriz_desastre_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'N';
                (*area_enchente)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }
    }
}

void meteoritos(char matriz_terreno[][17], int *area_meteorito, char matriz_desastre_aux[][17], int contCasa[6], int contFloresta[6], int contAgua[6], int vetorI[10], int vetorJ[10])
{
    int a;    //vai auxiliar no laço para a impressão das outras sprites de meteorito no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que o meteorito vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento do meteorito, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites do meteorito

    if (matriz_terreno[inicio_y][inicio_x] == 'A'  ||  matriz_terreno[inicio_y][inicio_x] == 'V' ||  matriz_terreno[inicio_y][inicio_x] == 'R'  ||   matriz_terreno[inicio_y][inicio_x] == 'E' ||   matriz_terreno[inicio_y][inicio_x] == 'T')
    {
        if (matriz_terreno[inicio_y][inicio_x] == 'A')
        {
            contAgua[2]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'V')
        {
            contFloresta[2]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'R')
        {
            contCasa[2]++;
        }


        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'M';
        (*area_meteorito)++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;


        for (a=0 ; a<(Area-1) ; a++, b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'A'  ||  matriz_terreno[i][j] == 'V' ||  matriz_terreno[i][j] == 'R'  ||   matriz_terreno[i][j] == 'E' ||   matriz_terreno[i][j] == 'T')
            {

                if (matriz_terreno[i][j] == 'A')
                {
                    contAgua[2]++;
                }
                else if (matriz_terreno[i][j] == 'V')
                {
                    contFloresta[2]++;
                }
                else if (matriz_terreno[i][j] == 'R')
                {
                    contCasa[2]++;
                }


                matriz_desastre_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'M';
                (*area_meteorito)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }
    }
}

void MST(char matriz_terreno[][17], int *area_mst, char matriz_desastre_aux[][17], int vetorI[10], int vetorJ[10])
{
    int a;    //vai auxiliar no laço para a impressão das outras sprites de MST no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que o MST vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento do MST, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites do MST
    if (matriz_terreno[inicio_y][inicio_x] == 'T')
    {
        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'S';
        (*area_mst)++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;


        for (a=0 ; a<(Area-1) ; a++, b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'T')
            {
                matriz_desastre_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'S';
                (*area_mst)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }
    }
}

void alien(char matriz_terreno[][17], int *area_alien, char matriz_desastre_aux[][17], int contCasa[6], int contFloresta[6], int contAgua[6], int vetorI[10], int vetorJ[10])
{
    int a;    //vai auxiliar no laço para a impressão das outras sprites de alien no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que o alien vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento do alien, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites do alien
    if (matriz_terreno[inicio_y][inicio_x] == 'A'  ||  matriz_terreno[inicio_y][inicio_x] == 'V' ||  matriz_terreno[inicio_y][inicio_x] == 'R'  ||   matriz_terreno[inicio_y][inicio_x] == 'E' ||   matriz_terreno[inicio_y][inicio_x] == 'T')
    {
        if (matriz_terreno[inicio_y][inicio_x] == 'A')
        {
            contAgua[4]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'V')
        {
            contFloresta[4]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'R')
        {
            contCasa[4]++;
        }


        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'L';
        (*area_alien)++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;


        for (a=0 ; a<(Area-1) ; a++, b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'A'  ||  matriz_terreno[i][j] == 'V' ||  matriz_terreno[i][j] == 'R'  ||   matriz_terreno[i][j] == 'E' ||   matriz_terreno[i][j] == 'T')
            {
                if (matriz_terreno[i][j] == 'A')
                {
                    contAgua[4]++;
                }
                else if (matriz_terreno[i][j] == 'V')
                {
                    contFloresta[4]++;
                }
                else if (matriz_terreno[i][j] == 'R')
                {
                    contCasa[4]++;
                }


                matriz_desastre_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'L';
                (*area_alien)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }

    }

}

void prova_ip(char matriz_terreno[][17], int *area_prova, char matriz_desastre_aux[][17], int contCasa[6], int vetorI[10], int vetorJ[10])
{

    int a;   //vai auxiliar no laço para a impressão das outras sprites de IP no jogo
    int Area;
    int inicio_x;  //variáveis vão "armazenar", os indices da matriz em que será iniciado o desastre
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado; //para o modo de alastramento em quadrado
    int i, j; //variáveis que vão me auxiliar no acesso a matriz
    int b = 1;

    Area = rand()%10 + 1; //quantidade de blocos que a prova de IP vai atingir (qtde vai de zero a nove)


    //'inicio_x' e inicio_y' serão escolhidos
    inicio_x = rand()%17; //atenção! os índices estão começando do zero
    inicio_y = rand()%19;

    //alocando espaço para os vetores
    vetor_x = (int*) malloc((Area-1)*sizeof(int));   //'Area-1', pois o inicio_x, já guarda uma posição, a mesma ideia para inicio_y
    vetor_y = (int*) malloc((Area-1)*sizeof(int));

    //calcula modo de alastramento da prova, aleatoriamente
    modo_aleatorio = rand()%5;


    if (inicio_y != 19)
        y = inicio_y;

    if (inicio_x != 17)
        x = inicio_x;


    //alastramento horizontal
    if (modo_aleatorio == 0)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento vertical
    else if (modo_aleatorio == 1)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (y < 19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal principal
    else if (modo_aleatorio == 2)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x<17)
                x = x + 1;

            if (y<19)
                y = y + 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento diagonal secundária
    else if (modo_aleatorio == 3)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            if (x>0)
                x = x - 1;

            if (y > 0)
                y = y - 1;

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }
    //alastramento quadrado
    else if (modo_aleatorio == 4)
    {
        for (a=0 ; a<(Area-1) ; a++)
        {
            aleatorio_quadrado = rand()%4;

            if (aleatorio_quadrado == 0)
            {
                if (x<17)
                    x = x + 1;

                if (y>0)
                    y = y - 1;
            }
            else if (aleatorio_quadrado == 1)
            {
                if (x>0)
                    x = x - 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 2)
            {
                if (x<17)
                    x = x + 1;

                if (y<19)
                    y = y + 1;
            }
            else if (aleatorio_quadrado == 3)
            {
                if (x>0)
                    x = x - 1;

                if (y>0)
                    y = y - 1;
            }

            vetor_x[a]= x;
            vetor_y[a]= y;
        }
    }


    //Para imprimir as sprites da prova
    if (matriz_terreno[inicio_y][inicio_x] == 'R')
    {
        contCasa[5]++;
        vetorI[0] = inicio_y;
        vetorJ[0] = inicio_x;
        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'I';
        (*area_prova)++;


        for (a=0 ; a<(Area-1) ; a++, b++)
        {
            i = vetor_y[a];
            j = vetor_x[a];

            if (matriz_terreno[i][j] == 'R')
            {
                contCasa[5]++;

                matriz_desastre_aux[i][j] = matriz_terreno[i][j];
                matriz_terreno[i][j] = 'I';
                (*area_prova)++;
                vetorI[b] = i;
                vetorJ[b] = j;
            }
        }

    }

}

void Desastres(Entrada *entrada_dados, char matriz_terreno[][17], char matriz_desastre_aux[][17], int contCasaDesastre[6], int contFlorestaDesastre[6], int contAguaDesastre[6], Incendio *pInc, Enchentes *pEnch, Meteoritos *pMeteoro, Alien *pAlienigena, mst *pInvMST, IP *pProva, Assalto *pAssalto, Morte *pMorte, Chacina *pChacina, ListaDesastres *desastre_relatorio, int *qualDesastre)
{
    int desastre = 0;
    int area_prova = 0;  //variáveis de área vão auxiliar para calcular o sucesso dos desastres
    int area_alien = 0;
    int area_mst = 0;
    int area_meteoritos = 0;
    int area_enchentes = 0;
    int area_incendio = 0;
    int sucesso;
    SAMPLE *som_incendio = load_sample("incendio.wav");
    SAMPLE *som_prova = load_sample("torture.wav");
    SAMPLE *som_enchentes = load_sample("enchente.wav");
    SAMPLE *som_alien = load_sample("alien.wav");
    SAMPLE *som_meteorito = load_sample("meteorito.wav");
    SAMPLE *som_mst = load_sample("mst.wav");

    desastre = rand()%1004 + 1; //probabilidade de acontecer
    //Prova IP = ocorre se ele sortear numeros de 1 a 9
    //Inavasão alienigena = ocorrer se ele sortear numeros de 10 a 21
    //Invasão MST = ocorre se ele sortear numeros de 22 a 102
    //Meteoritos = ocorre se ele sortear numeros de 103 a 253
    //Enchente = ocorre se ele sortear numeros de 254 a 604
    //Incêndio = ocorre se ele sortear numeros de 605 a 1004

    zeraVetor(vetorI, vetorJ); //zera as variáveis para que estejam certas na próxima chamada de função

    ///A LISTA DE DESASTRES SÓ ESTÁ SENDO PREENCHIDA COM TIPO E SEMANA EM QUE OCORREU
    if (desastre >= 1 && desastre <= 9)
    {
        prova_ip(matriz_terreno, &area_prova, matriz_desastre_aux, contCasaDesastre, vetorI, vetorJ);

        if (area_prova != 0)
        {
            *qualDesastre = 1;
            play_sample(som_prova, 120, 128, 1000, FALSE);
            //  sucesso = (2 * (ceil(area_prova/3)))///dividir por semanas em que conseguiu resolver o desastre
            pProva->Area = area_prova;   //se a area da prova for diferente de zero é pq ela realmente ocorreu e nesse caso deverá ser combate
        }

        //Para preencher a lista
        strcpy(desastre_relatorio->tipo, "Prova IP");
        desastre_relatorio->semana = entrada_dados->rest_semanas;

    }
    else if (desastre >= 10 && desastre<=21)
    {
        alien(matriz_terreno, &area_alien, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, contAguaDesastre, vetorI, vetorJ);

        if (area_alien != 0)
        {
            *qualDesastre = 2;
            play_sample(som_alien, 120, 128, 1000, FALSE);
            //   sucesso = (3 * ceil(area_alien/3))///dividir por semanas em que conseguiu resolver o desastre
            pAlienigena->Area = area_alien;
        }

        //Para preencher lista
        strcpy(desastre_relatorio->tipo, "Invasao Alienigena");
        desastre_relatorio->semana = entrada_dados->rest_semanas;
    }
    else if (desastre >= 22 && desastre <=102)
    {
        MST(matriz_terreno, &area_mst, matriz_desastre_aux, vetorI, vetorJ);

        if (area_mst != 0)
        {
            *qualDesastre = 3;
            play_sample(som_mst, 150, 128, 1000, FALSE);
            //   sucesso = (ceil(area_mst/3))///dividir por semanas em que conseguiu resolver o desastre
            pInvMST->Area = area_mst;
        }

        //Para preencher lista
        strcpy(desastre_relatorio->tipo, "Invasao MST");
        desastre_relatorio->semana = entrada_dados->rest_semanas;
    }
    else if (desastre >= 103 && desastre<=253)
    {
        meteoritos(matriz_terreno, &area_meteoritos, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, contAguaDesastre, vetorI, vetorJ);

        if (area_meteoritos != 0)
        {
            *qualDesastre = 4;
            play_sample(som_meteorito, 120, 128, 1000, FALSE);
            //   sucesso = (2 * ceil(area_meteoritos/3))///dividir por semanas em que conseguiu resolver o desastre
            pMeteoro->Area = area_meteoritos;
        }

        //Para preencher lista
        strcpy(desastre_relatorio->tipo, "Meteoros");
        desastre_relatorio->semana = entrada_dados->rest_semanas;
    }
    else if (desastre >= 254 && desastre<=604)
    {
        enchentes(matriz_terreno, &area_enchentes, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, vetorI, vetorJ);

        if (area_enchentes != 0)
        {
            *qualDesastre = 5;
            play_sample(som_enchentes, 120, 128, 1000, FALSE);
            //   sucesso = (3 * ceil(area_enchentes/3))///dividir por semanas em que conseguiu resolver o desastre

            pEnch->Area = area_enchentes;
        }

        //Para preencher lista
        strcpy(desastre_relatorio->tipo, "Enchente");
        desastre_relatorio->semana = entrada_dados->rest_semanas;
    }
    else if (desastre >= 605 && desastre <= 1004)
    {
        incendio(matriz_terreno, &area_incendio, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, vetorI, vetorJ);

        if (area_incendio != 0)
        {
            *qualDesastre = 6;
            play_sample(som_incendio, 100, 128, 1000, FALSE);
            //   sucesso = (2 * ceil(area_incendio/3))///dividir por semanas em que conseguiu resolver o desastre

            pInc->Area = area_incendio;

            //Para preencher lista
            strcpy(desastre_relatorio->tipo, "Incendio");
            desastre_relatorio->semana = entrada_dados->rest_semanas;
            inicializarCombateIncendio(pInc);
        }
    }

    ///AS VARIÁVEIS QUE CONTAM QUANTOS SLOTS ESTÃO SENDO ATACADOS JÁ ESTÁ FUNCIONANDO
    ///LEMBRAR DE ACRESCENTAR AS MÉDIAS PONDERADAS
    ///SUCESSO_DESASTRES EU DECLAREI NA MAIN A IDEIA É PASSAR POR REFERENCIA E ALTERAR O CONTEUDO SEMPRE QUE HOUVER UM DESASTRE.
    //(*sucesso_desastres) = (*sucesso_desastres) + sucesso;
}
