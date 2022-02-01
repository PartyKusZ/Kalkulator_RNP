#include <stdio.h>
#include <stdlib.h>
#include"stos.h"

void inicjuj(t_stos **stos){        // funkcja inicjująca pusty stos
    *stos = NULL;
}
int empty(t_stos **stos){           // funkjca sprawdzajaca czy stos jest pysty 
    return(*stos == NULL); 
}
void print(t_stos **stos){          // funkcja drukująca stos
    t_stos *pomocniczy;             // pomocnicza zmienna aby nie zgubić początku stosu 
    pomocniczy = *stos;             // przypisujemy orginalny wksaźniki stosu
    while(pomocniczy != NULL){      // dopuki nie trafimy na koniec stosu
        printf("%d\n", pomocniczy->dana);  // drukujemy wartość 
        pomocniczy = pomocniczy->nast; // przechodzimy do kolejnego węzła
    }
    printf("Koniec stosu\n");
}

void push(t_stos **stos, int *dana){  // funkcja dodawania na stos 
    t_stos *poczatek_stosu;           // tworzymy nowy węzeł 
    poczatek_stosu = (t_stos *)malloc(sizeof(t_stos)); // alukujemy dla niego pamięć
    if(poczatek_stosu == NULL)        // jeśli się nie udało 
        fprintf(stderr, "Blad przydzielenia pamieci\n");  // to o tym mówimy 
    else{                             // a jeśli wszystko jest ok     
    poczatek_stosu->dana = *dana;     // to dodajemy nowy element na początek stosu
    poczatek_stosu->nast = *stos;
    *stos = poczatek_stosu;
    }
}
void pop(t_stos **stos, int *dana){  // funkcja ściągająca ze stosu 
    if(empty(stos))                  // sprawdzamay czy stos jest pusty 
        fprintf(stderr,"Styrta jest pusta\n");
    else{
        t_stos *pomocnicza;          // tworzymy pomocnicza zmienna 
        pomocnicza = *stos;          // przy[isujemy jej początek stosu
        *dana = (*stos)->dana;       // dobieramy warość z początku 
        *stos = (*stos)->nast;       // przechodzimy do następnego elementu(nowego początku)
        free(pomocnicza);            // zwalniamy pamięć
    }    
}




