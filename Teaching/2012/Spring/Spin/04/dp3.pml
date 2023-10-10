#define Place	byte    /* assume < 256 tokens per place */

#define inp1(x)		(x>0) -> x=x-1
#define inp2(x,y)	(x>0&&y>0) -> x = x-1; y=y-1
#define inp3(x,y,z)	(x>0&&y>0&&z>0) -> x=x-1;y=y-1;z=z-1
#define out1(x)		x=x+1
#define out2(x,y)	x=x+1; y=y+1
#define out3(x,y,z)	x=x+1; y=y+1; z=z+1
#define out4(x,y,z,u)	x=x+1; y=y+1; z=z+1; u=u+1
#define out5(x,y,z,u,v)	x=x+1; y=y+1; z=z+1; u=u+1; v=v+1

Place fork0, fork1, fork2, fork3;
Place eat0, eat1, eat2, eat3;
Place think0, think1, think2, think3;

/* extra places for fork picking order */
Place t0f3,t0f0,t1f0,t1f1,t2f1,t2f2,t3f2,t3f3;

/* "waiter" semaphore */
Place w;

init {
	/* initial marking */
	fork0=1; fork1=1; fork2=1; fork3=1;
	think0=1; think1=1; think2=1; think3=1; 
	w=3;

	/* net structure */
	do
/*x0*/	:: atomic { inp3(fork3,think0,w) -> out1(t0f3) }
		:: atomic { inp2(fork0,t0f3) -> out1(eat0) }
		:: atomic { inp3(fork0,think0,w) -> out1(t0f0) }
		:: atomic { inp2(fork3,t0f0) -> out1(eat0) }
/*y0*/	:: atomic { inp1(eat0) -> out4(fork3,fork0,think0,w) }
/*x1*/	:: atomic { inp3(fork0,think1,w) -> out1(t1f0) }
		:: atomic { inp2(fork1,t1f0) -> out1(eat1) }
		:: atomic { inp3(fork1,think1,w) -> out1(t1f1) }
		:: atomic { inp2(fork0,t1f1) -> out1(eat1) }
/*y1*/	:: atomic { inp1(eat1) -> out4(fork0,fork1,think1,w) }
/*x2*/	:: atomic { inp3(fork1,think2,w) -> out1(t2f1) }
		:: atomic { inp2(fork2,t2f1) -> out1(eat2) }
		:: atomic { inp3(fork2,think2,w) -> out1(t2f2) }
		:: atomic { inp2(fork1,t2f2) -> out1(eat2) }
/*y2*/	:: atomic { inp1(eat2) -> out4(fork1,fork2,think2,w) }
/*x3*/	:: atomic { inp3(fork2,think3,w) -> out1(t3f2) }
		:: atomic { inp2(fork3,t3f2) -> out1(eat3) }
		:: atomic { inp3(fork3,think3,w) -> out1(t3f3) }
		:: atomic { inp2(fork2,t3f3) -> out1(eat3) }
/*y3*/	:: atomic { inp1(eat3) -> out4(fork2,fork3,think3,w) }
	od
}
