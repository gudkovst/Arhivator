#include<stdio.h>
#include<stdlib.h>

#include "st_node.h"

void restore_tree(Xnode* h, FILE* in);
char decoding(Xnode* h, FILE* in);
void dearxivation(FILE* in, FILE* out);