#ifndef COMBATE_H_INCLUDED
#define COMBATE_H_INCLUDED
#include "PrepararViaturas.h"

void inicializarCombateIncendio(Incendio* pInc)
{
    pInc->PontosBomb = 300*ceil((pInc->Area)/3);
    pInc->SlotsBomb = 3;
    pInc->PontosAmb = 240*ceil((pInc->Area)/3);
    pInc->SlotsAmb = 3;

    /*Se o que foi destruido era uma residencia
    pInc->CustoReparacao = contadorDeResidencia*250

    Se o que foi destruido era uma floresta
    pInc->CustoReparacao = contadorDeFloresta*200 */
}

void inicializarCombateEnchente(Enchentes* pEnch)
{
    pEnch->PontosBomb = 140*ceil(pEnch->Area/3);
    pEnch->SlotsBomb = 1;
    pEnch->PontosAmb = 80*ceil(pEnch->Area/3);
    pEnch->SlotsAmb = 1;

    /*Se o que foi destruido era uma residencia
    pEnch->CustoReparacao = contadorDeResidencia*250*/

}

void inicializarCombateMeteoritos(Meteoritos* pMeteoro)
{
    pMeteoro->PontosBomb = 200*ceil((pMeteoro->Area)/3) ;
    pMeteoro->SlotsBomb = 2;
    pMeteoro->PontosAmb = 100*ceil((pMeteoro->Area)/3);
    pMeteoro->SlotsAmb = 1;
    pMeteoro->PontosPolicia = 100*ceil((pMeteoro->Area)/3);
    pMeteoro->PontosPolicia = 1;
    //se for residencia
    //meteoro->CustoReparacao = contadorDeResidencia*
}

void inicializarCombateAlien(Alien* pAlienigena)
{
    pAlienigena->PontosBomb = 300*ceil((pAlienigena->Area)/3);
    pAlienigena->SlotsBomb = 4;
    pAlienigena->PontosAmb = 100*ceil((pAlienigena->Area)/3);
    pAlienigena->SlotsAmb = 1;
    pAlienigena->PontosPolicia = 300*ceil((pAlienigena->Area)/3);
    pAlienigena->SlotsPolicia = 4;

}

void inicializarCombateMST(mst* pInvMST)
{
    pInvMST->PontosPolicia = 270*ceil((pInvMST->Area)/3);
    pInvMST->SlotsPolicia = 3;

}

void inicializarCombateIP(IP* pProva)
{
    pProva->PontosAmb = 600*ceil((pProva->Area)/3);

    pProva->SlotsAmb = 8;
    //pProva->CustoReparacao = 250*contadorReisenciasAtigindas

}

void inicializarAssalto(Assalto *pAssalto)
{
    pAssalto->PontosPolicia = 100 * ((pAssalto->Area)/3);
    pAssalto->SlotsPolicia = 2;

}

void inicializarMorte(Morte *pMorte)
{
    pMorte->PontosAmb = 100*((pMorte->Area)/3);
    pMorte->SlotsAmb = 2;
    pMorte->PontosPolicia = 220 * ((pMorte->Area)/3);
    pMorte->SlotsPolicia = 3;

}

void inicializarChacina(Chacina *pChacina)
{
    pChacina->PontosAmb = 320 * ((pChacina->Area)/3);
    pChacina->PontosAmb = 4;
    pChacina->PontosPolicia = 400 *((pChacina->Area)/3);
    pChacina->SlotsPolicia = 5;
    pChacina->CustoReparacao = 590;

}
/*----------------------------------------------------------------------------------------------------------------------------*/

