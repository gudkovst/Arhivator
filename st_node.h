#pragma once

typedef struct Xafman_node {
	char data;
	int list;
	struct Xafman_node* left;
	struct Xafman_node* right;
	struct Xafman_node* next;
	int kol;
}Xnode;