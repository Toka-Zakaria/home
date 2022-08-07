 
#include"SWUART.h"  


void SWUART_init(uint32_t baudrate)
{
  /*configure Rx as input & Tx as output*/
  DIO_init(0, PORTD, IN);
  DIO_init(1, PORTD, OUT);
  
  /* configure baud rate*/
  uint32_t baudPreScaler = (((F_CPU / (baudrate * 8UL))) - 1)
  
  UBRRH = (unsigned char)(baudPreScaler>>8);
  UBRRL = (unsigned char)baudPreScaler;
  
  /* Enable receiver and transmitter */
  UCSRB = (1<<RXEN)|(1<<TXEN);
  
  /* Set frame format: 8data, 2stop bit, even parity */
 UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0) |(1<<UPM1);
  
}

void SWUART_send(uint8_t data)
{
  /* Wait for empty transmit buffer */
while ( !( UCSRA & (1<<UDRE)) );
  
/* Put data into buffer, sends the data */
UDR = data;
}

void SWUART_receive(uint8_t *data)
{
  /* Wait for data to be received */
while ( !(UCSRA & (1<<RXC)) );
  
  *data = UDR; 
}
