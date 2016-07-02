#include "stdafx.h"
#include "StacksAndQueues.h"
#include <memory>

using namespace std;

// ----------------------------------------------------------
// 9.1 IMPLEMENT A STACK WITH MAX API
//
// Store the max value whenever a value is pushed unto the stack. Keep another stack structure inside the stack class to track the max value for each entry in the stack. If the max doesn't change after pushing a new value, 
// i.e. there are duplicate values in the max stack, reduce storage for them by storing over how many values the max remains the same.

// ----------------------------------------------------------
// 9.2 EVALUATE RPN EXPRESSIONS
int EvaluateRPNexpression(const string& rpn)
{
	// Push the values unto the stack. When an operator is encountered, pop two values from stack, evaluate them, then pop the result in the stack. The stack contains the answer at the end. O(n).
	return 0;
}

// ----------------------------------------------------------
// 9.3 TEST A STRING OVER "{,},(,),[,]," FOR WELL-FORMEDNESS
bool TestForWellFormedness(const string& s)
{
	// Iterate through the string, and push opening enclosures on a stack. When encountering a closing enclosure, check that the last value on the stack matches. O(n).
	return false;
}

// ----------------------------------------------------------
// 9.4 NORMALIZE PATHNAMES *
string NormalizePathName(const string& path)
{
	// Split the string over /, and examine each component. If it's ., ignore it. If it's .., pop a component from the stack. Otherwise, record the component in the stack. The final state of the stack is the normalized path.
	// Special care must be taken to handle edge cases. If the string begins with / then it's an absolute path and we cannot go up from it. If the string begins with .., we need to record it in the stack. O(n).
	return string();
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
	// In the trivial case, we would simply iterate through the nodes, and recursively process their jump node. This can be mimicked with a stack, pushing the next node and the jump node on the stack, then popping the next node
	// to process from the stack.
}

// ----------------------------------------------------------
// 9.6 COMPUTE BUILDINGS WITH A SUNSET VIEW **
vector<int> ComputeBuildingsWithSunsetView(istringstream* sin)
{
	// We can make two observations: a new building change which existing buildings are obscured if it's smaller than the leftmost building, and buildings that are obscured do not change the obscuring of other smaller buildings
	// because they are themselves obscured by a taller building which obscures them all. This suggests that buildings in the solution will always have increasing heights from west to east, which forms a type of loop invariant.
	// If a new building comes in that is taller, and thus breaks the increasing heights invariant, than any buildings smaller than the new building must be removed from the solution set. Since the buildings in the existing 
	// solution set are in increasing order, the smaller ones are always going from west to east. This suggests the push/pop behavior of a stack: if a new building is taller than the top of the stack, pop the from the stack
	// any buildings smaller than the new building, then push the new building. This keeps the stack as a series increasing values with the smaller values at the front. O(n).
	return vector<int>();
}

// ----------------------------------------------------------
// 9.7 COMPUTE BINARY TREE NODES IN ORDER OF DECREASING DEPTH *
struct BinaryTreeNode
{
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

vector<vector<int>> ComputeBinaryTreeDepthOrder(const unique_ptr<BinaryTreeNode>& tree)
{
	// Use a processing queue to direct the order of processing. Start with the root node, add it to the result list, then add both children to the queue. The queue now contains the solution for the next level. Now process
	// queue, adding immediate children. The queue now contains the children at the deeper level, which can be added to the solution. Keep track of the current depth, and when we we've processed 2^k (k being the depth),
	// the queue now contains the solution for the current depth. O(n).
	return vector<vector<int>>();
}

// ----------------------------------------------------------
 // 9.8 IMPLEMENT A CIRCULAR QUEUE
//
// Use a circular array and keep track of both the head and the tail. An empty queue cannot be differentiated from a full one, so make sure to keep a separate count of the number of elements. Pay special attention to the
// resizing operation so that elements are still in a proper position after the resize operation.

// ----------------------------------------------------------
// 9.9 IMPLEMENT A QUEUE USING STACKS
//
// Keep two stacks. The first is normal stack for enqueue. When we need to dequeue, use push and pop to created an inverted version of the first stack on the second stack. Then we can dequeue those elements until the
// dequeuing stack is empty, at which point we can create an inverted version of the first stack again.

// ----------------------------------------------------------
// 9.10 IMPLEMENT A QUEUE WITH MAX API
// If there is a max value at i0 and the next max value is at i1, then all values between i0 and i1 are irrelevant and will not change the max. We use a deque to store these descending max values.
// When then current max value is dequeued, it is also dequeued from the deque. When a new value is enqueued, it is compared with the back of the dequeue. If the new value is greater than the back of the deque,
// then the deque is dequeued from the back; further values that are smaller than the new value are dequeued as well. The max value is then enqueued from the back.