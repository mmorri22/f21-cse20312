#ifndef B_TREE_H
#define B_TREE_H

#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

template<class T>
struct b_tree_node{
	
	bool is_leaf;
	int num_keys;
	VECTOR< T >* keys;
	VECTOR< b_tree_node<T>* >* child_ptrs;
	
	// B-Tree Node Constructor
	b_tree_node( int& max_degree_in, bool is_leaf_in ) : 

		is_leaf( is_leaf_in ), 
		num_keys( 0 ),
		// Establish the vector size of max_degree (to give space to add one extra prior to splitting
		keys( new VECTOR< T >( max_degree_in ) ),
		// Establish the size of child_ptrs as max_degree
		child_ptrs( new VECTOR< b_tree_node<T>* >( max_degree_in, NULL ) ) {}
		
		
	~b_tree_node(){
		
		delete keys;
		delete child_ptrs;
		
	}
	
	b_tree_node( const b_tree_node<T>& copy ) : 
		is_leaf( copy.is_leaf ), 
		num_keys( copy.num_keys ),
		// Establish the vector size of max_degree minus 1
		keys( copy.keys ),
		// Establish the size of child_ptrs as max_degree
		child_ptrs( copy.child_ptrs) {
		
		//(void)copy;
		
	}
	
	b_tree_node<T>& operator=( const b_tree_node<T>& assign ){

		if( this != &assign ){}
			
		
		return *this;

	}			
	
};


template<class T>
class b_tree{
	
	private:
	
		int max_degree;
	
		b_tree_node<T>* root;
		
		void delete_tree( b_tree_node<T>* curr_node ){
			
			if( curr_node == NULL )
				return;
			
			for( int iter = 0; iter < curr_node->child_ptrs->size(); ++iter ){
				
				delete_tree( curr_node->child_ptrs->at(iter) );
				
			}
			
			delete curr_node;
			
		}
		
		
		bool insert( b_tree_node<T>*& curr_node, const T& elem ){
			
			if( curr_node->is_leaf == true && curr_node->num_keys < max_degree - 1 ){
				
				insert_non_full_leaf( curr_node, elem );
				
				return false;
			}
			
			if( curr_node->is_leaf == true && curr_node->num_keys == max_degree - 1 ){
				
				insert_full_leaf( curr_node, elem );
				
				split_child( curr_node );
				
				// Indicate a split 
				return true;
			}
			
			for( int iter = 0; iter < curr_node->num_keys; ++iter ){	

				if( elem < curr_node->keys->at(iter) ){
					
					if( insert( curr_node->child_ptrs->at(iter), elem ) ){
						
						COUT << "Found" << ENDL;
						
					}
					
					// Split was resolved
					return false;
				}
			}
			
			// Got here, means we are at the last valid node
			b_tree_node<T>* temp_node = curr_node->child_ptrs->at( curr_node->num_keys );
			if( insert( temp_node, elem ) ){
				
				COUT << "Found! " << curr_node->keys->at(0) << " " << curr_node->num_keys << ENDL;
				
				curr_node->keys->at( curr_node->num_keys ) = temp_node->keys->at(0);
				
				curr_node->child_ptrs->at( curr_node->num_keys ) = temp_node->child_ptrs->at(0);
				temp_node->child_ptrs->at(0) = NULL;
				
				curr_node->num_keys++;
				
				curr_node->child_ptrs->at( curr_node->num_keys ) = temp_node->child_ptrs->at(1);
				temp_node->child_ptrs->at(1) = NULL;
				
				delete temp_node;
				
			}
			
			return false;
			
		}
		
		void insert_non_full_leaf( b_tree_node<T>*& curr_node, const T& elem ){
			
			if( curr_node->num_keys == 0 ){
				
				curr_node->keys->at(0) = elem;
				
			}
			else{
				int curr_loc = curr_node->num_keys - 1;
				
				while( curr_loc >= 0 && curr_node->keys->at( curr_loc ) > elem ){
					
					curr_node->keys->at( curr_loc + 1 ) = curr_node->keys->at( curr_loc );
					
					--curr_loc;
				}
				
				curr_node->keys->at( curr_loc + 1 ) = elem;
			}
			
			curr_node->num_keys++;
			
		}
		
