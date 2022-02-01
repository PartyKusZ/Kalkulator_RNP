/* Jakub Kusz 
   Wrocław, 20.01.2021  
   Kalkulator RPN
   Kompilacja diablo: cc -xc99 -Xc main.c stos.c dzialania.c
   Kompliacja Panamint: gcc -std=c99 -pedantic -Wall main.c stos.c dzialania.c */
#include<stdio.h>
#include"stos.h"
#include <stdlib.h>
#include"dzialania.h"
#include<ctype.h>
#define MAX 100
int main(){
  t_stos *stos;
  int dana;
  char dane [MAX] = " ";
  inicjuj(&stos);  // tworzymy stos 
  while(dane[0] != 'q'){
     scanf("%s",dane);
    
     switch(dane[0]){   // switch case - steruje wywoływaniem odpowiednich funkcji 
     
        case '+':
            dodawanie(&stos);
        break;

       case '-':
         dana=atoi(dane);
          if(dana==0)        // jeśli znak jest minusem to wykonujemy odejmowanie 
            odejmowanie(&stos);
          else               // a jeśli nie to to wrzucamy na stos 
            push(&stos,&dana);
        break;

        case '*':
            mnozenie(&stos);
        break;

        case '/':
            dzielenie(&stos);
        break; 

        case 'P':
            usun_szczyt(&stos);
        break;

        case 'c':
            wyczysc_stos(&stos);
        break;

        case 'r':
            zamien(&stos);
        break;

        case 'd':
            podwoj(&stos);      
        break;

        case 'p':
            drukuj_szczyt(&stos);
        break;

        case 'f':
            drukuj(&stos);
        break;

       

        default: 
        dana = atoi(dane); // wrzucamy na stos jesli jest liczbą
        push(&stos,&dana);
        break;
    
    }
  }
 exit(EXIT_SUCCESS);
 }
/****************************************************************************************************************/
/*                                                                                                              */
/*                                        SPRAWOZDANIE                                                          */ 
/*                                                                                                              */ 
/*      1.Testy                                                                                                 */ 
/*        Przyjęta przezemnie metodologia testowania programu wyglądała  w następujący sposób:                  */
/*          - wprowadzenie danych wartości liczbowych do kalkulatora i wykonanie na nich działań matematycznych */
/*          - odcena rezultatów.                                                                                */
/*        Wybrane przezemnie dane: 12 -15 9                                                                     */
/*          1.1 Dodawanie:                                                                                      */
/*              Wprowadzone dane: 12 -15 9 + +                                                                  */
/*              Wynik: 6, poprawny                                                                              */
/*          1.2 Odejmowanie:                                                                                    */
/*              Wprowadzone dane: 12 -15 9 - -                                                                  */
/*              Wynik: 12, poprawny                                                                             */
/*          1.3 Mnożenie:                                                                                       */
/*              Wprowadzone dane: 12 -15 9 * *                                                                  */
/*              Wynik: -1620, poprawny                                                                          */
/*          1.4 Dzielenie:                                                                                      */
/*              Wprowadzone dane: 12 -15 9 / /                                                                  */
/*              Wynik: -12, niepoprawny - należy pamiętać, że kalkulator operuje w swej pamięci na liczbach     */
/*              całkowitych, więc dzielenia niecałkowite mogą powodować błędne wyniki                           */
/*          1.5 P: prawdiłowo usuwa szczyt stosu                                                                */
/*          1.6 c: prawidłowo usuwa wszystkie elementy stosu                                                    */
/*          1.7 r: prawidłowo zamienia kolejność dwóch pierwszych liczb na stosie                               */ 
/*          1.8 d: prawidłowo duplikuje szczyt stosu                                                            */
/*          1.9 p: prawidłowo drukuje szczyt stosu                                                              */
/*          1.10 f: prawidłowo drukuje cały stos                                                                */
/*          1.11 Wprowadzanie innych znaków niż liczby i rozumiane przez kalkulator:                            */
/*               Niestety kalkulator błędnie interpretuje znaki inne niż "dozwolone" i interpretuje je jako 0   */
/*      2. Wnioski                                                                                              */
/*         Kalkulator poprawnie realizuje działania na liczbach (pojawiają się problemy przy dzieleniu niecałko-*/
/*           witym), poprawnie realizuje pozostałe operacje na stosie, interpretuje inne znaki niż dozwolone    */
/*           jako 0. Należało by go wyposażyć w zabezpieczenie przed podawaniem na wejście innych wartości.     */
/*                                                                                                              */
/****************************************************************************************************************/
