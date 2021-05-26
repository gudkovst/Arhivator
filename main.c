#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "arxivator.h"
#include "dearxivator.h"


int main(int argc, char* argv[]) {
	FILE* in, * out;
	if (argc == 1) {
		printf("Not parameters\n");
		return 0;
	}
	char komanda = argv[1];
	in = fopen(argv[2], "rb");
	out = fopen(argv[3], "wb");
	if (komanda == 'a')
		arxivation(in, out);
	if (komanda == 'x') 
		dearxivation(in, out);
	fclose(in);
	fclose(out);
	return 0;
}