ListaCarros* Pegar_viatura(Fila* viatura, ListaCarros* ViatOcupadas, int slotViatura) //Verifica, remove e adc na lista auxiliar
{
    int i;
    ViatOcupadas = viatura->ini;                                ///FUNÇAO QUE PODE SER GENERALIZADA :)
    int cont = 0;

    for (i = 0;(ViatOcupadas != NULL) && (i < slotViatura); i++)
    {
        if (ViatOcupadas->conservacao < 15)
        {
            ferro_velho(viatura);
            ///AVISAR QUE NAO HA VIATURAS SUFICIENTES
            cont++;
        }
        else
        {
            ViatOcupadas = remover(viatura); //Tirar da lista e colocar na lista de viaturas ocupadas

            inserir_carro(viatura, ViatOcupadas);
        }

        ViatOcupadas = ViatOcupadas->prox;
    }

    if (cont == slotViatura)
    {
        ViatOcupadas = NULL;
    }
    else
    {
        ViatOcupadas = viatura->ini;
    }

    return ViatOcupadas;
}

void LutaIncendBomb(Incendio* pInc,ListaCarros* ViatOcupBomb,Fila* bomb,int PassouSemana) //Combate Incendio x bombeiros
{
    int LifeDesastre = pInc->PontosBomb;
    int ForcaBomb[3];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(bomb)))
    {
        for (i=0;i<3;i++)
        {
            ViatOcupBomb->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupBomb->conservacao -= 5;
            ForcaBomb[i] = (ViatOcupBomb->conservacao)*100;

            if (ViatOcupBomb->conservacao < 15)
            {
                ferro_velho(bomb);
            }

            ViatOcupBomb = ViatOcupBomb->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaBomb[0] + ForcaBomb[1] + ForcaBomb[2]);
        }
        PassouSemana = 0;

    }

}

void LutaIncendAmb(Incendio* pInc,ListaCarros* ViatOcupAmb, Fila* amb,int PassouSemana) //combate incendio x ambulancias, so pode ser chamada depois de chamada a funcao acima
{
    int LifeDesastre = pInc->PontosAmb;
    int ForcaAmb[3];
    int i;

    while (LifeDesastre > 0 && !(fila_vazia(amb)))
    {
        for (i=0;i<3;i++)
        {
            ViatOcupAmb->qtd_chamadas += 1; //Decrementar e incrementar o que tiver que decrementar/incrementar
            ViatOcupAmb->conservacao -= 5;
            ForcaAmb[i] = (ViatOcupAmb->conservacao)*100;

            if (ViatOcupAmb->conservacao < 15)
            {
                ferro_velho(amb);

            }
            ViatOcupAmb = ViatOcupAmb->prox;
        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaAmb[0] + ForcaAmb[1] + ForcaAmb[2]);
        }
        PassouSemana = 0;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaEnchBomb(Enchentes* pEnch,ListaCarros* ViatOcupBomb,Fila* bomb,int PassouSemana) // combate enchente x bombeiro
{
    int LifeDesastre = pEnch->PontosBomb;
    int ForcaBomb;


    while (LifeDesastre > 0 && !(fila_vazia(bomb)))
    {

        ViatOcupBomb->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
        ViatOcupBomb->conservacao -= 5;
        ForcaBomb = (ViatOcupBomb->conservacao)*100;

        if (ViatOcupBomb->conservacao < 15)
        {
            ferro_velho(bomb);

        }
        if(PassouSemana != 0)
        {
            LifeDesastre =  LifeDesastre - ForcaBomb;
        }
        PassouSemana = 0;

    }

}

void LutaEnchAmb(Enchentes* pEnch,ListaCarros* ViatOcupAmb,Fila* amb,int PassouSemana) // combate enchente x ambulancia
{
    int LifeDesastre = pEnch->PontosAmb;
    int ForcaAmb;


    while (LifeDesastre > 0 && !(fila_vazia(amb)))
    {

        ViatOcupAmb->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
        ViatOcupAmb->conservacao -= 5;
        ForcaAmb = (ViatOcupAmb->conservacao)*100;

        if (ViatOcupAmb->conservacao < 15)
        {
            ferro_velho(amb);

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - ForcaAmb;
        }
        PassouSemana = 0;

    }

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaMeteoBomb(ListaCarros* ViatOcupBomb,Meteoritos *pMeteoro,Fila* bomb,int PassouSemana) //combate meteorito x bombeiro
{
    int LifeDesastre = pMeteoro->PontosBomb;
    int ForcaBomb[2];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(bomb)))
    {
        for (i=0;i<2;i++)
        {
            ViatOcupBomb->qtd_chamadas += 1; //Decrementar e Incrementar o que tiver que decrementar/pIncrementar
            ViatOcupBomb->conservacao -= 5;
            ForcaBomb[i] = (ViatOcupBomb->conservacao)*100;

            if (ViatOcupBomb->conservacao < 15)
            {
                ferro_velho(bomb);

            }

            ViatOcupBomb = ViatOcupBomb->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaBomb[0] + ForcaBomb[1]);
        }
        PassouSemana = 0;
    }

}

