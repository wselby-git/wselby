      START	0  
      L	1,=A(JOB)				;Load JOB name in reg 1
      L	2,=A(DESENCRYPTION)		        ;Load DESENCRYPTION name in reg 2
      SR	2,2				;Shift right twice 
      SVC	CODE(3)				;Call Supervisor Call
      BC	7,END				;Branch to END 
      L	15,=A(INPUT)			;Load INPUT name in reg 15
      SR	15,15				;Shift right twice
      SVC	CODE(4)				;Call Supervisor Call
      L	14,=A(OUTPUT)			;Load OUTPUT name in reg 14
      SR	14,14				;Shift right twice
      SVC	CODE(5)				;Call Supervisor Call
      LA	12,=V(DES)			;Load DES in reg 12
      SR	12,2				;Shift right twice
      SVC	CODE(6)				;Call Supervisor Call
      L	13,=A(KEY)			;Load KEY in reg 13
      SR	13,2				;Shift right twice
      SVC	CODE(7)				;Call Supervisor Call
      L	11,=A(IV)			;Load IV in reg 11
      SR	11,2				;Shift right twice
      SVC	CODE(8)				;Call Supervisor Call
      L	4,=F(DESENCRYPT)		;Load DESENCRYPT in reg 4
      SR	4,2				;Shift right twice
      SVC	CODE(9)				;Call Supervisor Call
      END	XR	15,15			;Exit program

DESENCRYPT	C	E			;Main DES Encryption routine
		MVI	B,0			;Clear B register
		LM	0,1,IV			;Load IV in reg 0
		SR	0,2			;Shift right twice
		MVC	0(8,B),0		;Copy IV into B
		LR	1,0			;Load IV into reg 1
		SR	1,2			;Shift right twice
		MVC	1(8,B),1		;Copy IV into B
		LR	2,4			;Load DESENCRYPT in reg 2
		SR	2,2			;Shift right twice
		MVC	2(8,B),2		;Copy DESENCRYPT into B
		LR	3,12			;Load DES in reg 3
		SR	3,2			;Shift right twice
		MVC	3(8,B),3		;Copy DES into B
		LR	4,13			;Load KEY in reg 4
		SR	4,2			;Shift right twice
		MVC	4(8,B),4		;Copy KEY into B
		LR	5,15			;Load INPUT in reg 5
		SR	5,2			;Shift right twice
		MVC	5(8,B),5		;Copy INPUT into B
		LR	6,14			;Load OUTPUT in reg 6
		SR	6,2			;Shift right twice
		MVC	6(8,B),6		;Copy OUTPUT into B
		BALR	14,13			;Branch to reg 13
		BR	14			;Branch to reg 14
		END	BR	14			;Branch to reg 14
