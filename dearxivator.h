// dearxivator.h

#pragma once
#include<stdio.h>
#include "st_node.h"

void restore_tree(Xnode* h, FILE* in);
char decoding(Xnode* h, FILE* in);
void dearxivation(char* file_in, char* file_out);