void LutaMeteoAmb(Meteoritos* pMeteoro,ListaCarros* ViatOcupAmb,Fila* amb,int PassouSemana) //combate meteoritos x ambulancia
{
    int LifeDesastre = pMeteoro->PontosAmb;
    int ForcaAmb;


    while (LifeDesastre > 0 && !(fila_vazia(amb)))
    {

        ViatOcupAmb->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
        ViatOcupAmb->conservacao -= 5;
        ForcaAmb = (ViatOcupAmb->conservacao)*100;

        if (ViatOcupAmb->conservacao < 15)
        {
            ferro_velho(amb);

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - ForcaAmb;
        }
        PassouSemana = 0;
    }

}

void LutaMeteoPolic(Meteoritos* pMeteoro,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //combate meteoritos x policia
{
    int LifeDesastre = pMeteoro->PontosPolicia;
    int ForcaPolicia;


    while (LifeDesastre > 0 && !(fila_vazia(policia)))
    {

        ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
        ViatOcupPolic->conservacao -= 5;
        ForcaPolicia = (ViatOcupPolic->conservacao)*100;

        if (ViatOcupPolic->conservacao < 15)
        {
            ferro_velho(policia);

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - ForcaPolicia;
        }
        PassouSemana = 0;
    }

}
///////////////////////////////////////////////////////////////////////////////////////////////////////


void LutaAlienBomb(Alien *pAlienigena, ListaCarros* ViatOcupBomb,Fila* bomb,int PassouSemana) //Combate Alienigena x bombeiros
{
    int LifeDesastre = pAlienigena->PontosBomb;
    int ForcaBomb[4];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(bomb)))
    {
        for (i=0;i<4;i++)
        {
            ViatOcupBomb->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupBomb->conservacao -= 5;
            ForcaBomb[i] = (ViatOcupBomb->conservacao)*100;

            if (ViatOcupBomb->conservacao < 15)
            {
                ferro_velho(bomb);
            }

            ViatOcupBomb = ViatOcupBomb->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaBomb[0] + ForcaBomb[1] + ForcaBomb[2] + ForcaBomb[3]);
        }
        PassouSemana = 0;
    }

}

void LutaAlienAmb(Alien* pAlienigena,ListaCarros* ViatOcupAmb,Fila* amb,int PassouSemana) // combate Alienigenas x ambulancia
{
    int LifeDesastre = pAlienigena->PontosAmb;
    int ForcaAmb;


    while (LifeDesastre > 0 && !(fila_vazia(amb)))
    {

        ViatOcupAmb->qtd_chamadas += 1;
        ViatOcupAmb->conservacao -= 5;
        ForcaAmb = (ViatOcupAmb->conservacao)*100;

        if (ViatOcupAmb->conservacao < 15)
        {
            ferro_velho(amb);

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - ForcaAmb;
        }
        PassouSemana = 0;
    }

}

