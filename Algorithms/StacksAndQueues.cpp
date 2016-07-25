#include "stdafx.h"
#include "StacksAndQueues.h"
#include <memory>
#include <algorithm>
#include <stack>
#include <string>
#include <sstream>
#include <queue>
#include "BinaryTrees.h"

using namespace std;

// ----------------------------------------------------------
// 9.1 IMPLEMENT A STACK WITH MAX API*
//
// Internally, keep a parallel stack that tracks the max of the value stack at the moment each value is pushed. To minimize storage, include, for each entry in the max stack, over how many values the same max is valid.
class StackWithMax
{
	struct ElementWithMax
	{
		int element, max;
	};

public :

	bool Empty() const // Don't forget const.
	{
		return _stack.empty(); // Note the use of empty.
	}

	void Push(int elem)
	{
		// Don't forget that there may not be a top.
		auto maxValue = max(elem, Empty() ? elem : _stack.top().max);
		_stack.emplace(ElementWithMax{elem, maxValue}); // Note, don't do back.
	}

	int Pop()
	{
		if (Empty())
			throw length_error("Cannot pop from an empty stack");
		int element = _stack.top().element;
		_stack.pop();
		return element;
	}

	int Max()
	{
		return _stack.top().max;
	}

private :

	stack<ElementWithMax> _stack;
};

// ----------------------------------------------------------
// 9.2 EVALUATE RPN EXPRESSIONS
int EvaluateRPNexpression(const string& rpn)
{
	// Push values on the stack. When an operator is encountered, pop two values, evaluate them, then push the result. The top of the stack contains the final answer. O(n).
	return 0;
}

// ----------------------------------------------------------
// 9.3 TEST A STRING OVER "{,},(,),[,]," FOR WELL-FORMEDNESS
bool TestForWellFormedness(const string& s)
{
	// Iterate through the string, and push opening enclosures on a stack. When encountering a closing enclosure, check that the top of the stack has the corresponding opening enclosure. O(n).
	return false;
}


// ----------------------------------------------------------
// 9.4 NORMALIZE PATHNAMES* TRICKY
string NormalizePathName(const string& p)
{
	// If the string starts with /, record it on a stack. Split the string over /. If the token is .., there are three cases. If it's the first token or the previous token was .., then push ".."
	// If the last token was /, error out. Otherwise, pop the stack. 
	// If the token is not .., ignore . or empty tokens, otherwise push them on the stack. Finally, assembly the final answer from the stack, making sure to not interject a / if the token is /.
	if (p.empty())
		throw invalid_argument("Not a valid path"); // Notice the use of empty and invalid_argument.
	vector<string> components; // why use a vector as a stack? todo
	if (p.front() == '/')
		components.emplace_back("/"); // Special case if we start with /.

	stringstream ss(p); // Notice the use of a string stream.
	string token;
	while (getline(ss, token, '/')) // Notice the use of getline to split the string.
	{
		if (token == "..")
		{
			if (components.empty() || components.back() == "..") // Keep the .. tokens if they occur during the prefix of the string.
				components.emplace_back(token);
			else
			{
				if (components.back() == "/") // Can't have "/.." at the start of the string.
					throw invalid_argument("Invalid path.");
				components.pop_back(); // Perform with .. by popping the stack.
			}
		}
		else if (token != "." && token != "") // Need a name to add it to the path.
			components.emplace_back(token);
	}
	string result; // Watch for misnamed references.
	if (!components.empty())
	{
		result += components.front(); // First component has no prefix.
		for (size_t i = 1; i < components.size(); i++)
		{
			if (i == 1 && result == "/") // If we prepended with a / then we need to keep it as is.
				result += components[i];
			else result += "/" + components[i]; // Otherwise add / between components.
		}
	}
	return result;
}

void TestNormalizePathName()
{
	auto r = NormalizePathName("hello/there/how/are/you");
	assert(r == "hello/there/how/are/you");
	auto r2 = NormalizePathName("/hello/there/how/are/you");
	assert(r2 == "/hello/there/how/are/you");
	auto r3 = NormalizePathName("hello/./there/../../how/are/./you");
	assert(r3 == "how/are/you");
}

// ----------------------------------------------------------
// 9.5 SEARCHING A POSTINGS LIST
struct PostingListNode
{
	PostingListNode* jump;
	PostingListNode* next;
	int order;
};

