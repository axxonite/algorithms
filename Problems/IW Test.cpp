#include "stdafx.h"

#include <cstring>
#include <algorithm>
#include <xmmintrin.h>
#include <smmintrin.h>

// ====================================================================================================================
//
// CONTAINED WATER PROBLEM.
//

struct CellState
{
	int x, y, height;
	bool isBoundary;
	bool waterVolumeAccountedFor;
	bool isInBFSQueue;
};

void AddNeighborCellHelper(int x, int y, vector<vector<CellState>>& cellStates, queue<CellState*>& bfsQueue)
{
	// Helper function to add a neighboring cell to the BFS queue. We use a flag to make sure we
	// don't add a node to the queue if it's already on the queue.
	if (!cellStates[x][y].isInBFSQueue)
	{
		cellStates[x][y].isInBFSQueue = true;
		bfsQueue.emplace(&cellStates[x][y]);
	}
}

int CalcContainedWater(const int *p_data, int num_columns, int num_rows)
{
	// This algorithm is based on the following observations.
	// For the water to flow off the board, it has to "leak" from one of the grid cells
	// on the edge of the board. For a given "leaking" edge cell, any connected cells 
	// can be in one of two states.
	//
	// Let e be the leaking boundary cell on the edge of the board and n be one of its neighboring cells.
	// Either the height of n > the height of e, in which case any water sitting at n will flow 
	// into e, and n will also become a leaking conduit for any other higher cells around it.
	//
	// Otherwise, n's height is lower than e's height, which means that e forms a wall boundary 
	// sitting above n, and n can potentially contain a volume of water whose height will not be 
	// any higher then e's height.
	//
	// Though e being higher than n guarantees that the water level of e cannot rise past n,
	// n could be connected to multiple boundary cells, and n's water level can only rise to the
	// level of the lowest of the boundary cells to which its' connected. One way to ensure this,
	// is to make sure edge cells are always processed from the bottom, going up.

	// Keep a cell state for each cell on the grid. Copy the height data from the cell grid, along with
	// the cell's coordinates and flags to indicate which stages the cell has already passed 
	// through.
	vector<vector<CellState>> cellStates(num_columns, vector<CellState>(num_rows));
	for (int y = 0, i = 0; y < num_rows; ++y)
		for (int x = 0; x < num_columns; ++x, ++i)
			cellStates[x][y] = CellState{ x, y, p_data[i], x == 0 || y == 0 || x == num_columns - 1 || y == num_rows - 1, false };

	// We want to process the leaking boundary cells from bottom to top, as explained above. Use a min heap
	// to keep the boundary cells ordered.
	priority_queue<CellState*, vector<CellState*>, function<bool(CellState*, CellState*)>> boundaryCellsMinHeap([](const CellState* a, const CellState* b) { return a->height > b->height; });

	// Add all the boundary cells to a processing queue, ordered from the lowest height boundary cell to the
	// highest.
	for (int y = 0; y < num_rows; ++y)
	{
		boundaryCellsMinHeap.emplace(&cellStates[0][y]);
		boundaryCellsMinHeap.emplace(&cellStates[num_columns - 1][y]);
	}
	for (int x = 1; x < num_columns - 1; ++x)
	{
		boundaryCellsMinHeap.emplace(&cellStates[x][0]);
		boundaryCellsMinHeap.emplace(&cellStates[x][num_rows - 1]);
	}

	int waterVolume = 0;
	while (!boundaryCellsMinHeap.empty())
	{
		auto boundaryCell = boundaryCellsMinHeap.top();
		boundaryCellsMinHeap.pop();

		// Now that we have a boundary cell, we want to perform a breadth first search
		// starting from the boundary cell, with the search propagating until it hits a 
		// wall (that is, a neighboring cell that is higher than the boundary cell). 
		// We will categorize each cell during the search according to its height with
		// respect to the boundary cell.
		queue<CellState*> bfsQueue;
		bfsQueue.emplace(boundaryCell);
		boundaryCell->isInBFSQueue = true;
		while (!bfsQueue.empty())
		{
			auto current = bfsQueue.front();
			current->isInBFSQueue = false;
			bfsQueue.pop();
			if (current->height > boundaryCell->height)
			{
				// The neighbor cell is higher than the edge cell. That means this cell
				// can now act as boundary cell for any other cells beyond it.
				// Make sure we never add a node to the boundary cell min heap twice.
				if (!current->isBoundary)
				{
					current->isBoundary = true;
					boundaryCellsMinHeap.emplace(current);
				}
			}
			else
			{
				// Make sure we account for the water volume of a cell only once. A cell
				// could be reached from multiple boundaries at different heights so we want
				// to make sure only the first, lowest boundary reaching the cell will
				// be taken into account to calculate that cell's water volume.
				if (!current->waterVolumeAccountedFor)
				{
					current->waterVolumeAccountedFor = true;
					waterVolume += boundaryCell->height - current->height;
					// Add all valid neighboring cells to the search.
					if (current->x > 0)
						AddNeighborCellHelper(current->x - 1, current->y, cellStates, bfsQueue);
					if (current->x < num_columns - 1)
						AddNeighborCellHelper(current->x + 1, current->y, cellStates, bfsQueue);
					if (current->y > 0)
						AddNeighborCellHelper(current->x, current->y - 1, cellStates, bfsQueue);
					if (current->y < num_rows - 1)
						AddNeighborCellHelper(current->x, current->y + 1, cellStates, bfsQueue);
				}
			}
		}
	}
	return waterVolume;
}

