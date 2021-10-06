#ifndef ABAD_H
#define ABAD_H

#include<iostream> 
  
template<class T, class U> 
class A  { 

	private:
		T x; 
		U y; 

	public: 
		A(T inX, U inY);
		
		T getX() const;
		
		U getY() const;
		
		void setX(T inX);
		
		void setY(U inY);
		
		bool operator==(const A& rhs) const;
		
		friend std::ostream& operator<<(std::ostream& output, const A<T, U>& in){
			output << in.x << " " << in.y;
			return output;
		}
	
}; 

#endif
