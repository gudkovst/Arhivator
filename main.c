#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

#include "arxivator.h"
#include "dearxivator.h"


int main(int argc, char* argv[]) {
	if (argc <= 2) {
		printf("Not parameters\n");
		return 0;
	}
	char* file_in = (char*)malloc(150 * sizeof(char));
	char* file_out = (char*)malloc(150 * sizeof(char));
	int nin = strlen(argv[2]);
	int nout = strlen(argv[3]);
	for (int i = 0; i < nin; i++) 
		file_in[i] = argv[2][i];
	file_in[nin] = '\0';
	for (int i = 0; i < nout; i++)
		file_out[i] = argv[3][i];
	file_out[nout] = '\0';
	if (argv[1][0] == 'a') {
		if (argc == 3)
			arxivation(file_in, "z.bin");
		else
			arxivation(file_in, file_out);
	}
	if (argv[1][0] == 'x') {
		if (argc == 3)
			printf("Few parameters\n");
		else
			dearxivation(file_in, file_out);
	}
	return 0;
}