void SearchPostingsList(const shared_ptr<PostingListNode>& l)
{
	// Iterate the nodes, pushing the next node and the jump node, then pop the next to process from the stack.
}

// ----------------------------------------------------------
// 9.6 COMPUTE BUILDINGS WITH A SUNSET VIEW **
struct BuildingWithHeight
{
	int id, height;
};

vector<int> ComputeBuildingsWithSunsetView(stringstream* sin)
{
	// We can make two observations: a new building change which existing buildings are obscured if it's smaller than the leftmost building, and buildings that are obscured do not change the obscuring of other smaller buildings
	// because they are themselves obscured by a taller building which obscures them all. This suggests that buildings in the solution will always have increasing heights from west to east, which forms a type of loop invariant.
	// If a new building comes in that is taller, and thus breaks the increasing heights invariant, than any buildings smaller than the new building must be removed from the solution set. Since the buildings in the existing 
	// solution set are in increasing order, the smaller ones are always going from west to east. This suggests the push/pop behavior of a stack: if a new building is taller than the top of the stack, pop the from the stack
	// any buildings smaller than the new building, then push the new building. This keeps the stack as a series increasing values with the smaller values at the front. O(n).
	int id = 0;
	int height;
	stack<BuildingWithHeight> buildings;
	while (*sin >> height)
	{
		while (!buildings.empty() && buildings.top().height <= height) // Watch for equal.
			buildings.pop();
		buildings.push(BuildingWithHeight{id++, height});
	}

	vector<int> result;
	while (!buildings.empty())
	{
		result.emplace_back(buildings.top().id);
		buildings.pop();
	}
	return result;
}

void TestComputeBuildingsWithSunsetView()
{
	stringstream b;
	b << "3 5 15 2 9 12";
	auto r = ComputeBuildingsWithSunsetView(&b);
	assert(r == vector<int>({5, 2}));
}

// ----------------------------------------------------------
// 9.7 COMPUTE BINARY TREE NODES IN ORDER OF DECREASING DEPTH *
struct BinaryTreeNode
{
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

vector<vector<int>> ComputeBinaryTreeDepthOrder(TreeNodePtr tree)
{
	// Initialize queue with root node. Process queue by popping node, storing it in a vector v and adding both children to the queue. When we have processed 2^d (d being the current depth), v contains a whole level and 
	// can be copied to the result. O(n).
	queue<TreeNodePtr> nodes;
	nodes.emplace(tree);
	vector<vector<int>> result;
	int n = 1;
	while (!nodes.empty())
	{
		vector<int> partial;
		if (n > 0) // watch out for adding an empty array.
		{
			int c = n;
			n = 0;
			for (int i = 0; i < c; i++)
			{
				auto node = nodes.front();
				partial.emplace_back(node->value);
				nodes.pop();
				if (node->left)
				{
					nodes.emplace(node->left);
					n++;
				}
				if (node->right)
				{
					nodes.emplace(node->right);
					n++;
				}
			}
			result.push_back(partial);
		}
	}
	return result;
}

void ComputeBinaryTreeDepthOrder()
{
	auto t = BuildBinaryTree(3);
	auto r = ComputeBinaryTreeDepthOrder(t);
	assert(r[0] == vector<int>({1}));
	assert(r[1] == vector<int>({2, 3}));
	assert(r[2] == vector<int>({4, 5, 6, 7}));
}

// ----------------------------------------------------------
// 9.8 IMPLEMENT A CIRCULAR QUEUE*
//
// Use a circular array and keep track of both the head and tail. Keep a count of the number of elements because an empty queue cannot be differentiated from a full one . Pay special attention to the
// resizing operation so that elements are still in their proper position after the resize operation.

// ----------------------------------------------------------
// 9.9 IMPLEMENT A QUEUE USING STACKS*
//
// Maintain a stack to enqueue to and a dequeue stacks. When we dequeue and the dequeue stack is empty, move the enqueue stack to an inverted version on the dequeue stack with push & pop.

// ----------------------------------------------------------
// 9.10 IMPLEMENT A QUEUE WITH MAX API*
// Maintain a deque m of max values in decreasing order. When dequeing a value x, pop m from the front if the front matches x. For enqueuing a value x, pop from m any values from the back that are < x, and push x at the back of m.

void TestStacksAndQueues()
{
	TestNormalizePathName();
	TestComputeBuildingsWithSunsetView();
	ComputeBinaryTreeDepthOrder();
}
