#pragma once

template <typename T>
struct Color3 
{
	Color3(const T _R, const T _G, const T _B)
	{
		r = _R;
		g = _G;
		b = _B;
	}
	Color3()
	{
		r = 0;
		g = 0;
		b = 0;
	}

	T r, g, b;
	Color3<T> toPercentage()
	{
		Color3<T> perc;

		if (r != 0)
			perc.r = this->r / 255;
		if (g != 0)
			perc.g = this->g / 255;
		if (b != 0)
			perc.b = this->b / 255;

		return perc;
	}
};

typedef Color3<float> Color3f;
typedef Color3<double> Color3d;
typedef Color3<int> Color3i;


template <typename T>
struct Color4
{
	Color4(const T _R, const T _G, const T _B, const T _A)
	{
		r = _R;
		g = _G;
		b = _B;
		a = _A;
	}

	Color4()
	{
		r = 0;
		g = 0;
		b = 0;
		a = 0;
	}

	T r, g, b, a;
	Color4<T> toPercentage()
	{
		Color4<T> perc;

		if (r != 0)
			perc.r = this->r / 255;
		if (g != 0)
			perc.g = this->g / 255;
		if (b != 0)
			perc.b = this->b / 255;
		if (a != 0)
			perc.a = this->a / 255;

		return perc;
	}
};

typedef Color4<float> Color4f;
typedef Color4<double> Color4d;
typedef Color4<int> Color4i;