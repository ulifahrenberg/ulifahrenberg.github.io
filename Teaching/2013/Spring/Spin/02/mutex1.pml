bit flag; /* signal flag */
byte mutex = 0; /* for testing mutual exclusion */

proctype P() {
	flag != 1; /* wait for flag==0 */
	flag = 1; /* to signal that we're entering */
	
	mutex++; /* models critical section */
	mutex--;

	flag = 0 /* to signal that we're done */
}

proctype monitor() {
	assert(mutex < 2)
}

init {
	run P(); run P(); run monitor()
}