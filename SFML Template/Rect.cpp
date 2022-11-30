#include "Rect.h"

template<typename T>
Rect<T>::Rect(const Vec2<T> _Position, const Vec2<T> _Size)
{
	position = _Position;
	size = _Size;
}


template<typename T>
Rect<T>::Rect()
{
	position = Vec2<T>(0, 0);
	size = Vec2<T>(0, 0);
}


template<typename T>
bool Rect<T>::contains(const Vec2<T> _Point)
{
	return false;
}


template<typename T>
bool Rect<T>::intersects(const Rect<T> _Rect)
{
	return false;
}
