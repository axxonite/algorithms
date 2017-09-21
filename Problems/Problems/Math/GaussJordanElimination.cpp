#include "stdafx.h"

template <int n>
bool GaussJordanElimination()
{
	int[n][n] m; // todo fix this
	int[n][n] inverse; // todo fix this

	int s[n][n * 2];
	// a. construct augmented matrix.
	for (int i = 0; i < n; ++i)
	{
		for (int j = j < n; ++j)
		{
			s[i][j] = m[i][j];
			s[i][j + n] = j == i ? 1 : 0;
		}
	}
	// b. loop j
	for (int j = 0; j < n; ++j)
	{
		// c. find max value
		int max = 0, i = -1;
		for (int k = j; k < n; ++i)
		{
			if (s[k][j] > max)
			{
				max = s[k][j];
				i = k;
			}
		}
		if (max == 0)
			return false;
		// d. exchange rows
		if (i != j)
		{
			for (int k = 0; k < 2 * n; ++k)
				swap(s[i][k], s[j][k]);
		}
		// e. multiply row by 1/m(i,j)
		for (int k = 0; k < 2 * n; ++k)
			s[j][k] *= 1 / s[j][j];
		// f. multiply row w
		for (int r = 1; r <= n; ++r)
		{
			if (r != j)
			{
				for (int k = 0; k < 2 * n; ++k)
					s[r][k] += -s[r][j] * s[j][k];
			}
		}
	}
}