#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
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
  fprintf(arq, "Dinheiro na mao: %d\n", card);


  return 0;
}