void LutaAlienPolicia(Alien* pAlienigena,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //Combate Alien x policia
{
    int LifeDesastre = pAlienigena->PontosPolicia;
    int ForcaPolicia[4];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(policia)))
    {
        for (i=0;i<4;i++)
        {
            ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupPolic->conservacao -= 5;
            ForcaPolicia[i] = (ViatOcupPolic->conservacao)*100;

            if (ViatOcupPolic->conservacao < 15)
            {
                ferro_velho(policia);
            }

            ViatOcupPolic = ViatOcupPolic->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaPolicia[0] + ForcaPolicia[1] + ForcaPolicia[2] + ForcaPolicia[3]);
        }
        PassouSemana = 0;

    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaMSTPolicia(mst* pInvMST,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //Combate Alien x policia
{
    int LifeDesastre = pInvMST->PontosPolicia;
    int ForcaPolicia[3];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(policia)))
    {
        for (i=0;i<3;i++)
        {
            ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupPolic->conservacao -= 5;
            ForcaPolicia[i] = (ViatOcupPolic->conservacao)*100;

            if (ViatOcupPolic->conservacao < 15)
            {
                ferro_velho(policia);
            }

            ViatOcupPolic = ViatOcupPolic->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaPolicia[0] + ForcaPolicia[1] + ForcaPolicia[2]);
        }
        PassouSemana = 0;
    }

}


//////////////////////////////////////////////////////////////////////////////////////////////////////
void LutaIPAmb(ListaCarros* ViatOcupAmb,IP *pProva,Fila* amb,int PassouSemana) //combate prova de IP x ambulancia
{
    int LifeDesastre = pProva->PontosAmb;
    int ForcaAmb[8];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(amb)))
    {
        for (i=0;i<8;i++)
        {
            ViatOcupAmb->qtd_chamadas += 1; //Decrementar e Incrementar o que tiver que decrementar/incrementar
            ViatOcupAmb->conservacao -= 5;
            ForcaAmb[i] = (ViatOcupAmb->conservacao)*100;

            if (ViatOcupAmb->conservacao < 15)
            {
                ferro_velho(amb);

            }

            ViatOcupAmb = ViatOcupAmb->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaAmb[0] + ForcaAmb[1] + ForcaAmb[2] + ForcaAmb[3] + ForcaAmb[4] + ForcaAmb[5] + ForcaAmb[6] + ForcaAmb[7]);
        }
        PassouSemana = 0;

    }

}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaAssaltoPolicia(Assalto* pAssalto,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //Combate "ladrão" x policia
{
    int LifeDesastre = pAssalto->PontosPolicia;
    int ForcaPolicia[2];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(policia)))
    {
        for (i=0;i<2;i++)
        {
            ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupPolic->conservacao -= 5;
            ForcaPolicia[i] = (ViatOcupPolic->conservacao)*100;

            if (ViatOcupPolic->conservacao < 15)
            {
                ferro_velho(policia);
            }

            ViatOcupPolic = ViatOcupPolic->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaPolicia[0] + ForcaPolicia[1]);
        }
        PassouSemana = 0;

    }

}

//////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaMorteAmb(ListaCarros* ViatOcupAmb,Morte* pMorte,Fila* amb,int PassouSemana) //combate prova de IP x ambulancia
{
    int LifeDesastre = pMorte->PontosAmb;
    int ForcaAmb[8];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(amb)))
    {
        for (i=0;i<2;i++)
        {
            ViatOcupAmb->qtd_chamadas += 1; //Decrementar e Incrementar o que tiver que decrementar/incrementar
            ViatOcupAmb->conservacao -= 5;
            ForcaAmb[i] = (ViatOcupAmb->conservacao)*100;

            if (ViatOcupAmb->conservacao < 15)
            {
                ferro_velho(amb);

            }

            ViatOcupAmb = ViatOcupAmb->prox;

        }
        if(PassouSemana != 0)
        {
             LifeDesastre = LifeDesastre - (ForcaAmb[0] + ForcaAmb[1]);
        }
        PassouSemana = 0;

    }

}

