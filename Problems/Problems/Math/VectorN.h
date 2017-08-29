#pragma once

template <int n>
class Vector
{
public:

	double v[n];

	Vector<n> operator -(const Vector<n>& b) const
	{
		Vector<n> result;
		for (int i = 0; i < n; ++i)
			result = v[i] - b[i];
		return result;
	}

	Vector<n> operator +(const Vector<n>& b) const
	{
		Vector<n> result;
		for (int i = 0; i < n; ++i)
			result = v[i] + b[i];
		return result;
	}

	double Dot(const Vector<n>& b) const
	{
		double result = 0.0;
		for (int i = 0; i < n; ++i)
			result += v[i] * b[i];
		return result;
	}

	Vector<n> ProjectUnto(const Vector<n>& b) const
	{
		return (Dot(b) / b.Dot(b)) * b;
	}
};

template <int n>
static Vector<n> operator *(double a, const Vector<n>& b)
{
	Vector<n> result;
	for (int i = 0; i < n; ++i)
		result = a * b.v[i];
	return result;
}