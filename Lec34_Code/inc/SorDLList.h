/**********************************************
* File: SorDLList.h
* Author: Matthew Morrison
* Email: matt.morrison@nd.edu
* 
* This file contains the function definitions and 
* structs for a Sorted Doubly Linked List Data structure 
**********************************************/

#ifndef SORDLLIST_H
#define SORDLLIST_H

#include <cstdlib>
#include <iostream>
#include <unordered_map>

#include "DLList.h"

template<class T>
class SorDLList : public DLList<T>{
	
	private:
	
		// Nothing
		
	public:
	
		// Default Constructor
		SorDLList() : DLList<T>() {}
		
		// Destructor
		~SorDLList(){

		}

		// Overloaded Insert
		void Insert (T value)
		{
		   typename DLList<T>::node* temp = new typename DLList<T>::node(value);

		   if ( this->IsEmpty() )
		   {
			   this->head = temp;
			   this->tail = temp;
		   }
		   else
		   {
				typename DLList<T>::node* prev =  NULL;
				typename DLList<T>::node* curr = this->head;

				/* traverse the list until the end or value <= data*/
				while (curr != NULL && curr->data < value)
				{
					prev = curr;
					curr = curr->next;
				}
		  
				// Inserting at the front
				if( prev != NULL ){
					/* insert the node, temp, at the end */
					prev -> next = temp;
				  
					/* Allocate the previous node */
					temp -> prev = prev;
				}
				
				// If prev is null, then there is only one element
				else{
					
					temp->next = this->head;
					this->head = temp;
					
				}
			  
				/* Inserting at the back */
				if( curr != NULL ){
					curr -> prev = temp;
					temp -> next = curr;
				}
				
				// If curr is NULL, then we insert at the end
				else{
					this->tail = temp;
					temp->next = NULL;
				}
		   }
		}
		
		// SorDLList Operator
		friend std::ostream& operator<<( std::ostream& output, const SorDLList<T>& theList ){
			
		   typename DLList<T>::node* curr;

		   if (theList.IsEmpty())
		   {
			  output << "The list is empty" << std::endl;;
		   }
		   else
		   {
			  /* set the current pointer to the first
			  ** node of the list */
			  curr = theList.head;

			  /* Until the end of the list */
			  while (curr != NULL)
			  {
				  /* print the current data item */
				  output << curr->data << " ";

				  /* move to the next node */
				  curr = curr -> next;
			  }
		   } 

		   return output;
		}

};

#endif
