#include "stdafx.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class SkipList {
public:

  SkipList();
  ~SkipList();

  void print() const;

  const string& find(int searchKey) const;
  void insert(int searchKey, const string& newValue) const;
  void erase(int searchKey) const;

private:

  struct Node {
    int key;
    string value;

    vector<Node*> lanes;

    Node(int k, string v, int level) :
      key(k), value(move(v)), lanes(level, nullptr)
    {}
  };

  // Returns number of incoming and outgoing pointers
  static int nodeLevel(const Node* v);

  vector<Node*> predecessors(int searchKey) const;

  // data members 
  const float probability;
  const int maxLevel;
  Node* head; // pointer to first node
  Node* NIL;  // last node
};


//==============================================================================
// Class SkipList member implementations

SkipList::SkipList() :
  probability(0.5),
  maxLevel(16)
{
  head = new Node(numeric_limits<int>::min(), "head", maxLevel);
  NIL = new Node(numeric_limits<int>::max(), "NIL", maxLevel);
  fill(head->lanes.begin(), head->lanes.end(), NIL);
}

SkipList::~SkipList() {
  auto node = head;
  while (node->lanes[0]) {
    auto tmp = node;
    node = node->lanes[0];
    delete tmp;
  }
  delete node;
}

const string& SkipList::find(int searchKey) const {
  Node* node = head;
  // don't think I want the lanes to be ordered this way.
  // go over each lane, skip to next lane as long as we are not at the key. 
  for (int i = head->lanes.size() - 1; i >= 0; --i)
    while (node->lanes[i]->key < searchKey)
      node = node->lanes[i];

  // we should always end up in the bottom lane, at 0.
  auto resultNode = node->lanes.front();
  if (resultNode && resultNode->key == searchKey && resultNode != NIL)
   return resultNode->value;
  throw invalid_argument("");
}

void SkipList::insert(int searchKey, const string& newValue) const
{
  auto preds = predecessors(searchKey);

  // reassign value if node exists and return
  auto next = preds[0]->lanes[0];
  if (next->key == searchKey && next != NIL) {
    next->value = newValue;
    return;
  }

  // create new node
  int newNodeLevel = 1;
  while (((double)rand() / RAND_MAX) < probability && newNodeLevel < maxLevel)
    newNodeLevel++;
  auto newNodePtr = new Node(searchKey, newValue, newNodeLevel);

  // connect pointers of predecessors and new node to respective successors
  for (int i = 0; i < newNodeLevel; ++i) {
    newNodePtr->lanes[i] = preds[i]->lanes[i]; // connect node at each level with a node that is > key?
    preds[i]->lanes[i] = newNodePtr;
  }
}

void SkipList::erase(int searchKey) const
{
  auto preds = predecessors(searchKey);

  //check if the node exists
  auto node = preds[0]->lanes[0];
  if (node->key != searchKey || node == NIL)
    return;

  // update pointers and delete node 
  for (size_t i = 0; i < nodeLevel(node); ++i)
    preds[i]->lanes[i] = node->lanes[i];
  delete node;
}

int SkipList::nodeLevel(const Node* v) {
  return v->lanes.size();
}

/*
* Returns a collection of Pointers to Nodes
* result[i] hold the last node of level i+1 for which result[i]->key < searchKey is true
*/
vector<SkipList::Node*> SkipList::predecessors(int searchKey) const {
  vector<Node*> result(nodeLevel(head), nullptr);
  Node* node = head;
  // gather up all nodes that are >= to the key on each level.
  // why is this called predecessors?
  for (int i = head->lanes.size() - 1; i >= 0; --i) {
    while (node->lanes[i]->key < searchKey)
      node = node->lanes[i];
    result[i] = node;
  }
  return result;
}

void SkipList::print() const {
  Node* list = head->lanes.front();
  int lineLenght = 0;

  cout << "{";
  while (list != NIL)
  {
    cout << "value: " << list->value << ", key: " << list->key << ", level: " << nodeLevel(list);
    list = list->lanes.front();
    if (list != NIL)
      cout << " : ";
    if (++lineLenght % 2 == 0)
      cout << "\n";
  }
  cout << "}\n";
}

#if 0
//==================================================
int main() {

  // 1.Initialize an empty SkipList object
  SkipList s;

  // 2. insert()
  for (int i = 0; i < 50; ++i) {
    stringstream ss;
    ss << i;

    s.insert(i, ss.str());
  }

  // 2a. print()
  s.print();
  cout << endl;

  // 3. find()        
  auto f = s.find(10);
  if (f) cout << "Node found!\nvalue: " << f << '\n';
  else cout << "Node NOT found!\n";

  // 4. insert() - reassign
  s.insert(40, "TEST");

  // 4a. print()
  s.print();
  cout << endl;

  // 5. erase()
  s.erase(40);

  // 5a. print();
  s.print();
  cout << endl;

  cout << "\nDone!\n";
  getchar();
}
#endif