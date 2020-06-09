#ifndef OBRAS_H_INCLUDED
#define OBRAS_H_INCLUDED
#endif // OBRAS_H_INCLUDED

void noMoneyDestroy(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_dinheiro = load_bitmap("sem_dinheiro_destruir.bmp", NULL);
    int aux=0;


    while(aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_dinheiro, 539, 13);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if(mouse_b&1 && mouse_x>618 && mouse_x<695 && mouse_y>189 && mouse_y<226)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_dinheiro);

}

void noMoneyBuild(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_dinheiro = load_bitmap("sem_dinheiro_construir.bmp", NULL);
    int aux=0;


    while(aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_dinheiro, 539, 13);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if(mouse_b&1 && mouse_x>618 && mouse_x<695 && mouse_y>189 && mouse_y<226)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_dinheiro);

}

void construir_residencia(BITMAP *tela, char matriz_terreno[19][17], Entrada *entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL); //carrega o bitmap do mouse de martelo
    BITMAP *local_improprio = load_bitmap("localImproprio.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on = 0;

    /*Variável sair controla a saída da função, se sair for igual a 1, sairá da função e sair só receberá
    1 em dois casos: quando o jogador passar a semana e quando o dinheiro for insuficiente*/
    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);


        //'if' checa se há dinheiro suficiente
        if (entrada_dados->caixa < 500)
        {
            //chama a função que vai avisar que não há dinheiro suficiente para construção
            noMoneyBuild(tela);
            sair = 1;
        }
        else
        {
            //Se o mouse estiver sobre a matriz
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os índices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b&1)
                {
                    if (matriz_terreno[i][j] != 'T')
                    {
                        aviso_on = 1;
                        mouse_x=-50;
                    }
                    else
                    {
                        /*'construindo' é uma variável que auxilia na impressão do bitmap
                        emConstrucao, para que ele continue sendo impresso mesmo depois do clique*/
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'C';
                        sair = 1;
                    }
                }
            }

            if (aviso_on == 1)
            {

                draw_sprite(buffer, local_improprio, 543, 18);

            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);
    destroy_bitmap(local_improprio);

}

//'construir_floresta' tem a mesma ideia de construir_residencia
void construir_floresta(BITMAP *tela, char matriz_terreno[19][17], Entrada *entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL);
    BITMAP *local_improprio = load_bitmap("localImproprio.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on=0;

    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);


        if (entrada_dados->caixa < 300)
        {
            noMoneyBuild(tela);
            sair = 1;
        }
        else
        {
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os indices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b &1)
                {
                    if (matriz_terreno[i][j] != 'T')
                    {
                        aviso_on=1;
                        mouse_x=-50;
                    }
                    else
                    {
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'C';
                        sair = 1;
                    }
                }
            }

            if(aviso_on == 1)
            {
                draw_sprite(buffer, local_improprio, 543, 18);
            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);

        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);

}

//'construir_agua' tem a mesma ideia de construir_residencia
void construir_agua(BITMAP *tela, char matriz_terreno[19][17], Entrada *entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL);
    BITMAP *local_improprio = load_bitmap("localImproprio.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on=0;

    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);

        if (entrada_dados->caixa < 100)
        {
            noMoneyBuild(tela);
            sair = 1;
        }
        else
        {
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os indices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b &1)
                {
                    if (matriz_terreno[i][j] != 'T')
                    {
                        aviso_on=1;
                        mouse_x=-50;
                    }
                    else
                    {
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'C';
                        sair = 1;
                    }
                }
            }

            if(aviso_on == 1)
            {
                draw_sprite(buffer, local_improprio, 543, 18);
            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);

}

void destruir_residencia(BITMAP *tela, char matriz_terreno[][17], Entrada* entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL);
    BITMAP *local_improprio = load_bitmap("localImproprioDR.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on=0;

    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);

        if (entrada_dados->caixa < 200)
        {
            noMoneyDestroy(tela);
            sair = 1;
        }
        else
        {
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os indices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b&1)
                {
                    if (matriz_terreno[i][j] != 'R')
                    {
                        aviso_on=1;
                        mouse_x=-50;
                    }
                    else
                    {
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'D';
                        sair = 1;
                    }
                }
            }

            if(aviso_on == 1)
            {
                draw_sprite(buffer, local_improprio, 543, 18);
            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);

}

