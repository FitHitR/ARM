
// Interfacing of ADC with uart using lpc2148

#include<LPC214X.H>
#include<stdio.h>

	void init_uart(void);
	void uart_convert(unsigned char);
	void Tx(unsigned char);
	
	
	unsigned char t1,t2,t3,t4,t5,i;
	
	int main()
	{
		
		VPBDIV = 0x00;            // 30 freaque
		PINSEL0 = 0x00000005;    // P0.0 and P0.1 selete as RXD and TXD           
		IODIR0 = 0x00000000;
	
		AD0CR = 0x0025068;            // AD.7 select
		AD0CR |= 0x01000000;         //24 =1 START bit 
	  init_uart();
		
		while(1)
		{
			uart_convert(AD0DR7 = AD0DR7 & 0x0000ffc0);
			Tx(t4);
			Tx(t5);
		}
	}
	
	void init_uart()
	{
		U0FCR = 0x05;  //this is FIFO ctri..first 5 enable uart, then we select rx & tx pin...
		U0LCR = 0x80;  // this is we select the baud rate 
		U0DLL = 97;   // PCLK (16* baudrate) = 15 MHZ / (16 * 9600)
		U0DLM = 0;    // higher byte = 0 and lower byte = 195;
		U0LSR = 0x03; // LSR is init tha data,stop, parity bits are all; 

	}
	void uart_convert(unsigned char value)
	{
		t1 = value % 10;  // t1 is the lower byte 
		t2 = value / 10;  // t2 is the higher byte 
		
		// t2 = t2<<4;
		// t3 = t1|t2;
		
		t2 = t2 | 0x30;
		t4 = t2;
		t1 = t1 | 0x30;
		t5 = t1;
	}
	
	void Tx(unsigned char set_data)
	{
		while(!(U0LSR & 0x20))
			U0THR = set_data;
	}