#include "Test_Gauss.h"
#include <time.h>
#include <process.h>

//  9301  49297  233280
//  4096  150889  714025

int random(int max) {
	static int W = 0;
	static short firsttime = 1;
	if (firsttime == 1) { W = (((int)time(NULL) << 16) + _getpid()); firsttime = 0; }
		W = W * 11035115245 + 12345;
	return (unsigned int)(W / 65536) % (max + 1);
}

double UltimateRandom(int n) {
	//int W = (((int)time(NULL) << 16) + _getpid());
	double i = ((double)(random(n) + random(n))) / ((double)(random(n) + random(n) + 2 * random(n)));
	return (i > 1)? i/2 : i;
}