void destruir_floresta(BITMAP *tela, char matriz_terreno[][17], Entrada *entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL);
    BITMAP *local_improprio = load_bitmap("localImproprioDF.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on=0;

    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);

        if (entrada_dados->caixa < 150)
        {
            noMoneyDestroy(tela);
            sair = 1;
        }
        else
        {
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os indices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b &1)
                {
                    if (matriz_terreno[i][j] != 'V')
                    {
                        aviso_on=1;
                        mouse_x=-50;
                    }
                    else
                    {
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'D';
                        sair = 1;
                    }
                }
            }

            if(aviso_on == 1)
            {
                draw_sprite(buffer, local_improprio, 543, 18);
            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);
}

void destruir_agua(BITMAP *tela, char matriz_terreno[][17], Entrada *entrada_dados)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse1 = load_bitmap("martelo.bmp", NULL);
    BITMAP *local_improprio = load_bitmap("localImproprioDA.bmp", NULL);
    int i, j, sair=0, b, c, aviso_on=0;

    while (sair == 0)
    {
        draw_sprite(buffer, tela, 0, 0);

        if (entrada_dados->caixa < 200)
        {
            noMoneyDestroy(tela);
            sair = 1;
        }
        else
        {
            if (mouse_x>94 && mouse_y>62 && mouse_x<520 && mouse_y<540) //Coordenadas do tamanho do mapa da cidade
            {
                //Calcula os indices
                j = (mouse_x - 94)/25;
                i = (mouse_y - 62)/25;
                //Se clicar
                if (mouse_b &1)
                {
                    if (matriz_terreno[i][j] != 'A')
                    {
                        aviso_on=1;
                        mouse_x=-50;
                    }
                    else
                    {
                        b = i;
                        c = j;
                        matriz_terreno[b][c] = 'D';
                        sair = 1;
                    }
                }
            }

            if(aviso_on == 1)
            {
                  draw_sprite(buffer, local_improprio, 543, 18);
            }

            draw_sprite(buffer, mouse1, mouse_x, mouse_y);
        }

        draw_sprite(screen, buffer, 0, 0);
        clear(buffer);
    }

    destroy_bitmap(buffer);
    destroy_bitmap(mouse1);
}

void construir(BITMAP* tela, char matriz_terreno[][17], Entrada *entrada_dados, int *aux_construcao)
{
    BITMAP* construir= load_bitmap("construir.bmp", NULL);
    BITMAP* buffer = create_bitmap(800,600);
    BITMAP* mouse = load_bitmap("mouse2.bmp",NULL);
    int verifica_construir = 0;

    while (verifica_construir != 1)
    {
        draw_sprite(buffer,tela,0,0);
        draw_sprite(buffer,construir,566,274);
        draw_sprite(buffer,mouse,mouse_x,mouse_y);
        draw_sprite(screen,buffer,0,0);

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>296 && mouse_y<360) //Construir Residência
        {
            (*aux_construcao) = 1;
            construir_residencia(tela, matriz_terreno, entrada_dados);
            verifica_construir = 1;

            if (entrada_dados->caixa >= 500)
            {
                entrada_dados->caixa = entrada_dados->caixa - 500;   //Se o dinheiro em caixa for suficiente(nesse caso maior que 500), haverá o débito
            }
            else
            {
                (*aux_construcao) = 0;  //Caso o dinheiro em caixa não for suficiente, o item não será construido e ai aux_construcao não deverá receber 1 mas sim zero.
            }
        }

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>362 && mouse_y<424) //Construir Floresta
        {
            (*aux_construcao) = 2;
            construir_floresta(tela, matriz_terreno, entrada_dados);
            verifica_construir = 1;

            if (entrada_dados->caixa >= 300)
            {
                entrada_dados->caixa = entrada_dados->caixa - 300;
            }
            else
            {
                (*aux_construcao) = 0;
            }
        }

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>437 && mouse_y<501) //Construir Água
        {
            (*aux_construcao) = 3;
            construir_agua(tela, matriz_terreno, entrada_dados);
            verifica_construir = 1;

            if (entrada_dados->caixa >= 100)
            {
                entrada_dados->caixa = entrada_dados->caixa - 100;
            }
            else
            {
                (*aux_construcao) = 0;
            }
        }
    }

    destroy_bitmap(construir);
    destroy_bitmap(buffer);
    destroy_bitmap(mouse);
}

