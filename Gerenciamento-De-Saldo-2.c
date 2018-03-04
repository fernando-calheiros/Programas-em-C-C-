#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int Registrar_Saldo(){
  printf("\n");
  int debito, card;
  int hora, minuto, segundo, dia, mes, ano;
  struct tm *local;
  time_t t;
  t = time(NULL);
  local=localtime(&t);

  hora = local->tm_hour;
  minuto = local->tm_min;
  segundo = local->tm_sec;

  dia = local->tm_mday;
  mes = local->tm_mon;
  ano = local->tm_year;
  ano = ano + 118;

  FILE *arq;
  char string[100];

  arq = fopen("financas.txt", "a+");
  if(arq==NULL){
    printf("Erro na abertura");
    exit(1);
  }
  printf("Dinheiro no Debito:");
  scanf("%d", &debito);
  printf("Dinheiro na mao:");
  scanf("%d", &card);
  fscanf(arq, 0, SEEK_END);
  fprintf(arq, "Data:%d/%d/%d \t Hora:%d:%d:%d\n", dia, mes, ano, hora, minuto, segundo);
  fprintf(arq, "Dinheiro no Debito:%d\n", debito);
  fprintf(arq, "Dinheiro na mao: %d\n\n", card);

  fclose(arq);
  return 0;

}

int Exibir_Saldo(){
    FILE *arq;
    char str[100];
    char *result;
    int i;
    printf("\n");
    arq = fopen("financas.txt", "rt");
    if (arq == NULL){
      printf("Erro ao abrir arquivo");
      return 1;
    }
    while (!feof(arq)){
      result = fgets(str, 100, arq);
      if (result){
        printf("%s", str);
      }
    }
}

int main(){
  int i;
  system("clear");
  do{
    int opt;
    printf("##################################\n");
    printf("[1] Registrar Saldo              #\n");
    printf("[2] Exibir Saldos Registrados    #\n");
    printf("##################################\n");
    printf("Escolha uma opção:");
    scanf("%d", &opt);
    switch(opt){
      case 1:
        Registrar_Saldo();
      case 2:
        Exibir_Saldo();
    }

  }while(i==0);
}
