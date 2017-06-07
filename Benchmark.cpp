#include <cstdlib>
#include <cstdio>
#include <cmath>
#include "Timers.h"
#include "FastTrig.h"

void testFunc(int testSize, const double* x, double* officialRes, double* approRes, double (*refFunc)(double), 
			double (*approFunc)(double, int), int prec, const char* name){
	double tA = get_wall_time();
	for(int i = 0; i<testSize; i++){
		officialRes[i] = refFunc(x[i]);
	}
	double tB = get_wall_time();
	printf("Tiempo medio del %s estándar (s):\t %.10lf\n", name, (tB - tA)/testSize);
	
	tA = get_wall_time();
	for(int i = 0; i<testSize; i++){
		approRes[i] = approFunc(x[i], prec);
	}
	tB = get_wall_time();
	printf("Tiempo medio del %s aproximado (s):\t %.10lf\n", name, (tB - tA)/testSize);
	double error = 0.0;
	for(int i = 0; i<testSize; i++){
		error += fabs(officialRes[i] - approRes[i]);
	}
	printf("Error medio del %s aproximado:\t %.10lf\n", name, error/testSize);
}

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("Error: Llamada: ./prog test_size precision[1-6]\n"); return -1;
	}
	int testSize = atoi(argv[1]);
	int prec = atoi(argv[2]);
	double* x = new double[testSize];
	for(int i = 0; i<testSize; i++){
		x[i] = ((double) rand()/RAND_MAX)*6.283185307 - 3.141592654;//-Pi, Pi
	}
	double* officialRes = new double[testSize];
	double* approRes = new double[testSize];
	testFunc(testSize, x, officialRes, approRes, std::sin, fastSin, prec, "seno");
	printf("----------------------------\n");
	testFunc(testSize, x, officialRes, approRes, std::cos, fastCos, prec, "coseno");

	delete [] x;
	delete [] officialRes;
	delete [] approRes;
	return 0;
}
