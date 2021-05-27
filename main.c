#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "arxivator.h"
#include "dearxivator.h"


int main(int argc, char* argv[]) {
	FILE* in, *in1, * out;
	if (argc == 1) {
		printf("Not parameters\n");
		return 0;
	}
	char komanda = argv[1];
	in = fopen(argv[2], "r");
	in1 = fopen(argv[2], "r");
	out = fopen(argv[3], "w");
	if (komanda == 'a')
		arxivation(in, in1, out);
	if (komanda == 'x')
		dearxivation(in, out);
	fclose(in);
	fclose(out);
	return 0;
}