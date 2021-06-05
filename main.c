#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "arxivator.h"
#include "dearxivator.h"


int main(int argc, char* argv[]) {
	if (argc <= 2) {
		printf("Not parameters\n");
		return 0;
	}
	if (argv[1][0] == 'a'){
		if (argc == 3)
			arxivation(argv[2], "z.bin");
		else	
			arxivation(argv[2], argv[3]);
	}
	if (argv[1][0] == 'x'){
		if (argc == 3)
			printf("Few parameters\n");
		else	
			dearxivation(argv[2], argv[3]);
	}
	return 0;
}
