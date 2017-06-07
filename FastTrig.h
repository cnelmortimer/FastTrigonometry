//http://people.math.sc.edu/girardi/m142/handouts/10sTaylorPolySeries.pdf

double fastCos(double x, int len=6){//USE BETWEEN -pi, pi
	double sq_x = x*x, output = 1.0, qu_x = sq_x*sq_x;
	double fac[] = {2.0, 24.0, 720.0, 40320.0, 3628800.0, 479001600.0};//2!, 4!, 6!, 8!, 10!, 12!...
	for(int i = 0; i<len; i = i + 2){
		output -= (sq_x / fac[i]);
		sq_x = sq_x*qu_x;
	}
	sq_x = qu_x;
	for(int i = 1; i<len; i = i + 2){
		output += (sq_x / fac[i]);
		sq_x = sq_x*qu_x;
	}
	return output;
}

double fastSin(double x, int len=6){//USE BETWEEN -pi, pi
	double tr_x = x*x*x, output = x, qu_x = tr_x*x;
	double fac[] = {6.0, 120.0, 5040.0, 362880.0, 39916800.0, 6227020800.0};//3!, 5!, 7!, 9!, 11!, 13!...
	for(int i=0; i<len; i = i+2){
		output -= (tr_x/fac[i]);
		tr_x = tr_x*qu_x;
	}
	tr_x = qu_x*x;
	for(int i=1; i<len; i = i+2){
		output += (tr_x/fac[i]);
		tr_x = tr_x*qu_x;
	}	
	return output;
}
//http://www.wolframalpha.com/input/?i=taylor+expand+tan(x)+to+order+13
double fastTan(double x, int len=6){//USE BETWEEN -pi/2, pi/2
	double sq_x = x*x, output = x, tr_x = sq_x*x;
	double fac[] = {1.0/3.0, 2.0/15.0, 17.0/315.0, 62.0/2835.0, 1382.0/155925.0, 21844.0/6081075.0};
	for(int i = 0; i<len; i++){
		output += fac[i]*tr_x;
		tr_x = tr_x*sq_x;
	}
	return output;
}
