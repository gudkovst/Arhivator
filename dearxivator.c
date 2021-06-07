// dearxivator.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "st_node.h"

long long COUNT;

Xnode* create_node(Xnode* l, Xnode* r) {
	Xnode* p = (Xnode*)malloc(sizeof(Xnode));
	p->left = l;
	p->right = r;
	return p;
}

Xnode* restore_tree(FILE* in) {
	unsigned char c;
	fread(&c, sizeof(char), 1, in);
	if (!c) {
		Xnode* l = restore_tree(in);
		Xnode* r = restore_tree(in);
		return create_node(l, r);
	}
	else {
		Xnode* p = create_node(NULL, NULL);
		fread(&p->data, sizeof(char), 1, in);
		return p;
	}
}

void decoding(Xnode* h, FILE* in, FILE* out) {
	Xnode* p = h;
	int k = 0;
	unsigned char byte;
	fread(&byte, sizeof(char), 1, in);
	while (COUNT) {
		unsigned char bit = byte & (1 << (7 - k));
		if (bit)
			p = p->right;
		else
			p = p->left;
		if (!p->left && !p->right) {
			fwrite(&p->data, sizeof(char), 1, out);
			COUNT--;
			p = h;
		}
		k = (k + 1) % 8;
		if (!k)
			fread(&byte, sizeof(char), 1, in);
	}

}

void dearxivation(char* file_in, char* file_out) {
	FILE* in, * out;
	in = fopen(file_in, "rb");
	out = fopen(file_out, "wb");
	fread(&COUNT, sizeof(long long), 1, in);
	if (!COUNT)
		return;
	Xnode* root = restore_tree(in);
	decoding(root, in, out);
	fclose(in);
	fclose(out);
}