void LutaMortePolicia(Morte* pMorte,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //Combate "ladrão" x policia
{
    int LifeDesastre = pMorte->PontosPolicia;
    int ForcaPolicia[2];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(policia)))
    {
        for (i=0;i<3;i++)
        {
            ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupPolic->conservacao -= 5;
            ForcaPolicia[i] = (ViatOcupPolic->conservacao)*100;

            if (ViatOcupPolic->conservacao < 15)
            {
                ferro_velho(policia);
            }

            ViatOcupPolic = ViatOcupPolic->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaPolicia[0] + ForcaPolicia[1] + ForcaPolicia[2]);
        }
        PassouSemana = 0;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void LutaChacinaAmb(Chacina* pChacina,ListaCarros* ViatOcupAmb, Fila* amb,int PassouSemana) //combate incendio x ambulancias, so pode ser chamada depois de chamada a funcao acima
{
    int LifeDesastre = pChacina->PontosAmb;
    int ForcaAmb[4];
    int i;

    while (LifeDesastre > 0 && !(fila_vazia(amb)))
    {
        for (i=0;i<4;i++)
        {
            ViatOcupAmb->qtd_chamadas += 1; //Decrementar e incrementar o que tiver que decrementar/incrementar
            ViatOcupAmb->conservacao -= 5;
            ForcaAmb[i] = (ViatOcupAmb->conservacao)*100;

            if (ViatOcupAmb->conservacao < 15)
            {
                ferro_velho(amb);

            }
            ViatOcupAmb = ViatOcupAmb->prox;
        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaAmb[0] + ForcaAmb[1] + ForcaAmb[2] + ForcaAmb[3]);
        }
        PassouSemana = 0;
    }
}

void LutaChacinaPolicia(Chacina* pChacina,ListaCarros* ViatOcupPolic,Fila* policia,int PassouSemana) //Combate Alien x policia
{
    int LifeDesastre = pChacina->PontosPolicia;
    int ForcaPolicia[5];
    int i;


    while ((LifeDesastre > 0) && !(fila_vazia(policia)))
    {
        for (i=0;i<5;i++)
        {
            ViatOcupPolic->qtd_chamadas += 1; //Decrementar e pIncrementar o que tiver que decrementar/pIncrementar
            ViatOcupPolic->conservacao -= 5;
            ForcaPolicia[i] = (ViatOcupPolic->conservacao)*100;

            if (ViatOcupPolic->conservacao < 15)
            {
                ferro_velho(policia);
            }

            ViatOcupPolic = ViatOcupPolic->prox;

        }
        if(PassouSemana != 0)
        {
            LifeDesastre = LifeDesastre - (ForcaPolicia[0] + ForcaPolicia[1] + ForcaPolicia[2] + ForcaPolicia[3] + ForcaPolicia[4]);
        }
        PassouSemana = 0;
    }

}

//----------------------------------------------------------------------------------------

