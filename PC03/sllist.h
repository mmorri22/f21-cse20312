#ifndef SLLIST_H
#define SLLIST_H

#include <stdio.h>
#include <stdlib.h>


typedef struct sll_node{

	int data;
	struct sll_node* next_node;	
	
}sll_node;


typedef struct sllist{
	
	struct sll_node* head_node;
	
} sllist;


void insert( sllist* the_list, int new_data );


void push_front( sllist* the_list, int new_data );


int pop_front( sllist* the_list );


void print_list( sllist* the_list );


void delete( sll_node** curr_node );


#endif

