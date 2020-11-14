#include <stdio.h>
#include <string.h>
#include <time.h> //per utilizzare time()
#include <stdlib.h> //per utilizzare rand() e srand()

void get_user_input(char *input); // La funzione è commentata in fondo

int main(void){

char m[128];
char k[128];
char t_cifrato[128];
char t_originale[128];
int lunghezza_m;
int lunghezza_k;
int scelta;

printf("Inserisci m: ");
get_user_input(m);
lunghezza_m=strlen(m);
printf("La lunghezza di m è %d\n\n", lunghezza_m);

printf("Scegliere tra il percorso:\n");
printf("1) Nel quale l'utente avrà la possibilità di immettere la chiave con cui cifrare il messaggio\n");
printf("2) Nel quale la chiave verrà generata in maniera casuale\n");

scanf("%d", &scelta);
while(getchar()!='\n');
while(scelta==0 || scelta>2){
  printf("Opzione nulla. Scegliere tra 1 o 2 \n");
  scanf("%d", &scelta);
}

switch (scelta) {
  case 1: printf("Inserire k: ");
          get_user_input(k);
          lunghezza_k= strlen(k);
          printf("La lunghezza di k è %d\n\n", lunghezza_k);

          while(lunghezza_k<lunghezza_m){
            printf("Inserire una chiave di lunghezza maggiore o uguale ad m ");
            get_user_input(k);
            lunghezza_k=strlen(k);
          }

          for(int i=0; i<lunghezza_m; i++){
            t_cifrato[i]= m[i] ^ k[i];}

          printf("MESSAGGIO CIFRATO IN ESADECIMALI: ");
          for(int i=0; i<lunghezza_m; i++){
          printf("%x", t_cifrato[i]);
          }

          printf("\n");

          for(int i=0; i<lunghezza_m; i++){
            t_originale[i]= t_cifrato[i] ^ k[i];
            }

          printf("MESSAGGIO ORIGINALE: ");
          printf("%s\n", t_originale);

          break;

case 2: printf("La chiave verrà generata casualmente\n");
          time_t t;
          printf("CHIAVE: ");
          for(int i=0; i<lunghezza_m; i++){
            srand((unsigned) time(&t));
            k[i]= 32+rand()%96;
            printf("%c", k[i]);
          }
          printf("\n");
          lunghezza_k= strlen(k);

          for(int i=0; i<lunghezza_m; i++){
            t_cifrato[i]= m[i] ^ k[i];}

          printf("MESSAGGIO CIFRATO IN ESADECIMALI: ");
          for(int i=0; i<lunghezza_m; i++){
          printf("%x", t_cifrato[i]);
          }

          printf("\n");

          for(int i=0; i<lunghezza_m+1; i++){
            t_originale[i]= t_cifrato[i] ^ k[i];
            }

          printf("MESSAGGIO ORIGINALE: ");
          printf("%s", t_originale);
          printf("\n");
          break;

}//fine switch
return 0;
}

// Funzione che usa l'fgets per l'inserimento da tastiera e risolve tutti i problemi relativi al buffer dello stdin
void get_user_input(char *input) {
    int length;
    *input = '\0';
    do {
        if (fgets(input, 128, stdin) == NULL) {
            break;
        }
        length = strlen(input)-1;
        input[length] = '\0';
    } while (length == 0);
}
