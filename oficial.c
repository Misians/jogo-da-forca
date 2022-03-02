#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>


struct jogador{
    char nomedojogador[8];
    int pontuacao;
};
struct jogador pessoa[3];


void playerA(){

    printf(" Digite o nome do player: ");
    scanf("%s%*c", &pessoa[1].nomedojogador);
}

void pontos(int status){


    int i;
    int erros = 0, acertos = 0;
    erros = status * 30;
    pessoa[1].pontuacao = 180 - erros;
    printf("\n\n");
    printf(" \n O PLAYER: %s ", pessoa[1].nomedojogador);
    printf("OBTEVE: %d", pessoa[1].pontuacao);

}
/*void record(){


    int i;
    if(pessoa[0].nomedojogador == ""){
        printf("Não tem nenhum record no histórico");
    }
    for(i = 0; i < 3; i++){
        if((pessoa[0].pontuacao > pessoa[1].pontuacao) && pessoa[1].pontuacao > pessoa[2].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[0].nomedojogador, pessoa[0].pontuacao);
        }
        else if((pessoa[0].pontuacao > pessoa[2].pontuacao) && pessoa[2].pontuacao > pessoa[1].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[0].nomedojogador, pessoa[0].pontuacao);
        }
        else if((pessoa[1].pontuacao > pessoa[0].pontuacao) && pessoa[0].pontuacao > pessoa[2].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[1].nomedojogador, pessoa[1].pontuacao);
        }
        else if((pessoa[1].pontuacao > pessoa[2].pontuacao) && pessoa[2].pontuacao > pessoa[0].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[1].nomedojogador, pessoa[1].pontuacao);
        }
        else if((pessoa[2].pontuacao > pessoa[0].pontuacao) && pessoa[0].pontuacao > pessoa[1].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[2].nomedojogador, pessoa[2].pontuacao);
        }
        else if((pessoa[2].pontuacao > pessoa[1].pontuacao) && pessoa[1].pontuacao > pessoa[0].pontuacao){
                printf("HIGHSCORE");
                printf("JOGADOR: %s PONTOS: %d", pessoa[2].nomedojogador, pessoa[2].pontuacao);
        }
    }
}*/

void strToUpper(char str[]) {


    int i = 0;
    while(str[i] != '\0') {
        str[i] = toupper(str[i]);
        i++;
    }
}

void forca(int status){
    int i;
  if(status==0){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
  }
  else if(status==1){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
  }
  else if(status==2){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
  }
  else if(status==3){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|         /|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
  }
  else if(status==4){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|         /|\\");
    printf("\n|");
    printf("\n|");
    printf("\n|");
  }
  else if(status==5){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|         /|\\");
    printf("\n|         / ");
    printf("\n|");
    printf("\n|");
  }
  else if (status==6){
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          O");
    printf("\n|         /|\\ ");
    printf("\n|         / \\ ");
    printf("\n|");
    printf("\n|");

        }
    }

char palavrasfaceis(){
  int sorteado, i;
  char nomedojogador1[10];
  char palavra[50];
  char* nomes[9];

  playerA();
  //Palavras que irao ser sorteadas
  printf("\nDICA - NIVEL FACIL - OBJETOS\n");
  nomes[0] = "caixa";
  nomes[1] = "sapato";
  nomes[2] = "caneta";
  nomes[3] = "tecido";
  nomes[4] = "quadro";
  nomes[5] = "filtro";
  nomes[6] = "bolsa";
  nomes[7] = "celular";
  nomes[8] = "tomada";
  nomes[9] = "estojo";

      srand(time(NULL));
      //sorteia a palavra
      for (i = 0; i < 1; i++) {
          sorteado = rand() % 9;
      }
        strcpy(palavra, nomes[sorteado]);


      char palavra_tela[50];

      strcpy(palavra_tela, palavra);
      for (size_t i = 0; i < strlen(palavra_tela); i++) {
        palavra_tela[i]= '_';
        //system("cls");
      }
      int status = 0;
      int j = 0;
      while (status != 6) {
        char letras_usadas[25];
        forca(status);
        printf("PALAVRA: ");

        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          printf("%c ",palavra_tela[i] );
        }

        char letra[20];
        printf("\n");
        printf("\nDigite a letra: ");// recebe a letra
        scanf("%s", &letra );//primeiro caractere digitado
        printf("\n");
        //converte a letra em maiuscula
        letras_usadas[j] = letra[0];

        for (i = 0; i <= j; i++){
            printf("%c ", letras_usadas[i] );
        }
        // ja entra com 1 erro, caso a palavraconter a letra o erro recebe zero
        int erro = 1;

        //verificando se a palavra contem a letra
        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          if (letra[0]==palavra[i]) {
             palavra_tela[i] = letra[0];
             //se possuir a letra o erro recebe zero
             erro = 0;
          }
        }
        //se a palavra nao conter a letra o status incrementa 1
        if (erro==1){
          status++;
        }
        if (status==6){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
            //system("cls");
          }
          printf("\n\n************** VOCE PERDEU! ****************" );
          break;
        }
        if(strcmp(palavra,palavra_tela)==0){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
          }
          printf("\n\n############# VOCE GANHOU! #################" );
          break;
        }
        j++;
      }
      printf("\n");
      pontos(status);
  }

