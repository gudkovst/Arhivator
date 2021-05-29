#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#include "arxivator.h"
#include "dearxivator.h"


int main(int argc, char* argv[]) {
	if (argc == 1) {
		printf("Not parameters\n");
		return 0;
	}
	if (argv[1] == 'a')
		arxivation(argv[2], argv[3]);
	if (argv[1] == 'x')
		dearxivation(argv[2], argv[3]);
	return 0;
}
