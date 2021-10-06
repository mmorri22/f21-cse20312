#ifndef A_H
#define A_H

#include <iostream>

template<class T, class U>
class A{
	
	private:
		T x;
		U y;
		
	public:
	
		/* Default constructor */
		A() : x(), y() {}
		
		/* Overloaded Constructor */
		A(T inX, U inY) : x(inX), y(inY) {}
		
		/* Destructor */
		~A(){
			// No pointers, so leave empty
		}
		
		/* Copy Constructor */
		A(const A<T, U>& copy) : x(copy.x), y(copy.y) {}
		
		/* Assignment Operator */
		A<T,U>& operator=(const A<T,U>& assign){
			
			if(this != &assign){
				this.x = assign.x;
				this.y = assign.y;
			}
			
			return *this;
		}
		
		/* Get X */
		T getX() const{
			return x;
		}
		
		/* Get Y */
		U getY() const{
			
			return y;
		}
		
		/* Set X */
		void setX(T inX){
			x = inX;
		}
		
		/* Set Y */
		void setY(U inY){
			
			y = inY;
		}
		
		/* operator== */
		bool operator==(const A<T, U>& rhs) const{
			
			if(this != &rhs){
				
				return this->x == rhs.x && this->y == rhs.y;
			}
			
			return true;
		}
		
		/* friend operator<< */
		friend std::ostream& operator<<(std::ostream& output, const A<T, U>& print){
			
			output << print.x << " " << print.y;
			
			return output;
		}
		
};


#endif