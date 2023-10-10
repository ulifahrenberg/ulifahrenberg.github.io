#define TIMES 10
byte	n = 0;
byte	finished = 0;

proctype P() {
	byte 	i = 1;
	byte	temp;
	do :: ( i > TIMES ) -> break  
	   :: else ->

			temp = n;
			temp++;
			n = temp;

		i++
	od;
	finished++;  /* Process terminates */
}

init {
	run P();
	run P();
	finished == 2;
	printf("After execution, n = %d\n", n);
	assert (n>2)
}