void imprime_prova(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_prova = load_bitmap("aviso_prova.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_prova, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_prova);
}

void imprime_alien(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_alien = load_bitmap("aviso_alien.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_alien, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_alien);
}

void imprime_mst(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_mst = load_bitmap("aviso_mst.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_mst, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_mst);
}

void imprime_meteor(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_meteoro = load_bitmap("aviso_meteoro.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_meteoro, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_meteoro);
}

void imprime_enchente(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_enchente = load_bitmap("aviso_enchente.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_enchente, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_enchente);
}

void imprime_incendio(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_incendio = load_bitmap("aviso_incendio.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_incendio, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_incendio);
}


//parte para imprimir as sprites
void imprimir_combates_D (BITMAP *tela, char matriz_terreno[][17], int *qualDesastre, Fila *bomb, Fila *amb, Fila *policia, Incendio *pInc, Enchentes *pEnch, Meteoritos *pMeteoro, Alien *pAlienigena, mst *pInvMST, IP *pProva, Assalto *pAssalto, Morte *pMorte, Chacina *pChacina, int slotViaturaA, int slotViaturaB, int slotViaturaP, ListaCarros *ViatOcupBomb, ListaCarros *ViatOcupAmb, ListaCarros *ViatOcupPolic,int PassouSemana)
{
    int  i, j = 0;
    int cont_area = 0; //vai ver se a qtde de viaturas é suficiente

    if (*qualDesastre == 1)
    {
        //prova ip
        inicializarCombateIP(pProva);
        slotViaturaA = pProva->SlotsAmb;

        //colocar um aviso que uma prova de ip está ocorrendo, quando o usuário clicar em OK, o aviso desaparece e imprime a sprite de combater
        imprime_prova(tela); //função vai imprimir msg dizendo que houve prova de IP

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if (ViatOcupAmb != NULL)
        {
            LutaIPAmb(ViatOcupAmb, pProva, bomb,PassouSemana);
        }
    }
    else if (*qualDesastre == 2)
    {
        //alien
        inicializarCombateAlien(pAlienigena);
        slotViaturaB = pAlienigena->SlotsBomb;
        slotViaturaA = pAlienigena->SlotsAmb;
        slotViaturaP = pAlienigena->SlotsPolicia;

        imprime_alien(tela);

        ViatOcupBomb = Pegar_viatura(bomb, ViatOcupBomb, slotViaturaB);
        if(ViatOcupBomb != NULL)
        {
            LutaAlienBomb(pAlienigena, ViatOcupBomb, bomb,PassouSemana);
        }

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaAlienAmb(pAlienigena, ViatOcupAmb, amb,PassouSemana);
        }

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaAlienPolicia(pAlienigena, ViatOcupPolic, policia,PassouSemana);
        }
    }
    else if (*qualDesastre == 3)
    {
        //MST
        inicializarCombateMST(pInvMST);
        slotViaturaP = pInvMST->SlotsPolicia;

        imprime_mst(tela);

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaMSTPolicia(pInvMST, ViatOcupPolic, policia,PassouSemana);
        }

    }
    else if (*qualDesastre == 4)
    {
        //meteoritos
        inicializarCombateMeteoritos(pMeteoro);
        slotViaturaA = pMeteoro->SlotsAmb;
        slotViaturaB = pMeteoro->SlotsBomb;
        slotViaturaP = pMeteoro->SlotsPolicia;

        imprime_meteor(tela);

        ViatOcupBomb = Pegar_viatura(bomb, ViatOcupBomb, slotViaturaB);
        if(ViatOcupBomb != NULL)
        {
            LutaMeteoBomb(ViatOcupBomb, pMeteoro, bomb,PassouSemana);
        }

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaMeteoAmb(pMeteoro, ViatOcupAmb, amb,PassouSemana);
        }

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaMeteoPolic(pMeteoro, ViatOcupPolic, policia,PassouSemana);
        }

    }
    else if (*qualDesastre == 5)
    {
        //enchentes
        inicializarCombateEnchente(pEnch);
        slotViaturaA = pEnch->SlotsAmb;
        slotViaturaB = pEnch->SlotsBomb;

        imprime_enchente(tela);

        ViatOcupBomb = Pegar_viatura(bomb, ViatOcupBomb, slotViaturaB);
        if(ViatOcupBomb != NULL)
        {
            LutaEnchBomb(pEnch, ViatOcupBomb, bomb,PassouSemana);
        }

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaEnchAmb(pEnch, ViatOcupAmb, amb,PassouSemana);
        }
    }
    else if (*qualDesastre == 6)
    {
        //incendio
        inicializarCombateIncendio(pInc);
        slotViaturaA = pInc->SlotsAmb;
        slotViaturaB = pInc->SlotsBomb;

        imprime_incendio(tela);

        ViatOcupBomb = Pegar_viatura(bomb, ViatOcupBomb, slotViaturaB);
        if(ViatOcupBomb != NULL)
        {
            LutaIncendBomb(pInc, ViatOcupBomb, bomb, PassouSemana);
        }

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaIncendAmb(pInc, ViatOcupAmb, amb,PassouSemana);
        }
    }

    // se *qualdesastre não for isso ele não faz nada e sai da função

    *qualDesastre = 0; //para que ele não repita a mesma função desnecessariamente
}

