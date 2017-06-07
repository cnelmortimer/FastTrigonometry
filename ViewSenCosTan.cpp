#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "FastTrig.h"

int main(int argc, char* argv[]){
	if(argc!=2){
		printf("Llamada: ./programa angulo_rad (entre -pi y pi)\n"); return -1;
	}
	double x = atof(argv[1]);
	double coseno = fastCos(x);
	double check = 1.0 - (x*x)/2.0 + (x*x*x*x)/24.0 - (x*x*x*x*x*x)/720.0 + (x*x*x*x*x*x*x*x)/40320.0 - (x*x*x*x*x*x*x*x*x*x)/3628800.0 + (x*x*x*x*x*x*x*x*x*x*x*x)/479001600.0;
	double cosenoOficial = cos(x);
	//---------------------------------
	double seno = fastSin(x);
	double checkB = x - (x*x*x)/6.0 + (x*x*x*x*x)/120.0 - (x*x*x*x*x*x*x)/5040.0  + (x*x*x*x*x*x*x*x*x)/362880.0 - (x*x*x*x*x*x*x*x*x*x*x)/39916800.0 + (x*x*x*x*x*x*x*x*x*x*x*x*x)/6227020800.0;
	double senoOficial = sin(x);
	//---------------------------------
	double tangente = fastTan(x);
	double checkC = x + (x*x*x)/3.0 + 2.0*(x*x*x*x*x)/15.0 + 17.0*(x*x*x*x*x*x*x)/315.0 + 62.0*(x*x*x*x*x*x*x*x*x)/2835.0 + 1382.0*(x*x*x*x*x*x*x*x*x*x*x)/155925.0 + 21844.0*(x*x*x*x*x*x*x*x*x*x*x*x*x)/6081075.0;
	double tangenteOficial = tan(x);	
	//---------------------------------
	printf("Mi coseno: %lf, CHECK: %lf, Oficial: %lf\n", coseno, check, cosenoOficial);
	printf("Mi seno: %lf, CHECK: %lf, Oficial: %lf\n", seno, checkB, senoOficial);
	printf("Mi tangente: %lf, CHECK: %lf, Oficial: %lf\n", tangente, checkC, tangenteOficial);
	return 0;
}
