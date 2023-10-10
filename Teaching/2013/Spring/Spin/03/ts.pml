chan c = [0] of {byte};

active proctype P1 () {
	byte v;
S1:	c!2;
	printf("P1: transmit 2\n");
	goto S2;
S2: c?v;
	printf("P1: receive %d\n", v);
	goto S1
}

active proctype P2 () {
	byte v;
S1: c?v;
	printf("P2: receive %d\n", v);
	goto S2;
S2: c!3;
	printf("P2: transmit 3\n");
	goto S1
}