#ifndef VIATURAS_H_INCLUDED
#define VIATURAS_H_INCLUDED
#endif // VIATURAS_H_INCLUDED
#include "PrepararViaturas.h"


char* LeTexto(BITMAP* tela, int textoX, int textoY, int tamanhoTexto, int cor)
{
    clear_keybuf();//Limpa o buffer do teclado
    tamanhoTexto++;//Caracter Extra para o '\0'
    char caracter;
    int i;//Índice
    BITMAP* buffer= create_bitmap(SCREEN_W, SCREEN_H);//Funciona em tamanhos de telas diferentes
    BITMAP* espaco = load_bitmap("digitar.bmp",NULL);

    //Aloca uma string com o tamanho desejado
    char* texto = (char*) malloc(tamanhoTexto*sizeof(char));
    if (texto==NULL)
    {
        allegro_message("Erro!");
        allegro_exit();
        exit(1);
    }

    for (i=0;i<tamanhoTexto;i++)//Inicializa o texto com '\0'
        texto[i]='\0';

    i = 0;

    //---------------------
    //Loop da função
    while (caracter != KEY_ENTER)
    {
        draw_sprite(buffer, tela,0,0);
        draw_sprite(buffer, espaco, textoX - 30, textoY - 50);


        //Se uma tecla foi pressionada
        if (keypressed())
        {
            int  tecla   = readkey();
            char ASCII    = tecla & 0xff;
            caracter = tecla >> 8;

            //Se o caracter não for o backspace
            if (ASCII >= 32 && ASCII <= 126 && i < tamanhoTexto - 1)
            {
                texto[i] = ASCII;
                i++;
            }
            else if (caracter == KEY_BACKSPACE && i > 0)
            {
                texto[i-1] = '\0';
                i--;
            }
        }
        textprintf_ex(buffer, font, textoX, textoY, cor, -1, "%s", texto);
        blit(buffer, screen, 0, 0, 0, 0, 15*tamanhoTexto, 600);//Expressão indica até onde o texto aparece

        clear(buffer);
    }

    return texto;//Retorna ponteiro para string dinâmica
}

void contratar(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600); //carrega as coisas
    BITMAP *viaturas = load_bitmap("viaturas.bmp", NULL);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);

    while (!mouse_b&1)
    {
        draw_sprite(buffer, tela, 0, 0); //faz elas aparecerem na tela
        draw_sprite(buffer, viaturas, 552, 273);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);
    }

}
