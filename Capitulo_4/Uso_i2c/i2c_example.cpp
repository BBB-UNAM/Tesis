//============================================================================
// Name        : i2c_example.cpp
// Author      : Alberto Picasso
// Version     : 1.0
// Copyright   : Este Programa Puede ser usado y distribuido libremente
// Description : Ejemplo del uso de la intefaz I2C con el display 1602A
//============================================================================

#include <iostream>
#include <unistd.h>
#include "BlackLib/BlackLib.h"//Declaramos la libreria Balcklib

using namespace std;
using namespace BlackLib;

BlackLib::BlackI2C  myI2c(I2C_1, 0x27);  //Declaramos la configuracion del Dispositivo I2C de manera Global

//funcion que se encarga de la configuración del display
void lcd_config(){
	myI2c.open( ReadWrite | NonBlock );

	int time=10000;

	uint8_t dato38 = 0x38;        uint8_t dato08 = 0x08;
	uint8_t dato3c = 0x3c;        uint8_t dato0c = 0x0c;
	uint8_t dato28 = 0x28;        uint8_t datof8 = 0xf8;
	uint8_t dato2c = 0x2c;        uint8_t datofc = 0xfc;
	uint8_t dato18 = 0x18;        uint8_t dato00 = 0x00;
	uint8_t dato1c = 0x1c;        uint8_t datoff = 0xff;

	myI2c.writeByte(dato00,datoff);     usleep(time);
	myI2c.writeByte(dato00,dato38);     usleep(time);
	myI2c.writeByte(dato00,dato3c);     usleep(time);
	myI2c.writeByte(dato00,dato38);     usleep(time);
	myI2c.writeByte(dato00,dato3c);     usleep(time);
	myI2c.writeByte(dato00,dato38);     usleep(time);
	myI2c.writeByte(dato00,dato3c);     usleep(time);
	myI2c.writeByte(dato00,dato38);     usleep(time);
	myI2c.writeByte(dato00,dato28);     usleep(time);
	myI2c.writeByte(dato00,dato2c);     usleep(time);
	myI2c.writeByte(dato00,dato28);     usleep(time);
	myI2c.writeByte(dato00,dato2c);     usleep(time);
	myI2c.writeByte(dato00,dato28);     usleep(time);
	myI2c.writeByte(dato00,dato18);     usleep(time);
	myI2c.writeByte(dato00,dato1c);     usleep(time);
	myI2c.writeByte(dato00,dato18);     usleep(time);
	myI2c.writeByte(dato00,dato08);     usleep(time);
	myI2c.writeByte(dato00,dato0c);     usleep(time);
	myI2c.writeByte(dato00,dato08);     usleep(time);
	myI2c.writeByte(dato00,datof8);     usleep(time);
	myI2c.writeByte(dato00,datofc);     usleep(time);
	myI2c.writeByte(dato00,datof8);     usleep(time);
}
//Funcuin encaragada de imprimir la letra "h"
void word_h(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t h1 = 0x4d;       uint8_t h3 = 0x8d;  uint8_t h0 = 0x00;
    uint8_t h2 = 0x49;       uint8_t h4 = 0x89;

    int time=25000;
    myI2c.writeByte(h0,h1);     usleep(time);
    myI2c.writeByte(h0,h2);     usleep(time);
    myI2c.writeByte(h0,h3);     usleep(time);
    myI2c.writeByte(h0,h4);     usleep(time);
}
//Función encargada de imprimir la letra "o"
void word_o(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t o1 = 0x4d;       uint8_t o3 = 0xfd;  uint8_t o0 = 0x00;
    uint8_t o2 = 0x49;       uint8_t o4 = 0xf9;

    int time=25000;
    myI2c.writeByte(o0,o1);     usleep(time);
    myI2c.writeByte(o0,o2);     usleep(time);
    myI2c.writeByte(o0,o3);     usleep(time);
    myI2c.writeByte(o0,o4);     usleep(time);

}
//Función encargada de imprimir la letra "l"
void word_l(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t l1 = 0x4d;       uint8_t l3 = 0xcd;  uint8_t l0 = 0x00;
    uint8_t l2 = 0x49;       uint8_t l4 = 0xc9;

    int time=25000;
    myI2c.writeByte(l0,l1);     usleep(time);
    myI2c.writeByte(l0,l2);     usleep(time);
    myI2c.writeByte(l0,l3);     usleep(time);
    myI2c.writeByte(l0,l4);     usleep(time);
}
//Función encargada de imprimir la letra "a"
void word_a(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t a1 = 0x4d;       uint8_t a3 = 0x1d;  uint8_t a0 = 0x00;
    uint8_t a2 = 0x49;       uint8_t a4 = 0x19;

    int time=25000;
    myI2c.writeByte(a0,a1);     usleep(time);
    myI2c.writeByte(a0,a2);     usleep(time);
    myI2c.writeByte(a0,a3);     usleep(time);
    myI2c.writeByte(a0,a4);     usleep(time);
}
//Función encargada de imprimir el caracter "-"
void word_(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t e1 = 0x2d;       uint8_t e3 = 0xdd;  uint8_t e0 = 0x00;
    uint8_t e2 = 0x29;       uint8_t e4 = 0xd9;

    int time=25000;
    myI2c.writeByte(e0,e1);     usleep(time);
    myI2c.writeByte(e0,e2);     usleep(time);
    myI2c.writeByte(e0,e3);     usleep(time);
    myI2c.writeByte(e0,e4);     usleep(time);
}
//Función encargada de imprimir la letra "u"
void word_u(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t u1 = 0x5d;       uint8_t u3 = 0x5d;  uint8_t u0 = 0x00;
    uint8_t u2 = 0x59;       uint8_t u4 = 0x59;

    int time=25000;
    myI2c.writeByte(u0,u1);     usleep(time);
    myI2c.writeByte(u0,u2);     usleep(time);
    myI2c.writeByte(u0,u3);     usleep(time);
    myI2c.writeByte(u0,u4);     usleep(time);
}
//Función encargada de imprimir la letra "n"
void word_n(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t n1 = 0x4d;       uint8_t n3 = 0xed;  uint8_t n0 = 0x00;
    uint8_t n2 = 0x49;       uint8_t n4 = 0xe9;

    int time=25000;
    myI2c.writeByte(n0,n1);     usleep(time);
    myI2c.writeByte(n0,n2);     usleep(time);
    myI2c.writeByte(n0,n3);     usleep(time);
    myI2c.writeByte(n0,n4);     usleep(time);
}
//Función encargada de imprimir la letra "m"
void word_m(){
	myI2c.open( ReadWrite | NonBlock );

	uint8_t m1 = 0x4d;       uint8_t m3 = 0xdd;  uint8_t m0 = 0x00;
    uint8_t m2 = 0x49;       uint8_t m4 = 0xd9;

    int time=25000;
    myI2c.writeByte(m0,m1);     usleep(time);
    myI2c.writeByte(m0,m2);     usleep(time);
    myI2c.writeByte(m0,m3);     usleep(time);
    myI2c.writeByte(m0,m4);     usleep(time);
}

//Programa Principal
int main() {
	int time2=250000; //variable que usamos para generar un retraso en el tiempo de ejecucion de cada funcion.
	cout << "Programa de mustra de la interfas I2C con el Display 1602A" << endl;
	lcd_config();
	usleep(time2);
	word_h();
	usleep(time2);
	word_o();
	usleep(time2);
	word_l();
	usleep(time2);
	word_a();
	usleep(time2);
	word_();
	usleep(time2);
	word_u();
	usleep(time2);
	word_n();
	usleep(time2);
	word_a();
	usleep(time2);
	word_m();
	return 0;
}
