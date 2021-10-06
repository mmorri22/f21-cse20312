#include "Abad.h"

template<class T, class U>
A<T, U>::A(T inX, U inY) : x(inX), y(inY) {}

template<class T, class U>
T A<T, U>::getX() const{
	return x;
}

template<class T, class U>
U A<T, U>::getY() const{
	return y;
}

template<class T, class U>
void A<T, U>::setX(T inX){
	x = inX;
}

template<class T, class U>
void A<T, U>::setY(U inY){
	y = inY;
}

template<class T, class U>
bool A<T, U>::operator==(const A<T, U>& rhs) const{
	if(x == rhs.x && y == rhs.y)
		return true;
	return false;
}


