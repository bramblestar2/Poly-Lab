#include "Rect.h"

template<typename T>
Rect<T>::Rect(const Vec2<T> _Position, const Vec2<T> _Size)
{
	position = _Position;
	size = _Size;
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

template<typename T>
T Rect<T>::right()
{
	return (T)(position.x + size.x);
}

template<typename T>
T Rect<T>::bottom()
{
	return (T)(position.y + size.y);
}
