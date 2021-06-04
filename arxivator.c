// arxivator.c

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#include "st_node.h"

Xnode* derevo[256] = { NULL };
char kod[256][100];
int count = 0;
long long COUNT = 0;

void create() {
	for (int i = 0; i < 256; i++) {
		derevo[i] = (Xnode*)malloc(sizeof(Xnode));
		derevo[i]->data = i;
		derevo[i]->left = NULL;
		derevo[i]->right = NULL;
		derevo[i]->next = NULL;
		derevo[i]->kol = 0;
	}
}

void initialization(char x) {
	if (!derevo[x]->kol)
		count++;
	derevo[x]->kol++;
	COUNT++;
}

void swap(Xnode** a, Xnode** b) {
	Xnode* t = *a;
	*a = *b;
	*b = t;
}

void sort() {
	for (int i = 0; i < 255; i++)
		for (int j = 254; j >= i; j--)
			if (derevo[j]->kol > derevo[j + 1]->kol)
				swap(&derevo[j], &derevo[j + 1]);
}

Xnode* make_tree(int N) {
	int k = N;
	for (int i = 256 - N; i < 255; i++)
		derevo[i]->next = derevo[i + 1];
	Xnode* first = derevo[256 - N];
	while (k - 1) {
		Xnode* p = (Xnode*)malloc(sizeof(Xnode));
		p->right = first;
		p->left = first->next;
		p->kol = p->right->kol + p->left->kol;
		Xnode* t = p->left;
		while (t->next && t->next->kol < p->kol)
			t = t->next;
		p->next = t->next;
		t->next = p;
		first = first->next->next;
		k--;
	}
	return first;
}

void razdacha_kod(Xnode* h, char* sk, int k) {
	if (!h->left && !h->right) {
		for (int i = 0; i < k; i++)
			kod[h->data][i] = sk[i];
		return;
	}
	sk[k] = 1;
	razdacha_kod(h->left, sk, k + 1);
	sk[k] = 2;
	razdacha_kod(h->right, sk, k + 1);
}

void write_tree(Xnode* p, FILE* out) {
	char z;
	if (!p->left && !p->right) {
		z = 1;
		fwrite(&z, sizeof(char), 1, out);
		fwrite(&p->data, sizeof(char), 1, out);
		return;
	}
	z = 0;
	fwrite(&z, sizeof(char), 1, out);
	if (p->left)
		write_tree(p->left, out);
	if (p->right)
		write_tree(p->right, out);
}

void print_kod(FILE* in, FILE* out) {
	char c, byte = 0;
	int k = 0;
	while (fread(&c, sizeof(char), 1, in)){
		int n = strlen(kod[c]);
		for (int i = 0; i < n; i++){
			byte = byte | ((kod[c][i] - 1) << (7 - k));
			k = (k + 1) % 8;
			if (!k){
				fwrite(&byte, sizeof(char), 1, out);
				byte = 0;
			}
		}
	}
	if (byte)
		fwrite(&byte, sizeof(char), 1, out);
}

void arxivation(char* file_in, char* file_out) {
	FILE* in, * out;
	char c;
	in = fopen(file_in, "rb");
	out = fopen(file_out, "wb");
	create();
	while (fread(&c, sizeof(char), 1, in))
		initialization(c);
	fwrite(&COUNT, sizeof(long long), 1, out);
	fclose(in);
	sort();
	Xnode* root = make_tree(count);
	char* strkod = (char*)malloc(100 * sizeof(char));
	for (int i = 0; i < 100; i++)
		strkod[i] = '\0';
	razdacha_kod(root, strkod, 0);
	write_tree(root, out);
	in = fopen(file_in, "rb");
	print_kod(in, out);
	fclose(in);
	fclose(out);
}
