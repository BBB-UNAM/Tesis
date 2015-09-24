//============================================================================
// Name        : PWM_modulation.cpp.
// Author      : Alberto Picasso.
// Version     : 1.0
// Copyright   : Este programa puede ser usado y distribuido libremente.
// Description : Modulacion de una señal PWM.
//============================================================================

#include <iostream>
#include <unistd.h>
#include "BlackLib/BlackLib.h"
using namespace std;
using namespace BlackLib;

float period; //variables globales

void pwm(float frec){
	float x,per_time;
	x= 1/frec;
	period=x*(1E9);

	for(int i=1;i<101;i++){

     	  per_time=i*period/100;

	      BlackPWM  myPwm(BlackLib::P8_19);
	      myPwm.setDutyPercent(100.0);
	      myPwm.setPeriodTime(period);

	      myPwm.setSpaceRatioTime(per_time, nanosecond);
	      usleep(200);
	                       }
	for(int i=100;i>0;i--){
		  per_time=i*period/100;
	      BlackPWM  myPwm(BlackLib::P8_19);
	      myPwm.setDutyPercent(100.0);
	      myPwm.setPeriodTime(period);

	      myPwm.setSpaceRatioTime(per_time, nanosecond);
	      usleep(200);
	}

}

void instrucciones(){
	cout<<endl<<"Con este programa podremos observar la modulacion de la PWM en un osciloscopio"<<endl;
	cout<<"Ingrese la frecuencia deseada para nuestra señal pwm: ";
}
int main() {
    instrucciones();
    BlackGPIO  button(GPIO_46, input, SecureMode);
    float frec;
    cin >> frec;


    for(;;){
    pwm(frec);
    }
	return 0;
}
