// RTC program for LPC2148
#include<LPC214X.H>
	
	void tx(void);
	void rx(void);
	void RW_RTC(void);
	
	unsigned char ch,i,j,k;
	unsigned char arr[] = {'R','A','N','J','E','E','T'};
	
	int main()
	{
		PINSEL0 = 0x00000005;   // TDX and RDX for UART 0101
		VPBDIV = 0x00;          // frequency 15
		IO0DIR = 0Xffffffff;   //0ut put
		
		U0LCR = 0x83;          // DLAB = 1 AND length 100000011
		U0DLM = 0x00;          
		U0DLL = 0x62;     // PCLK = 15; U0DLL value is 62 by using baudrate formula 
		
		U0FCR = 0x07;     // FIFO Controal Ragister set first three bit 1 , 00000111
		U0LCR = 0x03;     // Line Controal Ragister reset high bit of U0LCR 
		
		CCR = 0x11;   //clock control register 00010001; 0x11; 1 & 4 bit no set
		CIIR = 0x00;  // all input set 0
		AMR = 0xff;   // all input set 1
		
		SEC = 55;
		MIN = 55;
		HOUR = 02;
		
		while(1)
		{
			ch = 0x0D;       // go to home Command of hyper terminal
			tx();
			for(i=0;i<7;i++)
			{
				ch = arr[i];
				tx();
			}
			RW_RTC();
		}
	}
	
	void rx()
	{
		while((U0LSR & 0x01)!= 0x01);
		U0LSR = 0;
		ch = U0RBR;
	}
	
	void RW_RTC()
	{
		ch =' ';
		tx();
		
		j = HOUR / 10;
		j = j +'0';
		ch = j;
		tx();
		
		k = HOUR % 10;
		k = k +'0';
		ch = k;
		tx();
		
		ch = ':';
		tx();
		
		j = MIN / 10;
		j = j +'0';
		ch = j;
		tx();
		
		k = MIN % 10;
		k = k +'0';
		ch = k;
		tx();
		
		ch = ':';
		tx();
		
		j = SEC / 10;
		j = j +'0';
		ch = j;
		tx();
		
		k = SEC % 10;
		k = k +'0';
		ch = k;
		tx();
		
		ch = ':';
		tx();
	}