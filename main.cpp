#include <allegro.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "struct.h"
#include "Desastres.h"
#include "OutrasFuncoes1.h"
#include "Obras.h"
#include "Campanhas.h"
#include "Declarar.h"
#include "Desalocar.h"
#include "Combate.h"


volatile int milisegundos=0;
void conta()
{
    milisegundos++;
}
END_OF_FUNCTION(conta);
LOCK_FUNCTION(conta);
LOCK_VARIABLE(milisegundos);

inline void init()
{
    allegro_init();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);

    install_timer();
    install_int_ex(conta, MSEC_TO_TIMER(250));
    install_keyboard();
    install_mouse();
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
}

inline void deinit()
{
    clear_keybuf();
    allegro_exit();
}

void imprimir_sprites(char matriz_terreno[][17], int x, int y, BITMAP *tela, BITMAP *agua[2], BITMAP *terra, BITMAP *floresta, BITMAP *estrada, BITMAP *casa, BITMAP *EmConstrucao, BITMAP *EmDestruicao, BITMAP *fogo, BITMAP *enchente, BITMAP *meteorito, BITMAP *MST, BITMAP *alien, BITMAP *ip, BITMAP *chacina, BITMAP *morte, BITMAP *assalto, BITMAP *carro_amb, BITMAP *carro_bomb, BITMAP *carro_policia, BITMAP *inexplorada)
{
    int i, j;

    for (i=0 ; i<19 ; i++)
    {
        for (j=0 ; j<17 ; j++)
        {
            if (matriz_terreno[i][j] == 'A')
            {
                draw_sprite(tela, agua[milisegundos%2], x, y);
            }
            else if (matriz_terreno[i][j] == 'T')
            {
                draw_sprite(tela, terra, x, y);
            }
            else if (matriz_terreno[i][j] == 'V')
            {
                draw_sprite(tela, floresta, x, y);
            }
            else if (matriz_terreno[i][j] == 'E')
            {
                draw_sprite(tela, estrada, x, y);
            }
            else if (matriz_terreno[i][j] == 'R')
            {
                draw_sprite(tela, casa, x, y);
            }
            else if (matriz_terreno[i][j] == 'C')
            {
                draw_sprite(tela, EmConstrucao, x, y);
            }
            else if (matriz_terreno[i][j] == 'D')
            {
                draw_sprite(tela, EmDestruicao, x, y);
            }
            else if (matriz_terreno[i][j] == 'F') //fogo
            {
                draw_sprite(tela, fogo, x, y);
            }
            else if (matriz_terreno[i][j] == 'N') //enchente
            {
                draw_sprite(tela, enchente, x, y);
            }
            else if (matriz_terreno[i][j] == 'M') //meteorito
            {
                draw_sprite(tela, meteorito, x, y);
            }
            else if (matriz_terreno[i][j] == 'S') //MST
            {
                draw_sprite(tela, MST, x, y);
            }
            else if (matriz_terreno[i][j] == 'L') //alien
            {
                draw_sprite(tela, alien, x, y);
            }
            else if (matriz_terreno[i][j] == 'I') //prova IP
            {
                draw_sprite(tela, ip, x, y);
            }
            else if (matriz_terreno[i][j] == 'H') //chacina
            {
                draw_sprite(tela, chacina, x, y);
            }
            else if (matriz_terreno[i][j] == 'O') //morte
            {
                draw_sprite(tela, morte, x, y);
            }
            else if (matriz_terreno[i][j] == 'G') //assalto - g de gun
            {
                draw_sprite(tela, assalto, x, y);
            }
            else if (matriz_terreno[i][j] == 'X')
            {
                draw_sprite(tela, inexplorada, x, y);
            }
            else if (matriz_terreno[i][j] == '1') //carro de bombeiro
            {
                draw_sprite(tela, carro_bomb, x, y);
            }
            else if (matriz_terreno[i][j] == '2') //carro de policia
            {
                draw_sprite(tela, carro_policia, x, y);
            }
            else if (matriz_terreno[i][j] == '3') //ambulancia
            {
                draw_sprite(tela, carro_amb, x, y);
            }

            x = x + 25;
        }

        x = 94;
        y = y + 25;

    }

}