//-----------------------------------------------------------------------------
//o mesmo que acima só que para crimes

void imprime_assalto(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_assalto = load_bitmap("aviso_assalto.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_assalto, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_assalto);
}

void imprime_morte(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_morte = load_bitmap("aviso_morte.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_morte, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_morte);
}

void imprime_chacina(BITMAP *tela)
{
    BITMAP *buffer = create_bitmap(800,600);
    BITMAP *mouse = load_bitmap("mouse2.bmp", NULL);
    BITMAP *aviso_chacina = load_bitmap("aviso_chacina.bmp", NULL);
    int aux=0;

    while (aux == 0)
    {
        draw_sprite(buffer, tela, 0, 0);
        draw_sprite(buffer, aviso_chacina, 540, 16);
        draw_sprite(buffer, mouse, mouse_x, mouse_y);
        draw_sprite(screen, buffer, 0, 0);

        if (mouse_b&1 && mouse_x>630 && mouse_x<685 && mouse_y>190 && mouse_y<230)
        {
            aux = 1;
        }
    }

    destroy_bitmap(mouse);
    destroy_bitmap(buffer);
    destroy_bitmap(aviso_chacina);
}

void imprimir_combates_C(BITMAP *tela, char matriz_terreno[][17], int *qualCrime, Fila *bomb, Fila *amb, Fila *policia, Assalto *pAssalto, Morte *pMorte, Chacina *pChacina, int slotViaturaA, int slotViaturaB, int slotViaturaP, ListaCarros *ViatOcupBomb, ListaCarros *ViatOcupAmb, ListaCarros *ViatOcupPolic,int PassouSemana)
{
    int i, j;

    if (*qualCrime == 1)
    {
        //chacina
        inicializarChacina(pChacina);
        slotViaturaA = pChacina->SlotsAmb;
        slotViaturaP = pChacina->SlotsPolicia;

        imprime_chacina(tela);

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaChacinaPolicia(pChacina, ViatOcupPolic, policia, PassouSemana);
        }


        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaChacinaAmb(pChacina, ViatOcupAmb, amb, PassouSemana);

        }
    }
    else if (*qualCrime == 2)
    {
        //morte
        inicializarMorte(pMorte);
        slotViaturaA = pMorte->SlotsAmb;
        slotViaturaP = pMorte->SlotsPolicia;

        imprime_morte(tela);

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaMortePolicia(pMorte, ViatOcupPolic, policia, PassouSemana);

        }

        ViatOcupAmb = Pegar_viatura(amb, ViatOcupAmb, slotViaturaA);
        if(ViatOcupAmb != NULL)
        {
            LutaMorteAmb(ViatOcupAmb, pMorte,amb, PassouSemana);

        }

    }
    else if (*qualCrime == 3)
    {
        //assalto
        inicializarAssalto(pAssalto);
        slotViaturaP = pAssalto->SlotsPolicia;

        imprime_assalto(tela);

        ViatOcupPolic = Pegar_viatura(policia, ViatOcupPolic, slotViaturaP);
        if(ViatOcupPolic != NULL)
        {
            LutaAssaltoPolicia(pAssalto, ViatOcupPolic, policia, PassouSemana);
        }

    }

    *qualCrime = 0;
}



#endif // COMBATE_H_INCLUDED
