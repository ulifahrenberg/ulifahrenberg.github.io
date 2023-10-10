#define FROGS 16
#define FIELDSIZE 33 /* 2*FROGS+1 */
byte frogs=FROGS;
byte fieldsize=FIELDSIZE;

byte field[FIELDSIZE]; /* frog playing field */
byte steps; /* for counting steps */

byte lok=0; /* for checking finished left side */
byte rok=0; /* for checking finished right side */

proctype rmove(byte i) {
	do
	::	atomic {
			(field[i]==1)&&(field[i+1]==0) ->
			field[i]=0; field[i+1]=1;
			steps++;
			if
			::	rok+i==fieldsize-2 -> rok++
			::	else -> skip
			fi
		}
	od
}

proctype lmove(byte i) {
	do
	::	atomic {
			(field[i]==2)&&(field[i-1]==0) ->
			field[i]=0; field[i-1]=2;
			steps++;
			if
			::	lok==i-1 -> lok++
			::	else -> skip
			fi
		}
	od
}

proctype rjump(byte i) {
	do
	::	atomic {
			(field[i]==1)&&(field[i+1]!=0)&&(field[i+2]==0) ->
			field[i]=0; field[i+2]=1;
			steps++;
			if
			::	rok+i==fieldsize-3 -> rok++
			::	else -> skip
			fi
		}
	od
}

proctype ljump(byte i) {
	do
	::	atomic {
			(field[i]==2)&&(field[i-1]!=0)&&(field[i-2]==0) ->
			field[i]=0; field[i-2]=2;
			steps++;
			if
			::	lok==i-2 -> lok++
			::	else -> skip
			fi
		}
	od
}

init {
	byte iter=0;
	do
	:: iter<frogs -> field[iter]=1; iter++
	:: iter==frogs -> field[iter]=0; iter++
	:: (iter>frogs)&&(iter<fieldsize) -> field[iter]=2; iter++
	:: iter==fieldsize -> break
	od;

	steps=0;

	for (iter:0..fieldsize-2) { run rmove(iter) };
	for (iter:0..fieldsize-3) { run rjump(iter) };
	for (iter:1..fieldsize-1) { run lmove(iter) };
	for (iter:2..fieldsize-1) { run ljump(iter) }
}

/* old LTL claim which works only for FROGS==3 */
/*	
ltl {
	[]!((field[0]==2)&&(field[1]==2)&&(field[2]==2)&&
		(field[3]==0)&&
		(field[4]==1)&&(field[5]==1)&&(field[6]==1))
}
*/ 

/* LTL claim using lok and rok */
ltl {
	[]!((lok==FROGS)&&(rok==FROGS))
}
