#include<LPC214x.H>

	void delay(void);
	
	int main()
	{
		VPBDIV = 0x00;          //Peripheral frequency 60/4 = 15Mhz
		PINSEL0 = 0x00000000;
		IO0DIR = 0xffffffff;
		while(1)
		{
			IO0SET = 0xffffffff;
			delay();
			IO0CLR = 0xffffffff;
			delay();
		}
  }
	
	void delay()
	{
		unsigned int i;
		for(i=0; i<6000; i++);
  }
	
	
	
	
	
	