char palavrasmedias(){
  int sorteado, i;
  char nomedojogador1[10];
  char palavra[50];
  char* nomes[9];

  playerA();
  //Palavras que irao ser sorteadas
  printf("\n- NIVEL MEDIO n");
  nomes[0] = "helicoptero";
  nomes[1] = "ar-condicionado";
  nomes[2] = "refrigerador";
  nomes[3] = "cachorro-quente";
  nomes[4] = "micro-organismo";
  nomes[5] = "anti-inflamatorio";
  nomes[6] = "pos-graduacao";
  nomes[7] = "micro-ondas";
  nomes[8] = "autoretrato";
  nomes[9] = "microbiologista";
  nomes[9] = "anticoncepcional";

      srand(time(NULL));
      //sorteia a palavra
      for (i = 0; i < 1; i++) {
          sorteado = rand() % 9;
      }
        strcpy(palavra, nomes[sorteado]);


      char palavra_tela[50];

      strcpy(palavra_tela, palavra);

      for (size_t i = 0; i < strlen(palavra_tela); i++) {// substituios caracteres palavra_tela por undescore
        palavra_tela[i]= '_';
        //system("cls");
      }

      int status = 0;
      int j = 0;
      while (status != 6) {
        char letras_usadas[25];
        forca(status);
        printf("PALAVRA: ");

        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          printf("%c ",palavra_tela[i] );
        }

        char letra[20];
        printf("\n");
        printf("\nDigite a letra: ");// recebe a letra
        scanf("%s", &letra );//primeiro caractere digitado
        printf("\n");
        //converte a letra em maiuscula
        letras_usadas[j] = letra[0];

        for (i = 0; i <= j; i++){
            printf("%c ", letras_usadas[i] );
        }
        // ja entra com 1 erro, caso a palavraconter a letra o erro recebe zero
        int erro = 1;

        //verificando se a palavra contem a letra
        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          if (letra[0]==palavra[i]) {
             palavra_tela[i] = letra[0];
             //se possuir a letra o erro recebe zero
             erro = 0;
          }
        }
        //se a palavra nao conter a letra o status incrementa 1
        if (erro==1){
          status++;
        }
        if (status==6){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
            //system("cls");
          }
          printf("\n\n************** VOCE PERDEU! ****************" );
          break;
        }
        if(strcmp(palavra,palavra_tela)==0){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
          }
          printf("\n\n############# VOCE GANHOU! #################" );
          break;
        }
        j++;
      }
      printf("\n");
      pontos(status);
}

