//============================================================================
// Name        : Blink_without_blacklib.cpp
// Author      : Alberto Picasso
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<iostream>
#include<fstream>
#include<cstring>
#include<unistd.h>
using namespace std;

//definimos la ubicacion de los archivos que controlan la salida de el pin seleccionado
#define gpio_en "/sys/class/gpio"
#define gpio49 "/sys/class/gpio/gpio49"

//funcion para activar el pin que utlisamos.
void gpioEnable(){
std::fstream fs;
fs.open(gpio_en"/export", std::fstream::out);
fs<<"49";
fs.close();
}
//Funcion para desacitivar el pin que utilisamos
void gpioDisable(){
std::fstream fs;
fs.open(gpio_en"/unexport", std::fstream::out);
fs<<"49";
fs.close();
}
//Funcion para programar nuestro pin como una salida
void gpioOut(){
std::fstream fs;
fs.open(gpio49"/direction", std::fstream::out);
fs<<"out";
fs.close();
}
//Fincion para encender el led
void encender(){
	std::fstream fs;
    gpioOut();
    fs.open(gpio49"/value", std::fstream::out);
    fs<<"1";
    fs.close();
}
//funcio para apagar el led
void apagar(){
	std::fstream fs;
    gpioOut();
    fs.open(gpio49"/value", std::fstream::out);
    fs<<"0";
    fs.close();
}
//funcion para hacer parpadear el led
void flash(){
	std::fstream fs;
    gpioOut();
    int i;
    for(i=0;i<6;i++){//funcion para que parpadee 6 veaces
       fs.open(gpio49"/value", std::fstream::out);
       fs<<"1";
       fs.close();
       usleep(500000);
       fs.open(gpio49"/value", std::fstream::out);
       fs<<"0";
       fs.close();
       usleep(500000);
                   }
}

//Programa principal.
int main(){
     //primero que nada debemos activar el pin de salida llamando a la funcion:
     //"active_gpio"
      gpioEnable();

     //ahora definimos las variables que almacenaran el texto o comandos.
       char com[4];//cadena de tres caracteres(se pone el 4 por el caracter nulo)

       std::fstream fs;//declaramos fs

//Mandamos a la pantalla de la consola cadenas de caracteres con las instrucciones para ejecutar el programa.
  cout<<" "<<endl;
  cout<<"Encender un led Mediante cadenas de caracteres."<<endl;
  cout<<"  "<<endl;
  cout<<"oon : enciende el led."<<endl;
  cout<<"off : apaga el led."<<endl;
  cout<<"fsh : parpadea el led seis veces."<<endl;
  cout<<"ext : salir del programa."<<endl;
loop://parte donde regresa el programa cuando se ejcuta el goto.
     //en lugar de loop podemos usar cualquier otro nombre
  cout<<"  "<<endl;
  cout<<"ingrese el comando: ";
  cin>> com;


  if (strcmp(com,"oon")==0){//esta funcion prende el led
       encender();
       goto loop;
  }
 else if (strcmp(com,"off")==0){ //funcion que apaga el led.
       apagar();
       goto loop;
  }
 else if (strcmp(com,"ext")==0){
    cout<<"Fin del programa."<<endl;
    //este if no cuenta con goto asi que cuando elejimos esta opcion finaliza el programa
  }
 else if(strcmp(com,"fsh")==0){
       flash();
       goto loop;
  }
 else{
    cout<<"Comando no aceptado"<<endl;
    goto loop;
}
    gpioDisable();//Cuando finalisa el programa deja al pin que usamos en su configuacion inicial.
    return 0;
}

