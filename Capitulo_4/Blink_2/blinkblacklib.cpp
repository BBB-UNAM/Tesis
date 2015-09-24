//============================================================================
// Name        : blinkled.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente
// Description : Bink led empleando la libreria Blacklib
//============================================================================

#include <string>
#include <iostream>
#include <unistd.h>
#include "BlackLib/BlackLib.h"//llamamos a la libreria Blacklib

using namespace std;
using namespace BlackLib;

  BlackGPIO LED(GPIO_49, output, SecureMode);//declaramos el pin 49 como una salida de manera global

//función para encender el led
  void encender(){
	LED.setValue(high);
                 }
//funcion para apagar el led
  void apagar(){
	LED.setValue(low);
                }
//función para hacer parpadear el led
  void flash(){
		int i;
		for(i=0;i<6;i++){
	    LED.setValue(high);
		sleep(1);
		LED.setValue(low);
		sleep(1);
		}
               }
//Programa princiapl
int main() {
	cout<< " " << endl;
	cout<<"Programa para encender, apagar y hacer parpadear un led"<<endl<<endl;;
	cout<<"oon: Encender el Led"<<endl;
	cout<<"off: Apagar el Led"<<endl;
	cout<<"fsh: Parpadeo del Led"<<endl;
	cout<<"ext: Salir del programa"<<endl<<endl;
	loop://Aqui es dondé regresa cilicamente el programa hasta que metamos el coamndo exit
	cout<<"Ingrese el comando: ";
    //delcaracion de la variable que almacenará la cadena de caracteres
	char com[4];//cadena de tres caracteres(se pone el cuatro por el caracter nulo)
	cin>>com;
    //condicianales que comparan la intruccion insertada y ejecutan las funciones según la peticion del usuario
	if(strcmp(com,"oon")==0){
		encender();
		goto loop;
	}
	else if (strcmp(com,"off")==0){
		apagar();
		goto loop;
	}
	else if(strcmp(com,"fsh")==0){
		flash();
		goto loop;
	}
	else if(strcmp(com,"ext")==0){
		cout<<endl<<"Fin del Programa"<<endl;//aqui no hay retorno del loop, no lleva a la parte final del programa
	}
	else{
		cout<<endl<<"Comando no aceptado. "<<endl;
		goto loop;
	}
	return 0;
}