char palavrasdificeis(){
  int sorteado, i;
  char nomedojogador1[10];
  char palavra[50];
  char* nomes[9];

  playerA();
  //Palavras que irao ser sorteadas
  printf("\n - NIVEL DIFICIL \n");
  nomes[0] = "anticonstitucionalismo";
  nomes[1] = "desinstitucionalizando";
  nomes[2] = "otorrinolaringologista";
  nomes[3] = "transdisciplinaridade";
  nomes[4] = "pluridimensionalidade";
  nomes[5] = "extraterritorialidade";
  nomes[6] = "desproporcionadamente";
  nomes[7] = "contrarrevolucionario";
  nomes[8] = "desincompatibilizacao";
  nomes[9] = "desprofissionalizacao";

      srand(time(NULL));
      //sorteia a palavra
      for (i = 0; i < 1; i++) {
          sorteado = rand() % 9;
      }
        strcpy(palavra, nomes[sorteado]);


      char palavra_tela[50];

      strcpy(palavra_tela, palavra);

      for (size_t i = 0; i < strlen(palavra_tela); i++) {// substituios caracteres palavra_tela por undescore
        palavra_tela[i]= '_';
        //system("cls");
      }

      int status = 0;
      int j = 0;
      while (status != 6) {
        char letras_usadas[25];
        forca(status);
        printf("PALAVRA: ");

        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          printf("%c ",palavra_tela[i] );
        }

        char letra[20];
        printf("\n");
        printf("\nDigite a letra: ");// recebe a letra
        scanf("%s", &letra );//primeiro caractere digitado
        printf("\n");
        //converte a letra em maiuscula
        letras_usadas[j] = letra[0];

        for (i = 0; i <= j; i++){
            printf("%c ", letras_usadas[i] );
        }
        // ja entra com 1 erro, caso a palavraconter a letra o erro recebe zero
        int erro = 1;

        //verificando se a palavra contem a letra
        for (size_t i = 0; i < strlen(palavra_tela); i++) {
          if (letra[0]==palavra[i]) {
             palavra_tela[i] = letra[0];
             //se possuir a letra o erro recebe zero
             erro = 0;
          }
        }
        //se a palavra nao conter a letra o status incrementa 1
        if (erro==1){
          status++;
        }
        if (status==6){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
            //system("cls");
          }
          printf("\n\n************** VOCE PERDEU! ****************" );
          break;
        }
        if(strcmp(palavra,palavra_tela)==0){
          forca(status);
          printf("PALAVRA: ");
          for (size_t i = 0; i < strlen(palavra_tela); i++) {
            printf("%c ",palavra_tela[i] );
          }
          printf("\n\n############# VOCE GANHOU! #################" );
          break;
        }
        j++;
      }
      printf("\n");
      pontos(status);
}

void tutorial(){
      FILE *arq;
  char Linha[100];
  char *result;
  int i;
  arq = fopen("tutorial.txt", "rt");
  if (arq == NULL)  // Se houve erro na abertura
  {
     printf("Problemas na abertura do arquivo\n");
  }
  i = 1;
  while (!feof(arq))
  {
      result = fgets(Linha, 100, arq);
      if (result)
	  printf("Linha %d : %s",i,Linha);
      i++;
  }
  fclose(arq);
}



int main(){
    int opcao, i;
    int dificuldade = 0;
    int sorteado;
    int status;
    char jogar;
    char palavra[50];
    struct jogador pessoa[3];

    while(1){
      printf("\n 1- Jogar");
      printf("\n 2- Tutorial");
      printf("\n 3- Sair");
      //printf("\n 4 - Record");
      printf("\n");
      printf("\n Apenas Aperte o numero da opcao para continuar  ");
      scanf("%d", &opcao);
      printf("\n" );

      if (opcao == 3) {
        exit(1);
      }
      else if(opcao == 2){
        tutorial();
      }
      switch (opcao) {
          case 1:
              printf("DIFICULDADE\n 1 - FACIL\n 2 - MEDIO\n 3 - DIFICIL\n");
              scanf("%d", &dificuldade);
              if(dificuldade == 1){
                  palavrasfaceis();
              }
              else if(dificuldade == 2){
                  palavrasmedias();
              }
              else if(dificuldade == 3){
                  palavrasdificeis();
              }
              else{
                  printf("COMANDO INVALIDO!");
              }
              break;

          case 2:
              tutorial();
              break;

          case 3:
              printf ("\nSaindo do game...\n");
          system("pause");
          exit(0);
              break;
          default:
              printf("Op��o Inv�lida!");
              break;
      }
    }

  return 0;
}

