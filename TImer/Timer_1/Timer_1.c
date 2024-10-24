// LED rotate using timer_1 with LPC2148

#include<LPC214X.H>

	void init_timer_1(void);

	int main()
	 {
		 VPBDIV = 0x02;          //PCLK = fosc/2 ==30M HZ
		 T1PR = 0x1D;           // prescaler = (30-1) =29 = 0x1D
		 IO0DIR = 0x00ff0000;  //  p1.16 .. .13 defined as		 output
		 
		 while(1)
		 {
			 IO0PIN = 0x00ff0000;
			 init_timer_1();
			 IO0PIN = 0x00000000;
			 init_timer_1();
		 }
	 }
	 
	 void init_timer_1(void)
	 {
		 T1CTCR = 0x00000000;     //counter /timer controal register
		 T1TC = 0x00000000;      // timer /counter   . It is automatic time
		 T1MR0 = 100000;        // 100 ms * 10000 microsecond match counter
		 T1MCR = 0x00000004;   //  match countre register . If timer_0 will match with the register 3
		 T1TCR = 0x01;
		 while(T1TC != T1MR0)
		 {
     }
	 }
	 
	 
	 