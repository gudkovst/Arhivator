// arxivator.h

#pragma once
#include<stdio.h>
#include "st_node.h"

void create();
void initialization(char x);
void swap(Xnode** a, Xnode** b);
void sort();
Xnode* make_tree(int N);
void razdacha_kod(Xnode* h, char* sk, int k);
void write_tree(Xnode* p, FILE* out);
void print_kod(FILE* in, FILE* out);
void arxivation(char* file_in, char* file_out);