void destruir(BITMAP* tela, char matriz_terreno[][17], Entrada *entrada_dados, int *aux_destruicao)
{
    BITMAP* destruir= load_bitmap("destruir1.bmp", NULL);
    BITMAP* buffer = create_bitmap(800,600);
    BITMAP* mouse = load_bitmap("mouse2.bmp",NULL);
    int verifica_destruir = 0;

    while (verifica_destruir != 1)
    {
        draw_sprite(buffer,tela,0,0);
        draw_sprite(buffer,destruir,566,274);
        draw_sprite(buffer,mouse,mouse_x,mouse_y);
        draw_sprite(screen,buffer,0,0);

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>296 && mouse_y<360) //Destruir Residência
        {
            (*aux_destruicao) = 1;
            destruir_residencia(tela, matriz_terreno, entrada_dados);
            verifica_destruir = 1;

            if (entrada_dados->caixa >= 200)
            {
                entrada_dados->caixa = entrada_dados->caixa - 200;
            }
            else
            {
                (*aux_destruicao)=0;
            }
        }

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>362 && mouse_y<424) //Destruir Floresta
        {
            (*aux_destruicao) = 2;
            destruir_floresta(tela, matriz_terreno, entrada_dados);
            verifica_destruir = 1;

            if (entrada_dados->caixa >= 150)
            {
                entrada_dados->caixa = entrada_dados->caixa - 150;
            }
            else
            {
                (*aux_destruicao)=0;
            }
        }

        if (mouse_b&1 && mouse_x>578 && mouse_x<736 && mouse_y>437 && mouse_y<501) //Destruir Água
        {
            (*aux_destruicao) = 3;
            destruir_agua(tela, matriz_terreno, entrada_dados);
            verifica_destruir = 1;

            if (entrada_dados->caixa >= 200)
            {
                entrada_dados->caixa = entrada_dados->caixa - 200;
            }
            else
            {
                (*aux_destruicao)=0;
            }
        }
    }

    destroy_bitmap(destruir);
    destroy_bitmap(buffer);
    destroy_bitmap(mouse);
}

void construir_destruir(BITMAP*tela)
{
    BITMAP* construir_destruir = load_bitmap("ConstruirDestruir.bmp", NULL);
    BITMAP* buffer = create_bitmap(800,600);
    BITMAP* mouse = load_bitmap("mouse2.bmp",NULL);

    while (!mouse_b&1)
    {
        draw_sprite(buffer,tela,0,0);
        draw_sprite(buffer,construir_destruir,559,274);
        draw_sprite(buffer,mouse,mouse_x,mouse_y);
        draw_sprite(screen,buffer,0,0);
    }

    destroy_bitmap(construir_destruir);
    destroy_bitmap(buffer);
    destroy_bitmap(mouse);
}

void proibirC(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *proibir_construcao = load_bitmap("proibirConstrucao.bmp", NULL);
    int aux=0;


    while(aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, proibir_construcao, 541, 13);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if(mouse_b&1 && mouse_x>636 && mouse_x<688 && mouse_y>220 && mouse_y<252)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(proibir_construcao);

}

void proibirD(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *proibir_destruicao = load_bitmap("proibirDestruicao.bmp", NULL);
    int aux=0;


    while(aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, proibir_destruicao, 541, 13);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if(mouse_b&1 && mouse_x>636 && mouse_x<688 && mouse_y>220 && mouse_y<252)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(proibir_destruicao);

}
