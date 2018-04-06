#include "stdafx.h"
#include "Problems/Math/VectorN.h"

template <int n>
void GramSchmidtOrthogonalization(Vector<n>* b, Vector<n>* result)
{
	for (int i = 0; i < n; ++i)
	{
		result[i] = b[i];
		for (int j = 0; j < i; ++j)
			// We must project the current basis vector unto all the vectors we've found before.
			result[i] -= b[i].ProjectUnto(result[j]);
	}
}