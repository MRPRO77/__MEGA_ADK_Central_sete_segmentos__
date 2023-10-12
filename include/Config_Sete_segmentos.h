
/********************************Função que configura Pinos do MCU**************************************

                                   configuração para placa Mega ADK

********************************************************************************************************/
/*******************************************************************************************************/
                                      /* Arquivos de inclusão */

#ifndef Config_Sete_segmentos_h_
#define Config_Sete_segmentos_h_
               

// ======================================================================================================
// --- Protótipo das Funções ---

// --- Protótipo das Funções Auxiliares ---
int display7seg(int number);                 //Retorna o dado para o barramento do display
void multiplex(int value);                   //Faz a multiplexação do display
void changeCounter();                        //Modifica o valor do contador através dos botões
void config_sete_segmentos();

#endif