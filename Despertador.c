#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
  system("clear");
  int fon = 0;
  int  desp, mina;
  printf("Hora para desperta:");
  scanf("%d", &desp);
  printf("Minuto para desperta:");
  scanf("%d", &mina);
  system("clear");
  do{

    system("clear");
    int hora,min;
    struct tm *local;
    time_t t;
    t= time(NULL);
    local=localtime(&t);
    hora = local->tm_hour;
    min = local->tm_min;

    printf("Hora atual: %d:%d:00\n", hora, min);
    printf("Despertador programado para: %d:%d:00\n", desp, mina);

    if(hora==desp){
      if(min==mina){
        fon = 0;
        system("firefox https://www.youtube.com/watch?v=WixYoRTwqrU&list=RDWixYoRTwqrU");
        exit(0);
      }

    }
    sleep(60);
  }while(fon==0);

  return 0;
}
