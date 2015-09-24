//============================================================================
// Name        : Ledsplaca.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Modificado de : http://derekmolloy.ie/beaglebone-controlling-the-on-board-leds
//               para poder manipular todos los leds
// Description : Manipular los leds de la placa beaglebone
//============================================================================

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//Definimos la ubucacion de los archivos que controlan los leds.

#define LED0_PATH_0 "/sys/class/leds/beaglebone:green:usr0"
#define LED0_PATH_1 "/sys/class/leds/beaglebone:green:usr1"
#define LED0_PATH_2 "/sys/class/leds/beaglebone:green:usr2"
#define LED0_PATH_3 "/sys/class/leds/beaglebone:green:usr3"

void removeTrigger(){
   // Desactivamos la tarea que por defecto le asigna el beaglebone y los declaramos como una salida
   std::fstream fs;
   fs.open( LED0_PATH_0 "/trigger", std::fstream::out);
   fs.open( LED0_PATH_1 "/trigger", std::fstream::out);
   fs.open( LED0_PATH_2 "/trigger", std::fstream::out);
   fs.open( LED0_PATH_3 "/trigger", std::fstream::out);
   fs << "none";
   fs.close();
}

//Programa principal
int main(int argc, char* argv[]){
	//nos envia este mensaje cuando solo ejecutamos el programa sin nuestros comandos creados.
   if(argc!=2){
 cout << "    "  << endl;
 cout << "    "  << endl;
 cout << "    "  << endl;
 cout << "Usar este programa con los siguientes comandos: on,off,flash,all, trigger"  << endl;
 cout << "Escribimos en la consola lo siguiente: ./leds (nombre del led) (on,off,flash)"  << endl;
 cout << "Tambien podemos escribir en la consola lo siguiente: ./ledBBB all trigger (parpadearan todos los leds)"  << endl;

 cout << "Ejemplo 1: ./ledBBB led0 on" << endl;
 cout << "Ejemplo 2: ./ledBBB led2 flash" << endl;

   }

   string cmd1(argv[1]);
  // std::fstream fs;
   string cmd2(argv[2]);
   std::fstream fs;

   //encender led 0
   if((cmd1=="led0") & (cmd2=="on")){
 removeTrigger();
 fs.open (LED0_PATH_0 "/brightness", std::fstream::out);
 fs << "1";
 fs.close();
   }
//encender led 1
   else if((cmd1=="led1") & (cmd2=="on")){
 removeTrigger();
 fs.open (LED0_PATH_1 "/brightness", std::fstream::out);
 fs << "1";
 fs.close();
   }
//encender led 2
  else if((cmd1=="led2") & (cmd2=="on")){
 removeTrigger();
 fs.open (LED0_PATH_2 "/brightness", std::fstream::out);
 fs << "1";
 fs.close();
   }
//encender led 3
   if((cmd1=="led3") & (cmd2=="on")){
 removeTrigger();
 fs.open (LED0_PATH_3 "/brightness", std::fstream::out);
 fs << "1";
 fs.close();
   }
//APAGAR LEDS
//apagar led 1
   else if ((cmd1=="led0") & (cmd2=="off")){
 removeTrigger();
 fs.open (LED0_PATH_0 "/brightness", std::fstream::out);
 fs << "0";
 fs.close();
   }
//apagar led 2
   else if ((cmd1=="led1") & (cmd2=="off")){
 removeTrigger();
 fs.open (LED0_PATH_1 "/brightness", std::fstream::out);
 fs << "0";
 fs.close();
   }
//apagar led 3
   else if ((cmd1=="led2") & (cmd2=="off")){
 removeTrigger();
 fs.open (LED0_PATH_2 "/brightness", std::fstream::out);
 fs << "0";
 fs.close();
   }
//apagar led 4
   else if ((cmd1=="led3") & (cmd2=="off")){
 removeTrigger();
 fs.open (LED0_PATH_3 "/brightness", std::fstream::out);
 fs << "0";
 fs.close();
   }
//FLASH DE LOS LEDS
//flash led 1
   else if ((cmd1=="led0") & (cmd2=="flash")){
 fs.open (LED0_PATH_0 "/trigger", std::fstream::out);
 fs << "timer";
 fs.close();
 fs.open (LED0_PATH_0 "/delay_on", std::fstream::out);
 fs << "50";
 fs.close();
 fs.open (LED0_PATH_0 "/delay_off", std::fstream::out);
 fs << "50";
 fs.close();
   }
//flash led 2
   else if ((cmd1=="led1") & (cmd2=="flash")){
 fs.open (LED0_PATH_1 "/trigger", std::fstream::out);
 fs << "timer";
 fs.close();
 fs.open (LED0_PATH_1 "/delay_on", std::fstream::out);
 fs << "50";
 fs.close();
 fs.open (LED0_PATH_1 "/delay_off", std::fstream::out);
 fs << "50";
 fs.close();
   }
//Flash led 3
   else if ((cmd1=="led2") & (cmd2=="flash")){
 fs.open (LED0_PATH_2 "/trigger", std::fstream::out);
 fs << "timer";
 fs.close();
 fs.open (LED0_PATH_2 "/delay_on", std::fstream::out);
 fs << "50";
 fs.close();
 fs.open (LED0_PATH_2 "/delay_off", std::fstream::out);
 fs << "50";
 fs.close();
   }
//Flash led 4
   else if ((cmd1=="led3") & (cmd2=="flash")){
 fs.open (LED0_PATH_3 "/trigger", std::fstream::out);
 fs << "timer";
 fs.close();
 fs.open (LED0_PATH_3 "/delay_on", std::fstream::out);
 fs << "50";
 fs.close();
 fs.open (LED0_PATH_3 "/delay_off", std::fstream::out);
 fs << "50";
 fs.close();
   }
//flash todos los leds
else if ((cmd1=="all") & (cmd2=="trigger")){

 // display the current trigger details
 fs.open (LED0_PATH_0 "/trigger", std::fstream::out);
 fs << "heartbeat";
 fs.close();

 fs.open (LED0_PATH_1 "/trigger", std::fstream::out);
 fs << "heartbeat";
 fs.close();

 fs.open (LED0_PATH_2 "/trigger", std::fstream::out);
 fs << "heartbeat";
 fs.close();

 fs.open (LED0_PATH_3 "/trigger", std::fstream::out);
 fs << "heartbeat";
 fs.close();

 string line;
 while(getline(fs,line)) cout << line;
 fs.close();
   }
   else{
//si hay un comando no existente
 cout << "Invalid command" << endl;
   }
//cuando termina nuestra peticion y finaliza la ejecucion del programa.
   cout << "Finished the LED flash program" << endl;
   return 0;
}
