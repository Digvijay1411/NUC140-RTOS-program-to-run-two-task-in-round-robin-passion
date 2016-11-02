#include <RTL.h>                      /* RTX kernel functions & defines      */
#include "NUC1xx.h"
#include <stdio.h>
#include <stdint.h>
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "LCD_Driver.h"


int k=3, delay=75,delay1=150;
	unsigned char str1[3]="ABC";
unsigned char str2[3]="123";
/* id1, id2 will contain task identifications at run-time */
OS_TID id1, id2;

//Function prototypes
__task void task1 (void);
__task void task2 (void);

/*----------------------------------------------------------------------------
 *   Task 1:  RTX Kernel starts this task with os_sys_init (task1)
 *---------------------------------------------------------------------------*/
__task void task1 (void)  
{
  /* Obtain own system task identification number */
 id1 = os_tsk_create (task1, 1);

  /* Assign system identification numbers of task2 */
  id2 = os_tsk_create (task2, 1);
		
	 
	 Show_Word(k,1,str1[0]);
	 os_dly_wait (delay1);

	
	Show_Word(k,3,str1[1]);
	os_dly_wait (delay1);
	// os_dly_wait (delay);
		          
	
	Show_Word(k,5,str1[2]);
	os_dly_wait(delay1);
	
	//os_tsk_pass();
	
}
 
/*----------------------------------------------------------------------------
 *   Task 2:  RTX Kernel starts this task with os_tsk_create (task2,2)
 *---------------------------------------------------------------------------*/
__task void task2 (void)
{  
							os_dly_wait (delay);
							Show_Word(k,2,str2[0]);
							os_dly_wait (delay);
							//os_tsk_pass();
						
						os_dly_wait (delay);
						Show_Word(k,4,str2[1]);
						os_dly_wait (delay);
						//os_tsk_pass();
			
						os_dly_wait (delay);
						Show_Word(k,6,str2[2]);
						os_dly_wait (delay);
						//os_tsk_pass();
}


/*----------------------------------------------------------------------------
 *        Main: Initialize and start RTX Kernel
 *---------------------------------------------------------------------------*/
int main (void)
{	
	//UNLOCKREG();
	//DrvSYS_Open(48000000); // set to 48MHz
	//LOCKREG(); 

	Initial_panel(); 
	clr_all_panel();
	print_lcd(0, "RR prg for 2 tsk");
	print_lcd(1, "Str1= ABC");
	print_lcd(2, "Str2= 123");
  os_sys_init (task1);
}
