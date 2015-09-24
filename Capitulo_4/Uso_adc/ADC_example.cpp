//============================================================================
// Name        : ADC_example.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente
// Description : Uso del ADC1 con la libreria blackLib
//============================================================================

#include <iostream>
#include "BlackLib/BlackLib.h" //incluimos la libreria blacklib.h

using namespace std;
using namespace BlackLib; //incluimos Blackspace para no repeterlo tantas vecas

//Configuracion de los pines de salida
BlackGPIO LED0(GPIO_44, output, SecureMode);
BlackGPIO LED1(GPIO_45, output, SecureMode);
BlackGPIO LED2(GPIO_23, output, SecureMode);
BlackGPIO LED3(GPIO_26, output, SecureMode);
BlackGPIO LED4(GPIO_46, output, SecureMode);
BlackGPIO LED5(GPIO_47, output, SecureMode);
BlackGPIO LED6(GPIO_27, output, SecureMode);
BlackGPIO LED7(GPIO_65, output, SecureMode);
BlackGPIO LED8(GPIO_22, output, SecureMode);
BlackGPIO LED9(GPIO_49, output, SecureMode);

//Configuuracion del ADC que queremos emplear. En este caso nosotros elejomos el ADC 1
BlackADC myAdc(AIN1);
    int val;

//Función que activa el led 0
void led_0(){
  	  LED0.setValue(high);
  	  LED0.setValue(low);}
//Función que activa el led 1
void led_1(){
  	  LED1.setValue(high);
  	  LED1.setValue(low);
                       }
//Función que activa el led 2
void led_2(){
  	  LED2.setValue(high);
  	  LED2.setValue(low);
}
//Función que activa el led 3
void led_3(){
  	  LED3.setValue(high);
  	  LED3.setValue(low);
}
//Función que activa el led 4
void led_4(){
  	  LED4.setValue(high);
  	  LED4.setValue(low);
}
//Función que activa el led 5
void led_5(){
  	  LED5.setValue(high);
  	  LED5.setValue(low);
  	}
//Función que activa el led 6
void led_6(){

  	  LED6.setValue(high);
  	  LED6.setValue(low);

}
//Función que activa el led 7
void led_7(){
	  LED7.setValue(high);
	  LED7.setValue(low);
}
//Función que activa el led 8
void led_8(){
	  LED8.setValue(high);
	  LED8.setValue(low);
}
//Función que activa el led 9
void led_9(){
	  LED9.setValue(high);
	  LED9.setValue(low);
}

//Programa principal
int main()
{
	cout<<"Elemplo de uso del ADC. Para salir del programa presione ctrl+c"<<endl;

   //Ciclo infinito que supervisa continuamente los niveles de voltaje en ADC1
	   for(;;){
       myAdc >> val;

       if((val>0)&(val<180)) {
              led_0();       }

       if((val>180)&(val<360)) {
              led_1();       }

       if((val>360)&(val<540)) {
              led_2();       }

       if((val>540)&(val<720)) {
              led_3();       }

       if((val>720)&(val<900)) {
              led_4();       }

       if((val>900)&(val<1080)) {
              led_5();       }

       if((val>1080)&(val<1260)) {
              led_6();       }

       if((val>1260)&(val<1440)) {
              led_7();       }

       if((val>1440)&(val<1620)) {
              led_8();       }

       if((val>1620)&(val<1800)) {
              led_9();       }
	          }
	return 0;
}
