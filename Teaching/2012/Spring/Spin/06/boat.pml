bit fail=0;
bit success=0;

chan lfarmer = [0] of {bit};
chan lwolf = [0] of {bit};
chan lgoat = [0] of {bit};
chan lcabbage = [0] of {bit};
chan rfarmer = [0] of {bit};
chan rwolf = [0] of {bit};
chan rgoat = [0] of {bit};
chan rcabbage = [0] of {bit};

active proctype left () {
	bit farmer=1;
	bit wolf=1;
	bit goat=1;
	bit cabbage=1;
	do
	:: farmer==1 -> lfarmer!1; farmer--
	:: wolf==1 -> lwolf!1; wolf--
	:: goat==1 -> lgoat!1; goat--
	:: cabbage==1 -> lcabbage!1; cabbage--
	:: farmer==0; lfarmer?1 -> farmer++
	:: wolf==0; lwolf?1 -> wolf++
	:: goat==0; lgoat?1 -> goat++
	:: cabbage==0; lcabbage?1 -> cabbage++
	:: (farmer==0)&&(goat==1)&&((wolf==1)||(cabbage==1)) -> fail++
	od
}

active proctype right () {
	bit farmer=0;
	bit wolf=0;
	bit goat=0;
	bit cabbage=0;
	do
	:: farmer==1 -> rfarmer!1; farmer--
	:: wolf==1 -> rwolf!1; wolf--
	:: goat==1 -> rgoat!1; goat--
	:: cabbage==1 -> rcabbage!1; cabbage--
	:: farmer==0; rfarmer?1 -> farmer++
	:: wolf==0; rwolf?1 -> wolf++
	:: goat==0; rgoat?1 -> goat++
	:: cabbage==0; rcabbage?1 -> cabbage++
	:: (farmer==0)&&(goat==1)&&((wolf==1)||(cabbage==1)) -> fail++
	:: (farmer==1)&&(goat==1)&&(wolf==1)&&(cabbage==1) -> success++
	od
}

active proctype boat () {
	bit f, w, g, c;
	byte count=0;
S1:	do
	:: (f==0)&&(count<2); lfarmer?1 -> f++; count++
	:: (w==0)&&(count<2); lwolf?1 -> w++; count++
	:: (g==0)&&(count<2); lgoat?1 -> g++; count++
	:: (c==0)&&(count<2); lcabbage?1 -> c++; count++
	:: f==1 -> goto S2
	od;
S2:	do
	:: f==1 -> rfarmer!1; count--
	:: w==1 -> rwolf!1; count--
	:: g==1 -> rgoat!1; count--
	:: c==1 -> rcabbage!1; count--
	:: f==1 -> goto S1
	od
}

active proctype monitor1 () {
	assert(fail==0)
}

active proctype monitor2 () {
	success==1 -> goto accept;
accept: skip
}