void CalcContainedWaterTest()
{
	int* p_data = new int[3 * 5]{
		3, 3, 3, 3, 3,
		2, 1, 1, 1, 3,
		5, 5, 5, 5, 5
	};
	int result = CalcContainedWater(p_data, 5, 3);
	assert(result == 3);
	delete[] p_data;

	p_data = new int[3 * 5]{
		1, 1, 1, 1, 1,
		1, 0, 0, 0, 1,
		1, 1, 1, 1, 1,
	};
	result = CalcContainedWater(p_data, 5, 3);
	assert(result == 3);
	delete[] p_data;

	p_data = new int[3 * 3]{
		1, 0, 1,
		1, 0, 1,
		1, 1, 1
	};
	result = CalcContainedWater(p_data, 3, 3);
	assert(result == 0);
	delete[] p_data;

	p_data = new int[3 * 3]{
		0, 1, 0,
		1, 0, 1,
		0, 1, 0
	};
	result = CalcContainedWater(p_data, 3, 3);
	assert(result == 1);
	delete[] p_data;

	p_data = new int[5 * 5]{
		3, 2, 0, 4, 2,
		1, 1, 1, 0, 1,
		0, 2, 1, 1, 1,
		0, 0, 0, 1, 0,
		2, 1, 0, 1, 1
	};
	result = CalcContainedWater(p_data, 5, 5);
	assert(result == 1);
	delete[] p_data;

	p_data = new int[5 * 5]{
		5, 5, 5, 5, 5,
		5, 4, 4, 4, 5,
		5, 4, 3, 4, 5,
		5, 4, 4, 4, 5,
		5, 5, 5, 5, 5
	};
	result = CalcContainedWater(p_data, 5, 5);
	assert(result == 10);
	delete[] p_data;

	p_data = new int[5 * 5]{
		5, 5, 0, 5, 5,
		5, 4, 4, 4, 5,
		5, 4, 3, 4, 5,
		5, 4, 4, 4, 5,
		5, 5, 5, 5, 5
	};
	result = CalcContainedWater(p_data, 5, 5);
	assert(result == 1);
	delete[] p_data;
}

// ====================================================================================================================
//
// CODE DEBUG & OPTIMIZATION PROBLEM
//

// 4-element vector object.
struct SVector4
{
	float m_x;
	float m_y;
	float m_z;
	float m_w;
};

// Float-based shader parameter object.
struct SShaderFloatParameter
{
	float	m_value;
	char   *mp_name;
};

