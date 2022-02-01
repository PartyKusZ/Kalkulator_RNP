#include<stdio.h>
#include<stdlib.h>
#include"stos.h"
#include"dzialania.h"
#include<ctype.h>
void dodawanie(t_stos **stos){
    int x;
    int y;
    int z;
    pop(stos,&x); // ściągamy dwie liczby 
    pop(stos,&y);
    z = x + y;    // dodajemy je
    push(stos, &z); // wrzucamy na stos
}
void odejmowanie(t_stos **stos){
    int x;
    int y;
    int z;
    pop(stos,&x);// ściągamy dwie liczby 
    pop(stos,&y);
    z = y - x;   // odejmujemy je 
    push(stos,&z); // wrzucamy na stos
}
void mnozenie(t_stos **stos){
    int x;
    int y;
    int z;
    pop(stos,&x); // ściągamy dwie liczby
    pop(stos,&y);
    z = x * y;    // mnożymy je 
    push(stos, &z);  // wrzucamy na stos 
}
void dzielenie(t_stos **stos){
    int x;
    int y;
    int z;
    pop(stos,&x); // ściągamy dwie liczby
    pop(stos,&y);
    z = y / x;    // dzielimy je 
    push(stos, &z); // wrzucamy na stos 
}
void usun_szczyt(t_stos **stos){
    int x;       
    pop(stos, &x);  //usuwamy szczyt stosu 
}