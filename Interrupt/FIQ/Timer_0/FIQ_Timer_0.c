// Generate FIQ interrupt for timer_0

#include<LPC214X.H>

unsigned char i = 0x00;

	void init_timer_0(void);
	
	int main()
	{
		VPBDIV = 0x02;
		PINSEL0 = 0x00000000;
		IO0DIR = 0xffffffff;
		init_timer_0();
		IO0CLR = 0xffffffff;
		while(1);
	}
		

	__irq void FIQ_Handler(void)
	  {
			if(i == 0x00)
			{
				IO0SET = 0xffffffff;
				i = 0xff;
			}
			else
			{
				IO0CLR = 0xffffffff;
				i = 0x00;
			}
			T0IR = 0x01;               //clear interrupt falg
		}
		
		void init_timer_0(void)
		{
			T0CTCR = 0x00;
			T0MR0 = 0x00ffffff;        // 10 sec = 
			T0MCR = 0x00000003;        //Interrupt and Reset on MR0
			T0TCR = 0x00000001;        // Timer control register
			VICIntSelect = 0x00000010; // Timer_0 enable
			VICVectCntl0 = 0x20 | 4;   // Vector Control 0 register use for timer 0 interrupt
			VICIntEnable = 0x00000010; // Enable timer_0 interrupt
		}
	




		