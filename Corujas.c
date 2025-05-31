/*  
    Trabalho: Simulador de corujas
    Aluno: Lucas L. B. Barbosa
    S.A: 2021017872
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int rm=1, farOs=0, bg=0, jg=0, lin, col, i, j; //todas essas variaveis foram deixadas publicas pois seriam declaradas ou
char cav[25][90];                              //passadas como parametros na maioria das funções

void loading(char s[100]){ //função encarregada por fazer a transição visual das jogadas
    system("cls");
    for(i=5;i>0;i--){
        printf("\n\n\n\n\n\n\n\n\n%s", s);
        printf("\n\t\t\t\t  Voce podera jogar em %d", i);
        sleep(1);
        system("cls");
    }

}//end loading

void morcego(char a, char b, char c, char d){ //adiciona morcegos na matriz(feito em função por ser chamada em duas partes diferentes)
    int contr;
    contr=0;
    while(contr<31){  //morcegos
        i=rand()%13+6;
        j=rand()%90;
        if(cav[i][j]==a || cav[i][j]==b || cav[i][j]==c || cav[i][j]==d){
            cav[i][j]='W';
            contr++;
        }
    }
} //end morcego

void design(int esq, int dir){ //faz um envoltorio na matriz
    for(i=0;i<95;i++){
        if(i>3){
            if(i==4){
                printf("%c", esq); //primeiro caracter (canto esquerdo)
            }else{
                printf("%c", 205);
            }
        }else{
            printf(" ");
        }
    }
    printf("%c\n", dir); //ultimo caracter (canto direito)
} //end design

void inicializa(){
    int sort;
    for(i=0;i<25;i++){ //atribui um valor fixo para evitar lixos de memoria
        for(j=0;j<90;j++){
            cav[i][j]=' ';
        }
    }

    for(i=0;i<10;i++){ //Ramo
        sort=rand()%90;
        if(cav[0][sort]==' '){ //evita sobreposiçôes
            cav[0][sort]=':';
        }else{
            i--;
        }
    }

    for(i=0;i<4;i++){ //rochas 2-2-2-2-2
        sort=rand()%89; //maior numero gerado 88, assim sort+1 será no maximo 89
        if(cav[24][sort]==' ' &&  cav[24][sort+1]==' '){
            cav[24][sort]='.';
            cav[23][sort]='.';
            cav[22][sort]='.';
            cav[21][sort]='.';
            cav[20][sort]='.';

            cav[24][sort+1]='.';
            cav[23][sort+1]='.';
            cav[22][sort+1]='.';
            cav[21][sort+1]='.';
            cav[20][sort+1]='.';
        }else{
            i--;
        }
    }

    for(i=0;i<3;i++){ //rochas 3-3-3-3-3-3
        sort=rand()%88; //mesma logica usada a cima, porém para sort+2
        if(cav[24][sort]==' ' && cav[24][sort+1]==' ' && cav[24][sort+2]==' '){
            cav[24][sort]='.';
            cav[23][sort]='.';
            cav[22][sort]='.';
            cav[21][sort]='.';
            cav[20][sort]='.';
            cav[19][sort]='.';

            cav[24][sort+1]='.';
            cav[23][sort+1]='.';
            cav[22][sort+1]='.';
            cav[21][sort+1]='.';
            cav[20][sort+1]='.';
            cav[19][sort+1]='.';

            cav[24][sort+2]='.';
            cav[23][sort+2]='.';
            cav[22][sort+2]='.';
            cav[21][sort+2]='.';
            cav[20][sort+2]='.';
            cav[19][sort+2]='.';
        }else{
            i--;
        }
    }

    for(i=0;i<10;i++){ //estalagmites
        sort=rand()%90;
        if(cav[24][sort]==' '){
            cav[24][sort]='^';
        }else{
            i--;
        }
    }

    sort=0;
    while(sort<13){  //corujas (em while pra dar uma variada)
        i=rand()%13+6;
        j=rand()%90;
        if(cav[i][j]==' '){
            cav[i][j]='V';
            sort++;
        }
    }

    morcego(' ', ' ', ' ', ' ');
} //end inicializar

int imprime(){
    int cntCor;
    printf("\n               11111111112222222222333333333344444444445555555555666666666677777777778888888888\n");
    printf("     012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789\n");
    cntCor==0; //contada as corujas no tabuleiro para finalizar a partida
    design(201, 187);
    for(i=0;i<25;i++){
        printf("%2d->%c", i, 186);
        for(j=0;j<91;j++){
            if(j!=90){
                printf("%c", cav[i][j]);
                if(cav[i][j]=='V' || cav[i][j]=='v'){
                    cntCor++;
                }
            }else{
                printf("%c", 186);
            }
        }
        printf("\n");
    }
    design(200, 188);
    return cntCor;
} //end imprime

void fertilizar(){
    if(farOs>=1){ //checagem se há farinha de osso
        printf("Informe o ramo que deseja fertilizar [lin col]: ");
        scanf("%d %d", &lin, &col);
        getchar();
        if(lin>=0 && lin<25 && col>=0 && col<90){ //checagem se pertencem aos limites da matriz
            if(cav[lin][col]==':'){ //checagem se há ramo
                cav[lin][col]='%';
                jg++;
                farOs--;
            }else{  //mensagens de erro
                loading("\n\t\t\t\tNao ha RAMO no local informado!!!\n");
            }
        }else{
            loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
        }
    }else{
        loading("\n\t\t\tNao ha FARINHA DE OSSO para a fertilizacao!!\n");
        getchar();
    }
}
 /*as próximas funções tem estruturas parecidas, por isso não serão tão comentadas, a menos
 que tenha algo de diferente não antes comentado*/
