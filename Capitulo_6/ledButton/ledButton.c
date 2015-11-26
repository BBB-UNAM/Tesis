/** Programa que hace parpadear un led hatsa que es presionado un boton
*   Este programa fue tomado y modificado de:
*   https://github.com/derekmolloy/exploringBB/blob/master/chp13/ledButton/ledButton.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <prussdrv.h>
#include <pruss_intc_mapping.h>

#define PRU_NUM	0   // using PRU0 for these examples

int main (void)
{
   if(getuid()!=0){
      printf("Debes correr este programa como usuario root.\n");
      exit(EXIT_FAILURE);
   }
   // Initialize structure used by prussdrv_pruintc_intc
   // PRUSS_INTC_INITDATA is found in pruss_intc_mapping.h
   tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

   // Allocate and initialize memory
   prussdrv_init ();
   prussdrv_open (PRU_EVTOUT_0);

   // Map PRU's interrupts
   prussdrv_pruintc_init(&pruss_intc_initdata);
   
   // Load and execute the PRU program on the PRU
   prussdrv_exec_program (PRU_NUM, "./ledButton.bin");

   // Wait for event completion from PRU, returns the PRU_EVTOUT_0 number
   int n = prussdrv_pru_wait_event (PRU_EVTOUT_0);
   printf("EBB PRU programa finalizado, ejecucion del programa # %d.\n", n);

   // Disable PRU and close memory mappings
   prussdrv_pru_disable(PRU_NUM);
   prussdrv_exit ();
   return EXIT_SUCCESS;
}
