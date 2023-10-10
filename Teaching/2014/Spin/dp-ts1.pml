/* number of philosophers / forks */
#define MAX 3

chan tf[MAX] = [0] of {bit}; /* take fork */
chan rf[MAX] = [0] of {bit}; /* release fork */

proctype Phil(byte i) {
S1: if							/* thinking */
	:: tf[(i+1)%MAX]?1 -> goto S2
	:: tf[i]?1 -> goto S3
	fi;
S2:	tf[i]?1 -> goto S4;			/* have right fork */
S3:	tf[(i+1)%MAX]?1 -> goto S4;	/* have left fork */
S4:	rf[(i+1)%MAX]!1;			/* eating */
	rf[i]!1;
	goto S1
}

proctype Fork(byte i) {
S1:	tf[i]!1;					/* ready */
	goto S2;
S2:	rf[i]?1 -> goto S1			/* in use */
}

init {
	int i;
	atomic {
		for (i : 1 .. MAX) {
			run Phil(i-1);
			run Fork(i-1)
		}
	}
}