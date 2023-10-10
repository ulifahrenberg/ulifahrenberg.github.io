#define Place	byte    /* assume < 256 tokens per place */

#define inp1(x)		(x>0) -> x=x-1
#define inp2(x,y)	(x>0&&y>0) -> x = x-1; y=y-1
#define inp3(x,y,z)	(x>0&&y>0&&z>0) -> x=x-1;y=y-1;z=z-1
#define out1(x)		x=x+1
#define out2(x,y)	x=x+1; y=y+1
#define out3(x,y,z)	x=x+1; y=y+1; z=z+1

Place fork0, fork1, fork2, fork3;
Place eat0, eat1, eat2, eat3;
Place think0, think1, think2, think3;

init {
	/* initial marking */
	fork0=1; fork1=1; fork2=1; fork3=1;
	think0=1; think1=1; think2=1; think3=1; 

	/* net structure */
	do
/*x0*/	:: atomic { inp3(fork3,fork0,think0) -> out1(eat0) }
/*y0*/	:: atomic { inp1(eat0) -> out3(fork3,fork0,think0) }
/*x1*/	:: atomic { inp3(fork0,fork1,think1) -> out1(eat1) }
/*y1*/	:: atomic { inp1(eat1) -> out3(fork0,fork1,think1) }
/*x2*/	:: atomic { inp3(fork1,fork2,think2) -> out1(eat2) }
/*y2*/	:: atomic { inp1(eat2) -> out3(fork1,fork2,think2) }
/*x3*/	:: atomic { inp3(fork2,fork3,think3) -> out1(eat3) }
/*y3*/	:: atomic { inp1(eat3) -> out3(fork2,fork3,think3) }
	od
}
