#define MAX 4

chan msg = [3] of {byte,bit};
chan ack = [3] of {bit};

active proctype A() {
	byte mt=0; /* message data */
	bit  vr;
S1:	mt = (mt+1)%MAX;
	msg!mt,1;
	goto S2;
S2:	ack?vr;
	if
	:: (vr == 1) -> goto S1
	:: (vr == 0) -> goto S3
	:: printf("MSC: AERROR1\n") -> goto S5
	fi;
S3:	msg!mt,1;
	goto S2;
S4:	ack?vr;
	if
	:: goto S1
	:: printf("MSC: AERROR2\n"); goto S5
	fi;
S5:	msg!mt,0;
	goto S4
}

active proctype B(){
	byte mr;
	bit ar;
	goto S2; /* initial state */
S1:	ack!1;
	goto S2;
S2:	msg?mr,ar;
	if
	:: (ar == 1) -> goto S1
	:: (ar == 0) -> goto S3
	:: printf("MSC: ERROR1\n"); goto S5
	fi;
S3:	ack!1;
	goto S2;
S4:	msg?mr,ar;
	if
	:: goto S1
	:: printf("MSC: ERROR2\n"); goto S5
	fi;
S5:	ack!0;
	goto S4
}
