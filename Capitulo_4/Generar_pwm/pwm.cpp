//============================================================================
// Name        : pwm.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente
// Description : Programa para crear una senal PWM
//============================================================================

#include <iostream>
#include <unistd.h>
#include <cstring>
#include "BlackLib/BlackLib.h" //incluimos la libreria Blacklib

using namespace std;
using namespace BlackLib;             // agregamos el namespace BlackLib

double period;                        //Declaracion de la variable "Period" como una variable gloval

  void pwm(float frec, float dutty_cycle){
	  float x;
	  x=1/frec;                                    //Calculamos el periodo de la señal
	  period= x*(1E9);                             //La convertimos en microsegundos
	  BlackLib::BlackPWM myPwm(BlackLib::P8_19);   // Declaramos el pin "P8_9" como una salida PWM
	  myPwm.setDutyPercent(100.0);                 // Antes de generar la PWM es nesesario declararla con un ciclo de trabajo del 100%
	  myPwm.setPeriodTime(period);                 // Con esta instruccion le indicamos al programa el periodo de la señal en microsegundos
	  myPwm.setDutyPercent(dutty_cycle);           // Retipiendo esta intruccion podemos indicarle al programa el ciclo de trabajo.
     }
//Programa Principal.
int main() {
	//Intrucciones Para que el usuario pueda generara la PWM
	cout <<endl<< "Programa para generar una PWM, antes de iniciar es" << endl;
	cout << "nesesario conectar un osciloscpio en el  pin P8_19" << endl;
	cout << "Ingrese las caracteristicas deseadas."<<endl<<endl;
	loop2: //retorno de programa cuando el usuario decide generar una nueva pwm

	float frec,dutty_cycle;                            //Declaramos variables que por su nombre es facil deducir su funcion.

	cout << "Frecuencia en hz: ";          cin >> frec;
	loop:                                              //Retorno de programa cuando el usuario ingresa un numero no permitido para el ciclio de trabajo
	cout << "Ciclo de trabajo en %: ";     cin >> dutty_cycle;
	cout <<endl<< "PWM generada"<<endl;                //Lanza este texto cuando la señal es generada.

	   if(dutty_cycle>100){                            // Retornamos a donde esta la etiqueta ''Loop'' si escrivimos un numero de ciclo de trabajo no valido
		   cout<<"Ingresen un numero menor de 100."<< endl;
		   goto loop;
	   }

	pwm(frec,dutty_cycle);                            // llamamos a la funcion PWM

	loop4:                                            // El programa retorna hatsa esta etiqueta cuando una letra no es aceptada
	cout<< "Ingrese 'c' para generar una nueva PWM o 'e' para salir: ";
	char com[2];                                      //variable para ingresar una cadena de caracteres de dos variables.
	cin >> com;
	   if(strcmp(com,"c")==0){                        //Si el usuario decide generar una nueva PWM el grograma regresa a la etiqueta loop2
		   goto loop2;
	   }

	   else if(strcmp(com,"e")==0){                   //si decidimos salir del programa nos vamos hasta loop3
		   goto loop3;
	   }
	   else {
		   cout<<endl<<"Letra no Aceptada."<<endl;    //si nos equivocamos de letra aparece este aviso.
		   goto loop4;
	   }

	loop3:                                            // etiqueta que no ayuda a finalizar el programa
    cout <<endl<<"Fin del Programa."<<endl;
	return 0;
}
