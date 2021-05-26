// dearxivator.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

void restore_tree(Xnode* h, FILE* in) {
	char c;
	fread(&c, sizeof(char), 1, in);
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
	int bit_code;
	fread(&bit_code, 1, 1, in);
	if (bit_code)
		return decoding(h->right, in);
	else
		return decoding(h->left, in);
}

void dearxivation(FILE* in, FILE* out){
	Xnode* root = NULL;
	restore_tree(root, in);
	decoding(root, in);
}