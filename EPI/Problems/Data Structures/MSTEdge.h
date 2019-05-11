#pragma once

template <class T>
struct MSTEdge
{
	T* src;
	T* dest;
	int weight;

	bool operator == (const MSTEdge<T>& rhs ) const
	{
		return src->name == rhs.src->name && dest->name == rhs.dest->name && weight == rhs.weight;
	}
};