void colher(){
    printf("Informe o ramo(:) ou baga(%) que deseja colher [lin col]: ");
    scanf("%d %d", &lin, &col);
    getchar();

    if(lin>=0 && lin<25 && col>=0 && col<90){
        if(cav[lin][col]==':' || cav[lin][col]=='%'){
            for(i=lin;i<25;i++){ //percorre a coluna para encontrar outras bagas ou ramos apartir da posição selecionada
                if(cav[i][col]==':'){
                    cav[i][col]=' ';
                    rm++;
                }else{
                    if(cav[i][col]=='%'){
                        cav[i][col]=' ';
                        bg++;
                    }
                }
            }
            jg++;
        }else{
            loading("\n\t\t\t Nao ha RAMO ou BAGA no local informado\n");
        }
    }else{
        loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
    }
}//end colher

void ninho(){
    if(rm>=4){
        printf("Informe o local onde deseja construir o ninho[lin col]: ");
        scanf("%d %d", &lin, &col);
        getchar();

        if(lin>=0 && lin<24 && col>=0 && col<90){
            if(cav[lin+1][col]=='.'){ //verifica se há rocha para apoiar o ninho
                if(cav[lin][col]==' '){
                    cav[lin][col]='#';
                    rm=rm-4;
                    jg++;
                }else{
                    loading("\n\t\t\tInforme uma posicao VAZIA para construir o ninho\n");
                }
            }else{
                loading("\n\t\t Nao ha uma ROCHA ELEVADA o suficiente para apoiar o ninho!\n");
            }
        }else{
            loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
        }
    }else{
        loading("\n\t\tQuantidade de RAMOS insuficiente!! Necessario no minimo 4\n");
        getchar();
    }
}//end ninho

void alimentar(){
    printf("Informe a posição da coruja(V ou v) que deseja alimentar [lin col]: ");
    scanf("%d %d", &lin, &col);
    getchar();

    if(bg>0){
        if(lin<25 && lin>=0 && col>=0 && col<90){
            if(cav[lin][col]=='v'){ //caso haja uma coruja filhote na posição informada
                cav[lin][col]='V';
                bg--;
                jg++;
            }else{
                if(cav[lin][col]=='V'){//caso haja uma coruja adulta
                    bg--;
                    if(lin+2<24){
                        if(cav[lin+1][col]=='V' && cav[lin+2][col]=='#'){ //condição separada apenas para gerar mensagens de erros diferentes
                            cav[lin+2][col]='v';
                            jg++;
                            loading("\n\t\t\t\tNasceu um filhote");
                        }
                    }
                }else{
                    loading("\n\t\t\t  Nao ha CORUJA na coordenada informada\n");
                }//end caso coruja adulta
            }
        }else{
            loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
        }
    }else{
        loading("\n\t\t\t\tSaldo de BAGA insuficiente!!\n");
    }
}//end alimentar

void mover(){
    printf("Informe a coruja(V ou v) que deseja mover [lin col]: ");
    scanf("%d %d", &lin, &col);
    getchar();

    if(lin>=0 && lin<25 && col>=0 && col<90){
        if(cav[lin][col]=='v' || cav[lin][col]=='V'){
            printf("Informe informe para qual posicao deseja mover a coruja [lin col]: ");
            scanf("%d %d", &i, &j);
            getchar();

            if(i!=lin || j!=col){
                if(i>=0 && i<25 && j>=0 && j<90){
                    if((abs(i-lin)<=1) && (abs(j-col)<=1)){ //restringindo movimentação à uma casa
                        if(cav[i][j]==' '){ //movimento normal
                            cav[i][j]=cav[lin][col];
                            cav[lin][col]=' ';
                            jg++;
                        }else{
                            if(cav[i][j]=='W'){ //morte do morcego
                                cav[i][j]=cav[lin][col];
                                cav[lin][col]=' ';
                                farOs++;
                                jg++;
                            }else{
                                loading("\n\t\t\t  Movimento invalido!!!\n");
                            }
                        }
                    }else{
                        loading("\n\t\t  Voce pode mover a coruja apenas UMA CASA por vez!!\n");
                    }
                }else{
                    loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
                }
            }else{
                loading("\n\t\t\tInforme POSICOES DIFERENTES para movimentar!\n");
            }
        }else{
            loading("\n\t\t\tInforme uma posicao com CORUJA!!\n");
        }
    }else{
        loading("\n\t\t\t\t  Coordenadas invalidas!!\n");
    }
}//end mover

