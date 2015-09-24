//============================================================================
// Name        : LedButton.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente
// Description : Blink Led con push button.
//============================================================================

#include <iostream>
#include <unistd.h>
#include <unistd.h>
#include "BlackLib/BlackLib.h"//Declaramos la libreria Balcklib

using namespace std;
using namespace BlackLib;

//Funcion para hacer parpadear el led
void flash(){
	BlackGPIO  LED(GPIO_44, output, SecureMode);//declaramos el Gpio 44 como una salida
	int i;
	for(i=0;i<10;i++){
		LED.setValue(high);//Ponels el ledn en alto
		usleep(400000);
		LED.setValue(low);//ponemos el led en bajo
		usleep(400000);
	}
}
//Programa primcipal
int main() {
	//Instrucciones
	cout<<"  "<<endl<<endl;
	cout<<"Blink Led con push button " << endl; // prints !!!Hello World!!!
	cout<<"El programa esta a la espera de una accion"<<endl;
	cout<<"Puede parpadear el led o salir del programa dependiendo del boton oprimido."<<endl<<endl;

    //Declarmos los dis pines que utilizaremos como entradas
	//uno es para prender el led y el otro es para terminar el programa
	BlackGPIO  myGpio1(GPIO_26, input, SecureMode);
	BlackGPIO  myGpio2(GPIO_46, input, SecureMode);

	     for(;;){//ciclio infinito (hay muchas formas de crear ciclos infinitos)
	    	     //similar a void loop de los ardino pero este ciclo si es posble detenerlo

	     if( myGpio1.isHigh() )//si hay una alto en nuestro pin llama a la funcion para hacer
	         {                 //parpadear el led
	            std::cout << "Led Parpadeando" << std::endl;
                flash();//llamado de la funcion flash
	         }

	      if(myGpio2.isHigh()){
		        goto stop;//si detecta un alto nos saca del ciclo, justo a donde esta la etiqueta "stop"
	         }

                }

  stop:
  cout<<"Fin del Programa"<<endl<<endl;//Envia este letrero a la terminal cuando salimos del Programa.
  return 0;
}