// The table of float-based shader parameters -
// typically 500+ entries - no duplicate names.
SShaderFloatParameter	*pShaderFloatParameterTable;
unsigned int		ShaderFloatParameterTableNumEntries;

void SetVectorParameterAsLargestDP(char *p_param_name,
	SVector4 *src1,
	SVector4 *src2,
	int num_vectors)
{
	// This function iterates over the incoming vectors and calculates
	// the 3-element dot product between each pair of vectors src1[n] and
	// src2[n]. The largest dot product calculated should be stored in the
	// table entry for the specific shader parameter which matches the
	// supplied name.
	
	// If we have no vectors, early out so we don't end up searching the 
	//parameter name table needlessly.
	if (num_vectors == 0)
		return;

	// Calculate the 3-element dot product, store it in our temp array.
	float biggest_dot_product = 0.0;
	for ( int i = 0; i < num_vectors; ++i)
	{
		// Use SSE 4.1 to perform the dot product.
		// I'm assuming an aligned address here, otherwise use _mm_loadu_ps.
		__m128 a = _mm_load_ps(&src1[i].m_x); 
		__m128 b = _mm_load_ps(&src2[i].m_x);
		// Use a mask to ensure a 3-component dot product.
		float dp = _mm_cvtss_f32(_mm_dp_ps(a, b, 0x71)); 
		biggest_dot_product = std::max(biggest_dot_product, dp);
	}

	// Find the named parameter so we can set the value.
	for (unsigned int p = 0; p < ShaderFloatParameterTableNumEntries; ++p)
	{
		if (strcmp(p_param_name, pShaderFloatParameterTable[p].mp_name) == 0)
		{
			// We found a match! Set the value.
			pShaderFloatParameterTable[p].m_value = biggest_dot_product;
			// The parameter names are distinct.
			// No need to continue iterating.
			break; 
		}
	}
}

// ====================================================================================================================
//
// GEOMETRY PROBLEMS
//

struct Vector
{
	float x, y, z;

	float Dot(const Vector&b) const
	{
		return x * b.x + y * b.y + z * b.z;
	}

	Vector operator + (const Vector& b) const
	{
		return { x + b.x, y + b.y, z + b.z };
	}
	Vector operator - (const Vector& b) const
	{
		return { x - b.x, y - b.y, z - b.z };
	}

	Vector Cross(const Vector& b ) const
	{
		return { y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x };
	}

	void Normalize()
	{
		float length = sqrt(x * x + y * y + z * z);
		x /= length, y /= length, z /= length;
	}

	Vector operator - () const
	{
		return { -x, -y, -z };
	}

};

static Vector operator * (float a, const Vector& b)
{
	return { a * b.x, a * b.y, a * b.z };
}

Vector Reflect(Vector& v, Vector& p, const Vector& n)
{
	Vector incident = v - p;
	return incident - 2.0f * incident.Dot(n) * n;
}

Vector Refract(Vector& v, Vector& p, const Vector& n, float refractionRatio)
{
	Vector incident = v - p;
	float k = 1.0f - refractionRatio * refractionRatio * (1.0f - n.Dot(incident) * n.Dot(incident));
	if (k < 0.0f)
		return{0, 0, 0};
	return refractionRatio * incident - (refractionRatio * n.Dot(incident) + sqrt(k)) * n;
}

struct Plane
{
	Vector normal;
	float distance;

	Plane(const Vector& a, const Vector&b, const Vector& c)
	{
		normal = (b - a).Cross(c - a);
		normal.Normalize();
		distance = -normal.Dot(a);
	}

	bool LiesOnPlane(const Vector& p) const
	{
		float d = abs(Distance(p));
		const float epsilon = 0.00001f;
		if (d > epsilon)
			return false;
		return true;
	}

	float Distance(const Vector& p) const
	{
		return normal.Dot(p) + distance;
	}
};

bool IsCoplanar(const vector<Vector>& points)
{
	Plane plane(points[0], points[1], points[2]);
	for (int i = 3; i < points.size(); ++i)
	{
		if (!plane.LiesOnPlane(points[i]))
			return false;
	}
	return true;
}


