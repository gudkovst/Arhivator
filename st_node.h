#pragma once

typedef struct Xafman_node {
	unsigned char data;
	struct Xafman_node* left;
	struct Xafman_node* right;
	struct Xafman_node* next;
	int kol;
}Xnode;
