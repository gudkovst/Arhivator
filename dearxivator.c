// dearxivator.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "st_node.h"

Xnode* create_node(char k, Xnode* l, Xnode* r) {
	Xnode* p = (Xnode*)malloc(sizeof(Xnode));
	p->list = k;
	p->left = l;
	p->right = r;
	return p;
}

Xnode* restore_tree(FILE* in) {
	char c;
	fread(&c, sizeof(char), 1, in);
	if (!c) {
		Xnode* l = restore_tree(in);
		Xnode* r = restore_tree(in);
		Xnode* h = create_node(0, l, r);
		
	}
	else {
		Xnode* p = create_node(1, NULL, NULL);
		fread(&p->data, sizeof(char), 1, in);
		return p;
	}
}

void decoding(Xnode* h, FILE* in, FILE* out) {
	if (h->list) {
		fwrite(&h->data, sizeof(char), 1, out);
		return;
	}
	char bit_code;
	fread(&bit_code, sizeof(char), 1, in);
	if (bit_code == 1)
		decoding(h->right, in, out);
	else
		decoding(h->left, in, out);
}

void printp(Xnode* h) {
	if (h->list) {
		printf("%c", h->data);
		return;
	}
	printf("0");
	printp(h->left);
	printf("1");
	printp(h->right);
}

void dearxivation(char* file_in, char* file_out) {
	FILE* in, * out;
	in = fopen(file_in, "rb");
	out = fopen(file_out, "wb");
	int count;
	fread(&count, sizeof(int), 1, in);
	Xnode* root = restore_tree(in);
	for (int i = 0; i < count; i++)
		decoding(root, in, out);
	fclose(in);
	fclose(out);
}
