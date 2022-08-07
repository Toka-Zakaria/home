#include"SWUART.h"
#include"Timer0.h"
#include"platform.h"
#define DATA       (uint8_t)10


#define  MC_READY   0x11 /*to mak sure it will send & receive correctly*/

int main(void)
{
uint8_t check = 0;
  
  /*Initialization*/
  SWUART_init(9600);
  
  
  /*Application*/
  /*Cyclic Executive*/
  while(1)
  {
    
    while ( check != MC_READY ) 
    {
      SWUART_receive(&check) ;
    };
    SWUART_send(DATA);
    
  }
    
  return 0;
}
