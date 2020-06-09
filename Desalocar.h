#ifndef DESALOCAR_H_INCLUDED
#define DESALOCAR_H_INCLUDED

void Desalocar()
{
    free(entrada_dados->pAmbulancia);
    free(entrada_dados->pBombeiro);
    free(entrada_dados->pPolicia);
    free(entrada_dados);
    free(desastre_relatorio);
    free(bomb);
    free(policia);
    free(amb);
    free(pInc);
    free(pEnch);
    free(pMeteoro);
    free(pAlienigena);
    free(pInvMST);
    free(pProva);
    free(pAssalto);
    free(pMorte);
    free(pChacina);
    free(ViatOcupBomb);
    free(ViatOcupAmb);
    free(ViatOcupPolic);

}


#endif // DESALOCAR_H_INCLUDED
