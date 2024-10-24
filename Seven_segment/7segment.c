#include<LPC214X.H>

//	void rotate(void);

  long unsigned int d1,d2,d3,d4;
	unsigned int arr[] = {0x00fc0000,0x00600000,0x00da0000,0x00f20000,0x00660000,0x00b60000,0x00be0000,0x00e00000,0x00fe0000,0x00f60000};
	
	void inc(void);
	void display(void);
	void delay(unsigned int k);
	
	int main(void)
	{
		unsigned int i;
		VPBDIV = 0x00;     //60/4=15MHZ
	    // PINSETL0 = 0x00000000;
		PINSEL1 = 0x00000000;   //gpio
		PINSEL2 = 0x00000000;   // gpio
		
		IO0DIR = 0x00FF0000;   //Direction output P0.16...to...P0.23
		d1=d2=d3=d4=0;
		while(1)
		{
			for(i=0;i<12;i++)
			 {
				 display();
			 }
			 inc();
		}
  }
	
	void inc()
	{
		d1++;
		if(d1 == 10)
		{
			d2 = 0;
		
	  d2++;
		if(d2 == 10)
		{
			d3 = 0;
			
		d3++;
		if(d3 == 10)
		{
			d4 = 0;
		
		d4++;
		if(d4 == 10)
		{
			d4 = 0;
			d1 = 0;
		}
		}
		}
		}	
  }
	
	void display()
	{
		IO1DIR = 0x00010000;
		IO0SET = arr[d1];
		delay(10);
		IO0CLR = arr[d1];
		delay(10);
		
		IO1DIR = 0x00020000;
		IO0SET = arr[d2];
		delay(10);
		IO0CLR = arr[d2];
		delay(10);
		
		IO1DIR = 0x00040000;
		IO0SET = arr[d3];
		delay(10);
		IO0CLR = arr[d3];
		delay(10);
		
		IO1DIR = 0x00080000;
		IO0SET = arr[d4];
		delay(10);
		IO0CLR = arr[d4];
		delay(10);
  }
	
	void delay(unsigned int k)
	{
		unsigned int i,j;
		for(i=0;i<k;i++)
		{
		 for(j=0;j<60000;j++);
		}
  }	
	
	
	
	
	
	