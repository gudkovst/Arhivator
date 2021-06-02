// dearxivator.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "st_node.h"

void restore_tree(Xnode* h, FILE* in) {
	char c;
	fread(&c, sizeof(char), 1, in);
	printf("%c ", c);
	if (c == '0') {
		Xnode* p = (Xnode*)malloc(sizeof(Xnode));
		p->list = 0;
		p->left = NULL;
		p->right = NULL;
		if (!h) {
			h = p;
			restore_tree(h, in);
		}
		else if (!h->left) {
			h->left = p;
			restore_tree(h->left, in);
		}
		else {
			h->right = p;
			restore_tree(h->right, in);
		}
	}
	else {
		char sim;
		Xnode* p = (Xnode*)malloc(sizeof(Xnode));
		p->list = 1;
		p->left = NULL;
		p->right = NULL;
		fread(&sim, sizeof(char), 1, in);
		p->data = sim;
		return;
	}
}

char decoding(Xnode* h, FILE* in) {
	if (h->list)
		return h->data;
	char bit_code;
	fread(&bit_code, sizeof(char), 1, in);
	if (bit_code)
		return decoding(h->right, in);
	else
		return decoding(h->left, in);
}
void printp(Xnode* t) {
	if (!t) return;
	printf("%c ", t->data);
	printp(t->left);
	printp(t->right);
}

void dearxivation(char* file_in, char* file_out) {
	FILE* in, * out;
	in = fopen(file_in, "rb");
	out = fopen(file_out, "wb");
	Xnode* root = NULL;
	restore_tree(root, in);
	if (root)
		printp(root);
	else printf("1 ");
	decoding(root, in);
	fclose(in);
	fclose(out);
}
