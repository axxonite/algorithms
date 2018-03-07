// Copyright (c) 2015 Elements of Programming Interviews. All rights reserved.

#include "stdafx.h"

namespace Solutions
{
	class HeapStack
	{
	public:
		void Push( int x )
		{
			heap.emplace( Elem{ x, curTime++ } );
		}

		int Pop()
		{
			if ( heap.empty() )
				throw length_error( "" );
			auto elem = heap.top();
			heap.pop();
			return elem.value;
		}

		int Peek() const
		{
			if ( heap.empty() )
				throw length_error( "" );
			return heap.top().value;
		}

	private:
		struct Elem
		{
			int value;
			int timestamp;

			bool operator < ( const Elem& other ) const
			{
				return timestamp < other.timestamp;
			}
		};

		int curTime = 0;
		priority_queue<Elem, vector<Elem>> heap;
	};

	class HeapQueue
	{
	public:
		void Enqueue( int x )
		{
			heap.emplace( Elem{ x, curTime++ } );
		}

		int Dequeue()
		{
			if ( heap.empty() )
				throw length_error( "" );
			auto elem = heap.top();
			heap.pop();
			return elem.value;
		}

		int Head() const
		{
			if ( heap.empty() )
				throw length_error( "" );
			return heap.top().value;
		}

	private:
		struct Elem
		{
			int value;
			int timestamp;

			bool operator < ( const Elem& other ) const
			{
				return timestamp > other.timestamp;
			}
		};

		int curTime = 0;
		priority_queue<Elem, vector<Elem>> heap;

	};
}