bool IsContained(const Vector& a, const Vector& b, const Vector& c, vector<Vector>& points)
{
	Plane plane(a, b, c);
	// build three planes perpendicular to the triangle, aligned with its edges.
	vector<Plane> planes;
	planes.emplace_back(Plane{ a, b, a + plane.normal });
	planes.emplace_back(Plane{ b, c, b + plane.normal });
	planes.emplace_back(Plane{ c, a, a + plane.normal });

	for (int i = 0; i < points.size(); ++i)
	{
		auto& p = points[i];
		if (!plane.LiesOnPlane(p))
			return false;
		if (planes[0].Distance(p) > 0)
			return false;
		if (planes[1].Distance(p) > 0)
			return false;
		if (planes[2].Distance(p) > 0)
			return false;
	}
	return true;
}

void IsContainedTest()
{
	vector<Vector> points;
	points.emplace_back(Vector{0.25, 0.25, 0.0});
	bool result = IsContained({ 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, points);
	points.clear();
	points.emplace_back(Vector{ 0.75, 0.75, 0.0 });
	bool result2 = IsContained({ 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, points);
	points.clear();
	points.emplace_back(Vector{ -0.75, -0.75, 0.0 });
	bool result3 = IsContained({ 0, 0, 0 }, { 1, 0, 0 }, { 0, 1, 0 }, points);
}

// ====================================================================================================================
//
// SUN SHADOWING PROBLEM
//

struct Point
{
	float x, y;
};

bool TestPoint(const vector<float>& heights, const vector<float> & yintercepts, float slope, Point p, bool sunComingFromRight)
{
	if (sunComingFromRight)
		p.x = heights.size() - p.x;
	if (p.x < 0)
		return false;
	int block = min(int(yintercepts.size()) - 1, int(p.x));
	float yintercept = yintercepts[block];
	float fracX = p.x - int(p.x);
	float shadowY = yintercept + fracX * slope;
	if (block < heights.size())
		shadowY = max(shadowY, heights[block]); // Point is within a block, which counts as shadowed.
	return shadowY >= p.y;
}

void ComputeSunShadowing(vector<float> heights, Point sunDirection, vector<Point> points, vector<bool>& result)
{
	if (sunDirection.y > 0)
	{
		// The sun is below the ground. Everything is in shadow.
		/// O(n) time complexity for this case.
		result.assign(points.size(), true);
	}
	else if (heights.size() == 0)
	{
		// There are no buildings. Nothing is in shadow.
		// O(n) time complexity for this case.
		result.assign(points.size(), false);
	}
	else if (sunDirection.x == 0)
	{
		// Sun direction is completely vertical.
		// Check whether points are lower than the building that they overlap.
		// O(n) time complexity for this case.
		for (int i = 0; i < points.size(); ++i)
			result.emplace_back(points[i].x >= 0.0f && int(points[i].x) < heights.size() && heights[int(points[i].x)] > 0 && heights[int(points[i].x)] >= points[i].y);
	}
	else
	{
		bool sunComingFromRight = sunDirection.x < 0;
		if (sunComingFromRight)
		{
			// Sun direction is going from the right - the algorithm expects a light direction from the left.
			// Flip the direction, reverse the order of the height data.
			sunDirection.x = -sunDirection.x;
			reverse(heights.begin(), heights.end());
		}
		if (sunDirection.y == 0)
		{
			// Sun direction is completely horizontal.
			// Track the height of the highest column starting from the left. Any points lower than this max height
			// are in shadow.
			// O(kn) time complexity in this case, where k is number of screen columns and n is number of points.
			vector<float> maxHeight;
			maxHeight.emplace_back(heights[0]);
			for (int i = 1; i < heights.size(); ++i)
				maxHeight.emplace_back(max(maxHeight[i - 1], heights[i]));
			for (int i = 0; i < points.size(); ++i)
			{
				int block = min(int(maxHeight.size() - 1), int(points[i].x));
				result.emplace_back(points[i].x >= 0 && maxHeight[block] > 0 && maxHeight[block] >= points[i].y);
			}
		}
		else
		{
			// The sun direction is coming at an angle.
			// The insight here is that we can subdivide the screen into columns that are the width of one height
			// field column. For any given column, there are a number of column on the left that can cast a shadow
			// on the current column. One of the columns on the left will be casting a taller and longer shadow
			// than the others, and this is the only column we need to consider, for any point that is located
			// within that column.
			//
			//  =\
			// == \
			// === \
			// ==== \
			//      * <-- for any point lying above this column, we only need to consider the tallest shadow 
			//            overlapping the column, even when multiple shadows overlap the column.
			//
			// This algorithm relies on preprocessing to find, for each column on the screen, the y-intercept
			// of the tallest shadow that intersects that column. This values is always the same for a given set
			// of height data and a given sun direction, thus if our sun's direction doesn't change every frame,
			// we can precalculate this table and reuse it for several frames.
			//
			// The time to build the y-intercept table is O(k) where k is the number of columns on the screen.
			// The time to test the points is O(n) where n is the number of points.
			//
			// If the sun direction changes every frame, the time complexity of O(k + n) is smaller
			// than the O(n*k) we would get for a brute force algorithm that checks every building with every point.
			// If the sun direction is fixed, the time complexity is O(n).
			float slope = sunDirection.y / sunDirection.x;
			vector<float> yintercepts;
			yintercepts.emplace_back(0.0f); // there is no shadow cast on the first column.
			float largestXIntercept = 0.0f;
			for (int i = 0; i < heights.size(); ++i)
			{
				float xintercept = i - heights[i] / slope;
				// The largest x-intercept is the tallest shadow we have seen thus far.
				largestXIntercept = max(xintercept, largestXIntercept);
				// Compute y-intercept with the current building's right side, from the x-intercept.
				// The y-intercept may be negative, which implies there is no building shadowing this area.
				yintercepts.emplace_back((largestXIntercept - i) * -slope);
			}
			for (int i = 0; i < points.size(); ++i)
				result.emplace_back(TestPoint(heights, yintercepts, slope, points[i], sunComingFromRight));
		}
	}
}

// IMPORTANT: This brute force solutions is only here as a reference solution that we can test the more optimal solution above with.
bool TestPointBruteForce(const vector<float>& heights, float slope, const Point& p)
{
	for (int j = 0; j < heights.size() && j <= p.x; ++j)
	{
		float shadowY = heights[j] + slope * (p.x - j - 1);
		if (int(p.x) == j)
			shadowY = heights[j];
		if (shadowY >= p.y)
			return true;
	}
	return false;
}

// IMPORTANT: This brute force solutions is only here as a reference solution that we can test the more optimal solution above with.
void ComputeSunShadowingBruteForce(vector<float> heights, Point sunDirection, vector<Point> points, vector<bool>& result)
{
	if (sunDirection.y > 0)
	{
		result.assign(points.size(), true);
	}
	else if (sunDirection.x != 0)
	{
		if (sunDirection.x < 0)
		{
			sunDirection.x = -sunDirection.x;
			reverse(heights.begin(), heights.end());
			for (int i = 0; i < points.size(); ++i)
				points[i].x = heights.size() - points[i].x;
		}
		float slope = sunDirection.y / sunDirection.x;
		for (int i = 0; i < points.size(); ++i)
			result.emplace_back(TestPointBruteForce(heights, slope, points[i]));
	}
	else
	{
		for (int i = 0; i < points.size(); ++i)
			result.emplace_back(points[i].x >= 0 && points[i].x < heights.size() && heights[int(points[i].x)] > 0 && heights[int(points[i].x)] >= points[i].y);
	}
}

void ComputeSunShadowingTest()
{
	vector<bool> result;
	ComputeSunShadowingBruteForce({ 5, 0, 0, 0, 0, 0 }, Point{ 1, -1 }, { { 0, 5 },{ 1, 5 },{ 3.0, 3.5 },{ 3.0, 3.0 },{ 3.0, 2.5 },{ 5.0, 1.0 },{ 5.0, 0.0 },{ 6.0, 6.0 } }, result);
	vector<bool> reference = { true, true, false, true, true, true, true, false };
	assert(result == reference);
	result.clear();
	ComputeSunShadowingBruteForce({ 0, 0, 0, 0, 0, 5 }, Point{ -1, -1 }, { { 0, 5 },{ 1, 5 },{ 3.0, 3.5 },{ 3.0, 3.0 },{ 3.0, 2.5 },{ 5.0, 1.0 },{ 5.0, 0.0 },{ 6.0, 6.0 } }, result);
	reference = { false, false, false, true, true, true, true, false };
	assert(result == reference);
	result.clear();
	ComputeSunShadowingBruteForce({ 5, 0, 0, 0, 0, 0 }, Point{ 0, -1 }, { { 0, 5 },{ 1, 5 },{ 3.0, 3.5 },{ 3.0, 3.0 },{ 3.0, 2.5 },{ 5.0, 1.0 },{ 5.0, 0.0 },{ 6.0, 6.0 } }, result);
	reference = { true, false, false, false, false, false, false, false };
	assert(result == reference);

	result.clear();
	ComputeSunShadowing({ 5, 0, 0, 0, 0, 0 }, Point{ 1, -1 }, { { 0, 5 },{ 1, 5 },{ 3.0, 3.5 },{ 3.0, 3.0 },{ 3.0, 2.5 },{ 5.0, 1.0 },{ 5.0, 0.0 },{ 6.0, 6.0 } }, result);
	reference = { true, true, false, true, true, true, true, false };
	assert(result == reference);
	result.clear();
	ComputeSunShadowing({ 5, 0, 0, 0, 0, 0 }, Point{ 0, -1 }, { { 0, 5 },{ 1, 5 },{ 3.0, 3.5 },{ 3.0, 3.0 },{ 3.0, 2.5 },{ 5.0, 1.0 },{ 5.0, 0.0 },{ 6.0, 6.0 } }, result);
	reference = { true, false, false, false, false, false, false, false };
	assert(result == reference);

	default_random_engine seed((random_device())());
	for (int i = 0; i < 1000; ++i)
	{
		vector<float> heights;
		vector<Point> points;
		int n = uniform_int_distribution<int>{ 0, 100 }(seed);
		for (int j = 0; j < n; ++j)
			heights.emplace_back(uniform_real_distribution<float>{0, 100}(seed));
		int p = uniform_int_distribution<int>{ 0, 10 }(seed);
		p = 1;
		for (int j = 0; j < p; ++j)
			points.emplace_back(Point{ uniform_real_distribution<float>{0.0, float(n + 1)}(seed), uniform_real_distribution<float>{0.0, 100.0}(seed) });
		Point direction = Point{ uniform_real_distribution<float>{ -1.0, 1.0 }(seed), uniform_real_distribution<float>{ -1.0, 1.0 }(seed) };
		result.clear();
		ComputeSunShadowingBruteForce(heights, direction, points, result);
		vector<bool> result2;
		ComputeSunShadowing(heights, direction, points, result2);
		if (result != result2)
		{
			assert(false);
		}

		direction = Point{ 0.0, uniform_real_distribution<float>{ -1.0, 0.0 }(seed) };
		result.clear();
		ComputeSunShadowingBruteForce(heights, direction, points, result);
		result2.clear();
		ComputeSunShadowing(heights, direction, points, result2);
		if (result != result2)
		{
			assert(false);
		}

		direction = Point{ uniform_real_distribution<float>{ 0.0, 1.0 }(seed), 0.0 };
		result.clear();
		ComputeSunShadowingBruteForce(heights, direction, points, result);
		result2.clear();
		ComputeSunShadowing(heights, direction, points, result2);
		if (result != result2)
		{
			assert(false);
		}
	}
}
