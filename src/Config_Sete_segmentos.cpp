/************************************************************************************************************

                                      configurações Mega ADK
************************************************************************************************************/

                                   /* Arquivos de Bibliotecas */


 // ========================================================================================================
// --- Bibliotecas Auxiliares --- //
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Wire.h"

#include "Config_Sete_segmentos.h"
#include "Config_mcu.h"


// --- Mapeamento de Hardware ---
#define disp1    6                            //Display mais significativo no digital 9
#define disp2    7                            //Display menos significativo no digital 10
#define disp3    8
#define disp4    9

#define mais    13                            //Botão para incremento no digital 11
#define menos   13          


// --- Variáveis Globais ---
int mil,
    cen,
    dez,                                     //Armazena o valor da dezena
    uni,                                     //Armazena o valor da unidade
    counter_sete = 50;                       //Variável para contagem
    
boolean flagMais, 
        flagMenos;


void config_sete_segmentos(){

 


   for(char i= 22; i< 29; i++)    pinMode(i,       OUTPUT); //Saídas (barramento do display no PORTD)
   for(char j= 6;  j< 8; j++)     pinMode(j,       OUTPUT); //Saídas (controle do display)
   for(char k= 13; k< 13; k++)    pinMode(k, INPUT_PULLUP); //Entrada botões
   
   digitalWrite(disp1, HIGH);
   digitalWrite(disp2, HIGH);
   digitalWrite(disp3, LOW);
   digitalWrite(disp4, LOW); 


   flagMais  = 0x00; 
   flagMenos = 0x00;
}


// --- Desenvolvimento das Funções Auxiliares ---
int display7seg(int number)
{
  int catodo;                                  //Variável que receberá o número indexado ao vetor
  
  //Declaração e inicialização do vetor segmento
  int segmento[10] = {0x3f,                    //Dado referente ao BCD '0'
                      0x06,                    //Dado referente ao BCD '1'
                      0x5b,                    //Dado referente ao BCD '2'
                      0x4f,                    //Dado referente ao BCD '3'
                      0x66,                    //Dado referente ao BCD '4'
                      0x6d,                    //Dado referente ao BCD '5'
                      0x7d,                    //Dado referente ao BCD '6'
                      0x07,                    //Dado referente ao BCD '7'
                      0x7f,                    //Dado referente ao BCD '8'
                      0x67};                   //Dado referente ao BCD '9'
  
  catodo = segmento[number];  
  
  return(catodo);

} //end display7seg


void multiplex(int value)
{ 
  
   mil = value/10;
   PORTA = display7seg(mil);
   digitalWrite(disp4, LOW);
   delay(1);
   digitalWrite(disp4, HIGH);

   cen = value%10;
   PORTA = display7seg(cen);
   digitalWrite(disp3, LOW);
   delay(1);
   digitalWrite(disp3, HIGH);

   dez = value%10;
   PORTA = display7seg(dez);
   digitalWrite(disp2, LOW);
   delay(1);
   digitalWrite(disp2, HIGH);
   
   uni = value%10;
   PORTA = display7seg(uni);
   digitalWrite(disp1, LOW);
   delay(1);
   digitalWrite(disp1,HIGH);

} //end multiplex


void changeCounter()
{

   
   if(!digitalRead( mais)) flagMais  = 0x01;
   if(!digitalRead(menos)) flagMenos = 0x01;
   
   if(digitalRead(mais) && flagMais)
   {
      flagMais = 0x00;
      counter_sete++;
      
      if(counter_sete == 100) counter_sete = 0x00;
   }
   
   if(digitalRead(menos) && flagMenos)
   {
      flagMenos = 0x00;
      counter_sete--;
      
      if(counter_sete == 0) counter_sete = 100;
   }


} //end changeCounter
