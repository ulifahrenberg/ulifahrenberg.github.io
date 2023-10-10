#define Aturn	false
#define Bturn	true
bool x, y, t;
bool inC1, inC2; /* in critical section */

/* for ltl formula */
#define c1 inC1==true
#define c2 inC2==true

proctype A() {
	x = true;
	t = Bturn;
	(y == false || t == Aturn);
	inC1=true; inC1=false; /* critical section */
	x = false
}

proctype B() {
	y = true;
	t = Aturn;
	(x == false || t == Bturn);
	inC2=true; inC2=false; /* critical section */
	y = false
}

init {
	run A(); run B()
}