int dia(){
    int adc, ocrR, ocrE;
    jg=1;
    ocrR=0; //ambas as variaveis ocr indicaram se ocorreu crescimento de (R)amo
    ocrE=0; //ou (E)stalagmite para incrementar uma jogada cada
    for(i=0;i<25;i++){
        for(j=0;j<90;j++){

            if(i==0){ //crescimento de ramos
                if(cav[i][j]==':' && rand()%100<15){
                    adc=0;
                    lin=1; //troca da variavel para alteração do valor a fim de percorrer a coluna

                    while(lin<25 && adc<1){ //looping garantido crescimento caso já haja ramo abaixo

                        //restrição para crescimento de ramo apenas abaixo de ramo ou baga
                        if(cav[lin][j]==' ' && (cav[lin-1][j]==':' || cav[lin-1][j]=='%')){
                            cav[lin][j]=':';
                            adc++; //variavel que controla apenas uma adição por vez
                            ocrR++;
                        }
                        lin++;
                    }//end looping 1
                }
            }//end cresRamos

            if(cav[i][j]=='W'){ //retirando morcegos
                cav[i][j]=' ';
            }//end retMorcegos

            if(i==24){ //crescimento de estalagmites(segue a mesma logica do crescimento de ramos)
                if(cav[i][j]=='^' && rand()%100<15){
                    adc=0;
                    lin=23;
                    while(lin>-1 && adc==0){ //looping garantido crescimento caso já haja estalagmite a cima

                        //restrição para crescimento de estalagmite apenas acima de outra
                        if(cav[lin][j]==' ' && (cav[lin+1][j]=='^')){
                            cav[lin][j]='^';
                            adc++;
                            ocrE++;
                        }
                        lin--;
                    }//end looping 2
                }
            }//end cresEstalagmites
        }
    }//end for(i)

    if(ocrE>0){
        jg++;
    }
    if(ocrR>0){
        jg++;
    }
    morcego(' ', 'v', 'V', '#');
    loading("\t\tPeriodo do dia em andamento, espere a noite chegar");

}

int main(int argc, char *argv){
    char selc=' ';
    srand(time(NULL));
    inicializa();
    loading("\t\t\t\t     Iniciando o jogo\n \t\t\t(Jogue em tela cheia para uma experiencia melhor)");
    while(selc!='s'){
        system("cls");
        if(imprime()==0){ //jogo acaba devido a falta de corujas
         printf("==========================================Game Over==========================================");
         break;
        }
        printf("-------------------------------Ramos=%d, Farinha de osso=%d, Baga=%d-------------------------------\n", rm, farOs, bg);
        printf("\t\t(f)ertilizar / (c)olher / (n)inho / (a)limentar / (m)over / (s)air");
        printf("\n[Jogada %d]Selecione uma opcao: ", jg);
        selc=getchar();

        switch (selc){
        case 'f':
            fertilizar();
            break;

        case 'c':
            colher();
            break;

        case 'n':
            ninho();
            break;

        case 'a':
            alimentar();
            break;

        case 'm':
            mover();
            break;

        case 's':
            system("cls");
            printf("\n_____ \t\t\t\t\t       _____");
            printf("\n  `%c/{o,o} \t\t\t\t  {o,o}%c/%c", 92, 92, 239);
            printf("\n   / /)  ) \t\t\t\t  (  (%c %c", 92, 92);
            printf("\n  /,--%c-%c-", 34, 34);
            printf("  [^-^ Obrigado por jogar ^-^]  -%c-%c--,%c\n\n\n\n", 34, 34, 92);
            break;

        /*case 'd':  //caso queira testar a função dia sem fazer as 7 primeiras jogadas
            dia();
            getchar();
            break; */

        default:
            system("cls");
            getchar();
            loading("\n\t\t\t\t  [Opcao invalida!!]\n");
            break;
        }

        if(jg==7){
            dia();
        }

    }
    return 0;
}
