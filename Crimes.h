#ifndef CRIMES_H_INCLUDED
#define CRIMES_H_INCLUDED
#endif // CRIMES_H_INCLUDED


//As funções de crime têm a mesma ideia das funções para desastres
void chacina(char matriz_terreno[][17], int *area_chacina, char matriz_desastre_aux[][17], int *contCasa, int *contFloresta)
{
    int a;
    int Area;
    int inicio_x;
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado;
    int i, j;

    Area = rand()%10 + 1;


    inicio_x = rand()%17;
    inicio_y = rand()%19;


    vetor_x = (int*) malloc((Area-1)*sizeof(int));
    vetor_y = (int*) malloc((Area-1)*sizeof(int));


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

        printf("%c", matriz_terreno[inicio_y][inicio_x]);
        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'H';
        (*area_chacina)++;
    }

    for (a=0 ; a<(Area-1) ; a++)
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
                contFloresta[0]++;
            }


            printf("%c", matriz_terreno[i][j]);
            matriz_desastre_aux[i][j] = matriz_terreno[i][j];
            matriz_terreno[i][j] = 'H';
            (*area_chacina)++;
        }
    }

}

void morte(char matriz_terreno[][17], int *area_morte, char matriz_desastre_aux[][17], int *contCasa, int *contFloresta)
{
    int a;
    int Area;
    int inicio_x;
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado;
    int i, j;


    Area = rand()%10 + 1;


    inicio_x = rand()%17;
    inicio_y = rand()%19;


    vetor_x = (int*) malloc((Area-1)*sizeof(int));
    vetor_y = (int*) malloc((Area-1)*sizeof(int));


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


        printf("%c", matriz_terreno[inicio_y][inicio_x]);
        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'O';
        (*area_morte)++;
        printf("%d", *area_morte);
    }

    for (a=0 ; a<(Area-1) ; a++)
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


            printf("%c", matriz_terreno[i][j]);
            matriz_desastre_aux[i][j] = matriz_terreno[i][j];
            matriz_terreno[i][j] = 'O';
            (*area_morte)++;
            printf("%d", *area_morte);
        }
    }

}

void assalto(char matriz_terreno[][17], int *area_assalto, char matriz_desastre_aux[][17],  int *contCasa, int *contFloresta)
{
    int a;
    int Area;
    int inicio_x;
    int inicio_y;
    int *vetor_x;
    int *vetor_y;
    int x = 0, y = 0;
    int modo_aleatorio;
    int aleatorio_quadrado;
    int i, j;


    Area = rand()%10 + 1;


    inicio_x = rand()%17;
    inicio_y = rand()%19;


    vetor_x = (int*) malloc((Area-1)*sizeof(int));
    vetor_y = (int*) malloc((Area-1)*sizeof(int));


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


    if (matriz_terreno[inicio_y][inicio_x] == 'V' ||  matriz_terreno[inicio_y][inicio_x] == 'R'  ||   matriz_terreno[inicio_y][inicio_x] == 'E')
    {
        if (matriz_terreno[inicio_y][inicio_x] == 'V')
        {
            contFloresta[2]++;
        }
        else if (matriz_terreno[inicio_y][inicio_x] == 'R')
        {
            contCasa[2]++;
        }

        printf("%c", matriz_terreno[inicio_y][inicio_x]);
        matriz_desastre_aux[inicio_y][inicio_x] = matriz_terreno[inicio_y][inicio_x];
        matriz_terreno[inicio_y][inicio_x] = 'G';
        (*area_assalto)++;
        printf("%d", *area_assalto);
    }

    for (a=0 ; a<(Area-1) ; a++)
    {
        i = vetor_y[a];
        j = vetor_x[a];

        if (matriz_terreno[i][j] == 'V' ||  matriz_terreno[i][j] == 'R'  ||   matriz_terreno[i][j] == 'E')
        {
            if (matriz_terreno[i][j] == 'V')
            {
                contFloresta[2]++;
            }
            else if (matriz_terreno[i][j] == 'R')
            {
                contCasa[2]++;
            }

            printf("%c", matriz_terreno[i][j]);
            matriz_desastre_aux[i][j] = matriz_terreno[i][j];
            matriz_terreno[i][j] = 'G';
            (*area_assalto)++;
            printf("%d", *area_assalto);
        }
    }

}

void Crimes(char matriz_terreno[][17], char matriz_desastre_aux[][17], int *contCasaCrime, int *contFlorestaCrime, int *contAguaCrime, int *qualCrime)
{
    int crime;
    int area_chacina = 0;
    int area_assalto = 0;
    int area_morte = 0;

    SAMPLE *som_chacina = load_sample("morte.wav");
    SAMPLE *som_morte = load_sample("morte.wav");
    SAMPLE *som_assalto = load_sample("assalto.wav");


    crime = rand()%100 + 1; //probabilidade de acontecer
    //chacina = ocorre se o numero sorteado for 1
    //morte = ocorre se os numeros sorteados forem de 2 a 25
    //assalto = ocorre se os numeros sorteados forem de 26 a 101

    if (crime == 1)
    {
        chacina(matriz_terreno, &area_chacina, matriz_desastre_aux, contCasaCrime, contFlorestaCrime);

        if (area_chacina != 0)
        {
            *qualCrime = 1;
            play_sample(som_chacina, 120, 128, 1000, FALSE);
        }
    }
    else if (crime >= 2 && crime <= 25)
    {
        morte(matriz_terreno, &area_morte, matriz_desastre_aux, contCasaCrime, contFlorestaCrime);

        if (area_morte != 0)
        {
            *qualCrime = 2;
            play_sample(som_morte, 120, 128, 1000, FALSE);
        }
    }
    else if (crime >= 26 && crime <= 101)
    {
        assalto(matriz_terreno, &area_assalto, matriz_desastre_aux, contCasaCrime, contFlorestaCrime);

        if (area_assalto != 0)
        {
            *qualCrime = 3;
            play_sample(som_assalto, 150, 128, 1000, FALSE);
        }
    }
}
