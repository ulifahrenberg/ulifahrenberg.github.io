/* number of philosophers / forks */
/* with waiter = process */
#define MAX 8

chan tf[MAX] = [0] of {bit};
chan rf[MAX] = [0] of {bit};
chan tw = [0] of {bit};
chan rw = [0] of {bit};

proctype Phil(byte i) {
S1: if
	:: tw?1; tf[(i+1)%MAX]?1 -> goto S2
	:: tw?1; tf[i]?1 -> goto S3
	fi;
S2:	tf[i]?1 -> goto S4;
S3:	tf[(i+1)%MAX]?1 -> goto S4;
S4:	rf[(i+1)%MAX]!1;
	rf[i]!1;
	rw!1;
	goto S1
}

proctype Fork(byte i) {
S1:	tf[i]!1;
	goto S2;
S2:	rf[i]?1 -> goto S1
}

proctype Waiter(byte max) {
	int num=max-1;
	do
	:: (num>0) -> tw!1; num=num-1
	:: rw?1 -> num=num+1
	od
}
	
init {
	int i;
	atomic {
		for (i : 1 .. MAX) {
			run Phil(i-1);
			run Fork(i-1)
		};
		run Waiter(MAX)
	}
}