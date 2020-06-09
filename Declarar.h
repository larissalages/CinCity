#ifndef DECLARAR_H_INCLUDED
#define DECLARAR_H_INCLUDED


    int qualDesastre;
    int qualCrime;
    int contPolicia = 0;
    int contAmbulancia = 0;
    int contBombeiro = 0;
    int contCasaDesastre[6] = {0,0,0,0,0,0};    //Essas vari�veis v�o ser utilizadas para poder contar quantas casas, por exemplo, foram afetadas pela desastre e coisa e tal
    int contFlorestaDesastre[6] = {0,0,0,0,0,0};
    int contAguaDesastre[6] = {0,0,0,0,0,0};
    int contCasaCrime[3] = {0,0,0};
    int contFlorestaCrime[3] = {0,0,0};
    int contAguaCrime[3] = {0,0,0};
    int i, j;
    int x, y;   //Coordenadas(pixels)
    int vetorI[10];  //vari�vel vai armazenar as coordenadas de onde come�am os desastres para que a gente possa imprimir as sprites das viaturas
    int vetorJ[10];
    int cont1; //vari�vel vai receber o retorno da fun��o opcoes, para que assim reduza-se a qtde de chamadas de fun��es dentro de fun��es
    int sair = 0;
    int pop_max; //Vari�vel de armazenar� a popula��o m�xima que pode ser suportada baseando-se na qtde de casas do jogo no momentos
    ///int ocorrencia=0; //Nao sei pra que isso t� servindo

    char matriz_terreno[19][17]; //Matriz que armazenar� dados do terreno
    char matriz_desastre_aux[19][17];
    Entrada *entrada_dados; //Variavel do tipo struct que armazenar� os dados de entrada da cidade
    int cont_residencias; //Vari�vel que vai receber o valor retornado pela fun��o qtde_residencias
    float taxa_imposto = 0.1; //Essa vari�vel pode sofrer altera��es no decorrer do jogo
    float imposto; //Vai guardar o valor do imposto na cidade
    int cont_impostos=0; //vari�vel vai verificar se j� passaram 4 semanas para poder assim aplicar os impostos
    int aux_construcao=0; //Essas vari�veis s�o ponteiros que ser�o passados para a fun��o construir/destruir a fim de verificar qual foi a construcao/destruicao realizada.
    int aux_destruicao=0;
    int aux_campanha=0;
    int sucesso_desastres=0;  //calcular a taxa de sucesso m�dio dos desastres
    int sucesso_crimes=0;  //calcular a taxa de sucesso m�dio dos crimes
    int tamanhoTexto = 30;
    int textoX = 120;
    int textoY = 110;
    int cor = makecol(0, 0, 0);
    int slotViaturaB;
    int slotViaturaA;
    int slotViaturaP;
    int NumBomb;
    int NumAmb;
    int NumPolicia;
    int PassouSemana;

    ListaDesastres *desastre_relatorio = NULL;

    Fila* bomb = (Fila*) malloc(sizeof(Fila));
    Fila* policia = (Fila*) malloc(sizeof(Fila));
    Fila* amb = (Fila*) malloc(sizeof(Fila));

    Incendio* pInc = (Incendio*) malloc(sizeof(Incendio));
    Enchentes* pEnch = (Enchentes*) malloc(sizeof(Enchentes));
    Meteoritos *pMeteoro = (Meteoritos*) malloc(sizeof(Meteoritos));
    Alien *pAlienigena = (Alien*) malloc(sizeof(Alien));
    mst* pInvMST = (mst*) malloc(sizeof(mst));
    IP *pProva = (IP*) malloc(sizeof(IP));
    Assalto *pAssalto = (Assalto*) malloc(sizeof(Assalto));
    Morte *pMorte = (Morte*) malloc(sizeof(Morte));
    Chacina *pChacina = (Chacina*) malloc(sizeof(Chacina));

    ListaCarros* ViatOcupBomb = (ListaCarros*) malloc(sizeof(ListaCarros));
    ListaCarros* ViatOcupAmb = (ListaCarros*) malloc(sizeof(ListaCarros));
    ListaCarros* ViatOcupPolic = (ListaCarros*) malloc(sizeof(ListaCarros));


#endif // DECLARAR_H_INCLUDED
