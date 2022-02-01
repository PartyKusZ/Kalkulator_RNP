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
void wyczysc_stos(t_stos **stos){
    int x;
    while(*stos != NULL){  // dopóki adres jest różny od 0
        pop(stos,&x);     // usuwamy element
    }
}
void zamien(t_stos **stos){  // ściągamy 2 elementy i wrzycamy w odwrotnej kolejności
    int x;
    int y;
    pop(stos,&x);
    pop(stos,&y);
    push(stos,&x);
    push(stos,&y);
}
void podwoj(t_stos **stos){  // ściągamy element i wrzucamy 2 razy
    int x;
    pop(stos,&x);
    push(stos,&x);
    push(stos,&x);
}
void drukuj_szczyt(t_stos **stos){    
    int x;
    pop(stos,&x);       // ściągamy szczczyt 
    printf("%d\n",x);   // drukujemy go 
    push(stos,&x);      // i odkładamy znów na szczyt 
}
void drukuj(t_stos **stos){
    print(stos);            // drukujemy szczyt
}

