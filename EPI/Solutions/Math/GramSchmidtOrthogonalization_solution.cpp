#include "stdafx.h"
#include "Problems/Math/VectorN.h"

template <int n>
void GramSchmidtOrthogonalization(Vector<n>* b, Vector<n>* result)
{
	for (int i = 0; i < n; ++i)
	{
		result[i] = b[i]; // Start with the original vector
		for (int j = 0; j < i; ++j)
			// A perpendicular vector between u and v is found by projection u unto v and subtracting that from u.
      // Replace u and v by u = b[i] and v = result[j].
      // In essence, we are projecting the given vector against all other vectors in the basis and subtracting that from the result so that we end up with a vector that is perpendicular to all prior basis vectors.
			result[i] -= b[i].ProjectUnto(result[j]);
	}
}