int main()
{

    init();
    srand(time(NULL));

    //as outras variáveis são carregadas em "declarar.h"

    BITMAP *menu, *mouse, *tela, *terra, *floresta, *estrada, *casa, *fundo_jogo, *agua[3], *fogo, *enchente, *meteorito, *MST, *alien, *ip, *chacina, *morte, *assalto, *inexplorada;
    BITMAP *Perdeu, *EmConstrucao, *EmDestruicao, *carro_bomb, *carro_policia, *carro_amb;
    SAMPLE *musica_menu = load_sample("MusicaMenu.wav");
    SAMPLE *musica_jogo = load_sample("MusicaJogo.wav");


    //Carregando imagens
    tela = create_bitmap (800,600);
    mouse = load_bitmap("mouse2.bmp",NULL);
    menu = load_bitmap("menu.bmp",NULL);
    agua[0] = load_bitmap("agua1.bmp", NULL);
    agua[1] = load_bitmap("agua2.bmp", NULL);
    agua[2] = load_bitmap("agua3.bmp", NULL);
    terra = load_bitmap("terra.bmp", NULL);
    floresta = load_bitmap("arvore.bmp", NULL);
    estrada = load_bitmap("estrada.bmp", NULL);
    casa = load_bitmap("casa.bmp", NULL);
    fundo_jogo = load_bitmap("jogo_fundo.bmp", NULL);
    Perdeu = load_bitmap("PerdeJogo.bmp", NULL);
    EmConstrucao = load_bitmap("construcao.bmp", NULL);
    EmDestruicao = load_bitmap("destruicao.bmp", NULL);
    fogo = load_bitmap("fogo.bmp", NULL);
    enchente = load_bitmap("enchente.bmp", NULL);
    meteorito = load_bitmap("meteorito.bmp", NULL);
    MST = load_bitmap("MST.bmp", NULL);
    alien = load_bitmap("alien.bmp", NULL);
    ip = load_bitmap("bomba.bmp", NULL);
    chacina = load_bitmap("chacina.bmp", NULL);
    morte = load_bitmap("caveira.bmp", NULL);
    assalto = load_bitmap("assalto.bmp", NULL);
    carro_amb = load_bitmap("ambulancia.bmp", NULL);
    carro_bomb = load_bitmap("bombeiro.bmp", NULL);
    carro_policia = load_bitmap("policia.bmp", NULL);
    inexplorada = load_bitmap("inexplorada.bmp", NULL);


    bomb = cria_bombeiro();
    policia = cria_policia();
    amb = cria_ambulancia();

    char* nome = (char*) malloc(sizeof(char));

    //Aloca espaço para as structs

    entrada_dados = (Entrada*) malloc(sizeof(Entrada));

    if (entrada_dados == NULL)
    {
        printf("Nao foi possivel carregar o jogo\n");
        exit(1);
    }
    else
    {
        entrada_dados->pBombeiro = (Bombeiro*) malloc(sizeof(Bombeiro));
        entrada_dados->pAmbulancia = (Ambulancia*) malloc(sizeof(Ambulancia));
        entrada_dados->pPolicia = (Policia*) malloc(sizeof(Policia));

        if ((entrada_dados->pBombeiro == NULL) || (entrada_dados->pAmbulancia == NULL) || (entrada_dados->pPolicia == NULL))
        {
            printf("Nao foi possivel carregar o jogo\n");
            exit(1);
        }
    }

    //para inicializar a matriz que vai auxiliar nos desastres
    for (i=0; i<19 ; i++)
    {
        for (j=0 ; j<17 ; j++)
        {
            matriz_desastre_aux[i][j] = '0';
        }
    }


    //chama as funções que lerão a entrada fornecida, dando condições ao início do jogo
    ler_entrada(matriz_terreno, entrada_dados);

    //toca música do menu
    play_sample(musica_menu, 100, 127, 900, TRUE);


    while (!key[KEY_ESC] && sair == 0)
    {

        clear(tela);

        //imprime as imagens do menu, mouse
        draw_sprite(tela,menu,0,0);
        draw_sprite(tela,mouse,mouse_x,mouse_y); //essas tres linhas sao para aparecer mouse e menu na tela
        draw_sprite(screen, tela,0,0);

        //próximo if identifica se a opção "jogar" foi selecionada
        if ((mouse_b&1 && mouse_x>339 && mouse_x<506 && mouse_y>481 && mouse_y<558)  || key[KEY_ENTER]) //Esses valores representam os pixels de abrangência do mouse
        {
            //Parar a musica que estava tocando no menu
            stop_sample(musica_menu);

            //Iniciar a musica do jogo
            play_sample(musica_jogo, 120, 128, 1000, TRUE);


            while (!key[KEY_ESC] && sair == 0)  //so sai da tela do jogo se for pressionado esc
            {
                //Imprimir a imagem do terreno
                clear(tela);

                draw_sprite(tela, fundo_jogo, 0, 0);
                //draw_sprite(tela, mouse, mouse_x, mouse_y);  //Comandos para que o mouse funcione corretamente quando o jogo estiver rolando


                //Chamada da função para imprimir as sprites na tela
                x=94;
                y=62;


                imprimir_sprites(matriz_terreno, x, y, tela, agua, terra, floresta, estrada, casa, EmConstrucao, EmDestruicao, fogo, enchente, meteorito, MST, alien, ip, chacina, morte, assalto, carro_amb, carro_bomb, carro_policia, inexplorada);

                cont_residencias = qtde_residencias(matriz_terreno, &pop_max); //Vai alterar o valor da qtde de residencias

                //Calcula o imposto
                imposto = (entrada_dados->populacao)*taxa_imposto*100;

                //Para imprimir os dados de entrada (numeros)
                textprintf_ex(tela, font, 563, 27, makecol(255,253,3), -1, "%s", entrada_dados->nome_cidade);

                textprintf_ex(tela, font, 212, 566, makecol(37,244,110), -1, "%d", entrada_dados->rest_semanas);

                textprintf_ex(tela, font, 744, 57, makecol(255,253,3), -1, "%d", cont_residencias);

                textprintf_ex(tela, font, 650, 76, makecol(255,253,3) , -1, "%d", entrada_dados->populacao);

                textprintf_ex(tela, font, 709, 95, makecol(255,253,3), -1, "%d", entrada_dados->min_habitantes);

                textprintf_ex(tela, font, 707, 177, makecol(255, 253, 3), -1, "%.2f", entrada_dados->caixa);

                textprintf_ex(tela, font, 631, 127, makecol(255, 253, 3), -1, "%.2f", imposto);

                textprintf_ex(tela, font, 723, 198, makecol(255, 253, 3), -1, "%d", NumBomb);

                textprintf_ex(tela, font, 661, 216, makecol(255, 253, 3), -1, "%d", NumAmb);

                textprintf_ex(tela, font, 710, 236, makecol(255, 253, 3), -1, "%d", NumPolicia);


                imprimir_combates_D(tela, matriz_terreno, &qualDesastre, bomb, amb, policia, pInc, pEnch, pMeteoro, pAlienigena, pInvMST, pProva, pAssalto, pMorte, pChacina, slotViaturaA, slotViaturaB, slotViaturaP, ViatOcupBomb, ViatOcupAmb, ViatOcupPolic, PassouSemana);  //chama a função que vai imprimir as sprites, a função é chamada antes de verificar se houve desastre para dar tempo de imprimir as sprites do desastre

                imprimir_combates_C(tela, matriz_terreno, &qualCrime, bomb, amb, policia, pAssalto, pMorte, pChacina, slotViaturaA, slotViaturaB, slotViaturaP, ViatOcupBomb, ViatOcupAmb, ViatOcupPolic, PassouSemana);


                ///Falta completar as entradas, com os outros dados (arrecadação mensal, carros de bombeiro, ambulancia, policia)
                ///verificar se as variáveis vetorI e vetorJ são realmente necessárias
                cont1 = opcoes(entrada_dados, imposto, &cont_impostos, &aux_construcao, &aux_destruicao, matriz_terreno, bomb, policia, amb, matriz_desastre_aux, contCasaDesastre, contFlorestaDesastre, contAguaDesastre, contCasaCrime, contFlorestaCrime, contAguaCrime, desastre_relatorio, &qualDesastre, &qualCrime, PassouSemana);
                //os 'ifs' abaixo verificam qual é o valor de cont1 para assim realizar a ação correta
                //CONTRATAR!
                if (cont1 == 1)
                {
                    contratar(tela);

                    if (mouse_b&1 && mouse_x>568 && mouse_x<739 && mouse_y>294 && mouse_y<349) //Bombeiro
                    {
                        nome = LeTexto(tela,textoX,textoY,tamanhoTexto,cor);
                        novoCarro(bomb, nome);
                        entrada_dados->caixa = (entrada_dados->caixa) - (entrada_dados->pBombeiro->custo_aquisicao);
                        aviso_compra_viatura(tela); //função que vai imprimir o aviso de compra da viatura
                        NumBomb++;
                    }

                    if (mouse_b&1 && mouse_x>568 && mouse_x<740 && mouse_y>368 && mouse_y<423)//Policia
                    {
                        nome = LeTexto(tela,textoX,textoY,tamanhoTexto,cor);
                        novoCarro(policia,nome);
                        entrada_dados->caixa = (entrada_dados->caixa) - (entrada_dados->pPolicia->custo_aquisicao);
                        aviso_compra_viatura(tela); //função que vai imprimir o aviso de compra da viatura
                        NumPolicia++;
                    }

                    if (mouse_b&1 && mouse_x>568 && mouse_x<738 && mouse_y>442 && mouse_y<497)//Ambulancia
                    {
                        nome = LeTexto(tela,textoX,textoY,tamanhoTexto,cor);
                        novoCarro(amb,nome);
                        entrada_dados->caixa = (entrada_dados->caixa) - (entrada_dados->pAmbulancia->custo_aquisicao);
                        aviso_compra_ambulancia(tela); //função que vai imprimir o aviso de compra da viatura
                        NumAmb++;
                    }

                }
                //CAMPANHAS!
                if (cont1 == 2)
                {
                    aux_campanha = campanhas(tela);
                    efetivar_campanha(aux_campanha, bomb, amb, policia, entrada_dados, &taxa_imposto);
                }
                //CONSTRUIR/DESTRUIR
                if (cont1 == 3)
                {
                    construir_destruir(tela); //vai imprimir a janelinha que tem duas opções: construir e destruir

                    if (mouse_b&1 && mouse_x>580 && mouse_x<720  && mouse_y>307 && mouse_y<366) //coordenadas do botão construir
                    {
                        mouse_x = -50;

                        if (aux_construcao == 0)
                        {
                            construir(tela, matriz_terreno, entrada_dados, &aux_construcao);
                        }
                        else
                        {
                            //chama a função que irá imprimir a mensagem de não é possível construir dois itens numa mesma semana
                            proibirC(tela);
                        }
                    }
                    if (mouse_b&1 && mouse_x>580 && mouse_x<720 && mouse_y>420 && mouse_y<475) //coordenadas do botão destruir
                    {
                        mouse_x = -50;

                        if (aux_destruicao == 0)
                        {
                            destruir(tela, matriz_terreno, entrada_dados, &aux_destruicao);
                        }
                        else
                        {
                            proibirD(tela);
                        }
                    }
                }

                cont1 = 0;

                draw_sprite(tela,mouse,mouse_x,mouse_y);
                draw_sprite(screen, tela, 0, 0);


                //O 'if' abaixo permite a saida do programa, apertando a tecla "sair"
                if ((mouse_b&1) && (mouse_x>94) && (mouse_x<215) && (mouse_y>12) && (mouse_y<39))
                {
                    stop_sample(musica_jogo);
                    sair = 1;
                    ///lembrar de destruir as coisas antes disso
                }
            }
        }
    }

    destroy_bitmap(menu);
    destroy_bitmap(mouse);
    destroy_bitmap(tela);
    destroy_bitmap(agua[0]);
    destroy_bitmap(agua[1]);
    destroy_bitmap(agua[2]);
    destroy_bitmap(terra);
    destroy_bitmap(floresta);
    destroy_bitmap(estrada);
    destroy_bitmap(casa);
    destroy_bitmap(fundo_jogo);
    destroy_bitmap(Perdeu);
    destroy_bitmap(EmConstrucao);
    destroy_bitmap(EmDestruicao);
    destroy_bitmap(fogo);
    destroy_bitmap(enchente);
    destroy_bitmap(meteorito);
    destroy_bitmap(MST);
    destroy_bitmap(alien);
    destroy_bitmap(ip);
    destroy_bitmap(chacina);
    destroy_bitmap(morte);
    destroy_bitmap(assalto);

    destroy_sample(musica_menu);
    destroy_sample(musica_jogo);
    Desalocar();

    deinit();
    return 0;
}
END_OF_MAIN()
