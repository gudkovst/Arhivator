// dearxivator.h

#pragma once
#include<stdio.h>
#include "st_node.h"

Xnode* create_node(char k, Xnode* l, Xnode* r);
void restore_tree(FILE* in);
void decoding(Xnode* h, FILE* in, FILE* out);
void dearxivation(char* file_in, char* file_out);
