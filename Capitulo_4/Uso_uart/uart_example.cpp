//============================================================================
// Name        : uart_example.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente
// Description : Ejemplo de uso de la interfas UART4
//============================================================================

#include <iostream>
#include <unistd.h>
#include "BlackLib/BlackLib.h"

using namespace BlackLib; //parametro usado para no llamar tantas veces la palabara: Blacklib
using namespace std; //parametro usado para no llamar tantas veces la palabara: std

//configuracion basica del la uart y del pin que utilisamos como salida para el led
	  BlackUART  myUart(UART4, Baud9600, ParityNo, StopOne, Char8 );
	  BlackGPIO  LED(GPIO_44, output, SecureMode);

//funciones que realizan las acciones del led.
 void oon(){
	LED.setValue(high);
          }
 void off(){
	LED.setValue(low);
           }
 void flash(){
	int i;
		for(i=0;i<10;i++){
			LED.setValue(high);//Ponels el ledn en alto
			usleep(400000);
			LED.setValue(low);//ponemos el led en bajo
			usleep(400000);
                         }
              }

int main() {
cout<<"Ejemplo de uso del bluetooth HC05"<<endl;

//configuracion del puerto uart
	  myUart.open( ReadWrite | NonBlock );
	  myUart.flush( bothDirection );

//Variables que guardan cadenas de caracteres que contienen las intrucciones de uso del programa.
	  string outuart1 = "Programa para encender, apagar y hacer parpadear un led\n \n";
	  string outuart2 = "Opciones: \n\nencender - enciende el Led \napagar -apaga el Led \nflash - Parpadea el led \n ";
	  string outuart3 = "\nEl programa esta a la espera de una opcion. \n";
//con las siguientes instrcciones enviamos las variables anteriores a la uart
	  myUart << outuart1;
	  myUart << outuart2;
	  myUart << outuart3;

	  loop: //cada que se termina de ejecutar una tarea el programa regresa a esta linea

	  usleep(27000); //retardo de uS que nos permite leer los paqutes de datos recibidos son ayuda de señales de
                     //sincronisacion
	  string inuart; //Variable que nos ayudara a comparar los datos recividos para  ejecutar las acciones del led
	  myUart >> inuart;

	  //enciende el led
	  if(inuart=="encender"){
		  string outuart4 = "\nLed Encendido";
		  myUart << outuart4;
		  oon();
		  goto loop;
	  }
      //apaga el led
	  else if(inuart=="apagar"){
		  string outuart5 = "\nLed Apagado";
		  myUart << outuart5;
		  off();
		  goto loop;
	  }
	  //parpadea el led
	  else if(inuart=="flash"){
		  string outuart6 = "\nLed Parpadeando";
		  myUart << outuart6;
		  flash();
		  goto loop;
	  }

	  /*Esto se puso ya que cuando no enviamos ningun paquete de datos via bluetooth nos llega un paquete de datos
	    con la cadena de caracteres "UartReadError"*/
	  else if(inuart=="UartReadError"){
		  goto loop;
	  }
	  //termina de ejecutar el programa al recivir la cadena de caracteres "salir"
	  else if(inuart=="salir"){
		  string outuart7 = "\nFin del Programa";
		  myUart << outuart7;
		  goto exit;
	  }
	  //Nos manda un aviso si enviamos una cadena de caracteres no valida para ejecutar una accion.
	  else {
		  string outuart8 = "\nCadena de caracteres no Aceptada";
		  myUart << outuart8;
		  goto loop;
	       }

    exit: // etiqueta para terminar de ejecutar el programa.
    return 0;
}
