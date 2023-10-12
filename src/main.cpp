/*******************************************************************************
   Título:      TCC  Engenharia Mecatrônica.

   Descrição:   C L P   ---  I H M

   Processador: ARDUINO MEGA ADK +  ROBOCORE ESP32 
   
   Geração Multifolhas


   Desenvolvido: MRPRO Tecnologia e Automação

   Autor: Tecnologo. Marcelo Rodrigues     Crea-SP 5070505617

   Data de Inicio: 02/09/2023       Versão:   2023.1.0

        

 
*******************************************************************************/  
/* ============================================================================  
                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\___________________________________
                                                                             
============================================================================== */

/******************************************************************************/
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "Wire.h"
#include "avr/io.h"
#include "avr/interrupt.h"



#include "Config_mcu.h"
#include "Config_Sete_segmentos.h"

int extern counter_sete;

void setup() {
   
             Config_mcu();
  config_sete_segmentos();

}

void loop() {


         Comunicacao_Oled();
              comunicacao();
            changeCounter();
    multiplex(counter_sete); 
        Supervisionamento(); 
   
}