		void insert_full_leaf( b_tree_node<T>*& curr_node, const T& elem ){
			
			int curr_loc = curr_node->num_keys - 1;
			
			while( curr_loc >= 0 && curr_node->keys->at( curr_loc ) > elem ){
				
				curr_node->keys->at( curr_loc + 1 ) = curr_node->keys->at( curr_loc );
				
				--curr_loc;
			}
			
			curr_node->keys->at( curr_loc + 1 ) = elem;
			
			curr_node->num_keys++;
			
		}

		
		// Only split a leaf node by B-Tree rule
		void split_child( b_tree_node<T>*& curr_node ){
			
			// Create the left and right children
			b_tree_node<T>* left_child = new b_tree_node<T>( max_degree, true );
			b_tree_node<T>* right_child = new b_tree_node<T>( max_degree, true );
			
			// Set the minimum degree
			int min_degree; 
			
			// Allows for Odd Maximum Degrees
			if( max_degree % 2 == 1 )
				min_degree = max_degree / 2;
			
			// Allows for Odd Minimum Degrees 
			else
				min_degree = max_degree / 2 - 1;
			
			// Iterate and get the first min_degree elements and put into the left child
			for( int iter = 0; iter < min_degree; ++iter ){
				
				insert_non_full_leaf( left_child, curr_node->keys->at(iter) );
				
			}
			
			// Get all the elements AFTER min_degree and put them in the right chi;d
			for( int iter = min_degree + 1; iter < curr_node->num_keys; ++iter ){
				
				insert_non_full_leaf( right_child, curr_node->keys->at(iter) );
				
			}			
			// Set the first element in curr_node equal to min_degree-th element 
			curr_node->keys->at(0) = curr_node->keys->at(min_degree);
			curr_node->num_keys = 1;
			
			// Set the curr_node's first and second pointers
			curr_node->child_ptrs->at(0) = left_child;
			curr_node->child_ptrs->at(1) = right_child;
			
			// Set the curr_node as no longer a leaf 
			curr_node->is_leaf = false;
			
		}
		
		
		void print_internal( std::ostream& out, const b_tree_node<T>* curr_node, int level ) const{
			
			// Dr. Morrison's Golden Rule of Pointers
			if( curr_node == NULL )
				return;
			
			for( int iter = 0; iter < curr_node->num_keys; ++iter ){
				
				print_internal( out, curr_node->child_ptrs->at(iter), level + 1 );
				
				out << "{Level: " << level << ", Value = " << curr_node->keys->at(iter) << "} ";
				
			}
			
			print_internal( out, curr_node->child_ptrs->at( curr_node->num_keys ), level + 1 );
		}
		
		
	public:
		b_tree( int max_degree_in ) : max_degree( max_degree_in ), root( NULL ) {}
		
		~b_tree(){
			
			// Dr. Morrison's Golden Rule of Pointers
			if( root != NULL )
				delete_tree( root );
			
		}
		
		b_tree( const b_tree<T>& copy ) : root( NULL ) {
			
			(void)copy;
			
		}
		
		b_tree<T>& operator=( const b_tree<T>& assign ){

			if( this != &assign ){}
				
			
			return *this;

		}			
		
		void insert( const T& elem ){
			
			if( root == NULL ){
				
				root = new b_tree_node<T>( max_degree, true );
				insert_non_full_leaf( root, elem );
				
				return;
			}
				
			insert( root, elem );
			
		}
		
		
		friend std::ostream& operator<<( std::ostream& out, const b_tree<T>* print_b_tree ){
			
			int level = 1;
			
			print_b_tree->print_internal( out, print_b_tree->root, level );
			
			return out;
			
		}
	
	
};



#endif