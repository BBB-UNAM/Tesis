/* Programa que controla el sensor HC-SR04 a traves de PRU0
*  Este codigo fue modificado de:
*  https://github.com/derekmolloy/exploringBB/blob/master/chp13/ultrasonic/ultrasonic.c
*/
#include <stdio.h>
#include <stdlib.h>
#include <prussdrv.h>
#include <pruss_intc_mapping.h>
#include <pthread.h>
#include <unistd.h>

#define PRU_NUM 0

static void *pru0DataMemory;
static unsigned int *pru0DataMemory_int;

void *threadFunction(void *value){
   do {
      int notimes = prussdrv_pru_wait_event (PRU_EVTOUT_1);
      unsigned int raw_distance = *(pru0DataMemory_int+2);
      float distcm = ((float)raw_distance / (100 * 58));
      printf("Objeto encontrado a %f cm)             \r", distcm);
      prussdrv_pru_clear_event (PRU_EVTOUT_1, PRU0_ARM_INTERRUPT);
   } while (1);
}

int  main (void)
{
   if(getuid()!=0){
      printf("Debes correr este programa como usuario root.\n");
      exit(EXIT_FAILURE);
   }
   pthread_t thread;
   tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

   // Allocate and initialize memory
   prussdrv_init ();
   prussdrv_open (PRU_EVTOUT_0);
   prussdrv_open (PRU_EVTOUT_1);

   // Map PRU's INTC
   prussdrv_pruintc_init(&pruss_intc_initdata);

   // Copy data to PRU memory - different way
   prussdrv_map_prumem(PRUSS0_PRU0_DATARAM, &pru0DataMemory);
   pru0DataMemory_int = (unsigned int *) pru0DataMemory;
   // Use the first 4 bytes for the number of samples
   *pru0DataMemory_int = 500;
   // Use the second 4 bytes for the sample delay in ms
   *(pru0DataMemory_int+1) = 100;   // 2 milli seconds between samples

   // Load and execute binary on PRU
   printf("   \n");
   printf("Programa que mide la distancia a la que se encuentra un objeto. \n");
   printf(" \n");
   prussdrv_exec_program (PRU_NUM, "./ultrasonic.bin");
   if(pthread_create(&thread, NULL, &threadFunction, NULL)){
       printf("Fallo la creacion de thread!");
   }
   int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
   printf("Programa de deteccion de distancias finalizado, ejecucion numero: %d.\n", n);
   printf("Los detalles de la ejecucion del programa se muestran a continuacion: \n");
   printf(" \n");
   printf("- El numero de muestras tomadas fue: %d.\n", *pru0DataMemory_int);
   printf("- El tiempo de retardo es de %d ", *(pru0DataMemory_int+1));
   printf(" milisegundos \n");
 
   // distance in inches = time (ms) / 148 according to datasheet
   unsigned int raw_distance = *(pru0DataMemory_int+2);
   float distcm = ((float)raw_distance / (100 * 58));
   printf("- La ultima lectura de distancia tomada es de %f cm.\n", distcm);
   printf("   \n");

   /* Disable PRU and close memory mappings */
   prussdrv_pru_disable(PRU_NUM);
   prussdrv_exit ();
   return EXIT_SUCCESS;
}
