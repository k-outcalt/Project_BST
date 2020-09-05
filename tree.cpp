// Katherine Outcalt
// tree.cpp
// 2.12.2020

/* tree.cpp is the implementation file for Tree class. Tree.cpp includes
*  tree.h and contains the methods for the class.
*/

#include "tree.h"
#include <iomanip>
#include <iostream>
#include <stack>
using namespace std;

Tree::Tree()
{
  root = nullptr;
}

Tree::~Tree()
{
  deleteAll(root);
}

Tree::Tree(const Tree& orig)
{
  if (orig.root == nullptr)
    root = nullptr; 
  else {
    root = makeCopy(orig.root); 
  }
}

Tree& Tree::operator=(const Tree& orig)
{
  if (this != &orig) {
    deleteAll(root); 
    root = makeCopy(orig.root); 
  }
  return *this; 
}

bool Tree::isEmpty() const
{
  return root == nullptr;
}

void Tree::deleteAll(TreeNode* &r) // private method
{
  if (r != nullptr) {
    deleteAll(r->left);
    deleteAll(r->right);
    delete r;
    r = nullptr;
  }
}

void Tree::insert(int k) // public method 
{
  insert(root, k); 
}

void Tree::insert(TreeNode* &r, int k) // private method
{
  if (r == nullptr) { // then insert
    r = new TreeNode; 
    r->key = k; 
    r->left = nullptr;
    r->right = nullptr;
    return; 
  }
  else {
    if (r->key == k)
      return; // it's a duplicate
    else if (k < r->key)
      insert(r->left, k);
    else if (k > r->key)
      insert(r->right, k);
  }
}

void Tree::postorder() // public method
{
  postorder(root); 
}

void Tree::postorder(TreeNode* r) // private method
{
  if (r != nullptr) {
    postorder(r->left); 
    postorder(r->right); 
    cout << r->key << " "; 
  }
}

void Tree::inorder() // public method
{
  inorder(root); 
}

void Tree::inorder(TreeNode* r) // private method
{
  stack<TreeNode*> s; 
  TreeNode* current = r; 

  while (current != nullptr || !s.empty()) {
    if (current != nullptr) {
      s.push(current); 
      current = current->left; 
    }
    else {
      current = s.top(); 
      s.pop(); 
      cout << current->key << " "; 
      current = current->right; 
    } 
  }
}

Tree::TreeNode* Tree::makeCopy(TreeNode* r) // private method
{
  if (r == nullptr) {
    return nullptr; 
  }
  else {
    TreeNode* tempNode = new TreeNode; 
    tempNode->key = r->key; 
    tempNode->left = makeCopy(r->left); 
    tempNode->right = makeCopy(r->right); 
    return tempNode; 
  }
}

bool Tree::findKey(int k) // public method
{ 
  return findKey(root, k); 
}

bool Tree::findKey(TreeNode* r, int k) // private method
{
  if (r == nullptr) 
    return false; 
  else if (r->key == k)
    return true; 
  else if (r->key > k) // checks which direction to search next
    return findKey(r->left, k);
  else 
    return findKey(r->right, k); 
}

void Tree::printAnc(int k) // public method 
{
  bool done = false;
  printAnc(root, k, done); 
}

void Tree::printAnc(TreeNode* r, int k, bool& done) // private method
{
  if (r != nullptr && !done) {
    if (r->key > k)
      printAnc(r->left, k, done); 
    else if (r->key < k)
      printAnc(r->right, k, done); 
    else // r->key == k 
      done = true; 
    }
  if (done)
    cout << r->key << " "; 
}

int Tree::countLeaves() // public method
{
  return countLeaves(root); 
}

int Tree::countLeaves(TreeNode* r) // private method
{
  if (r == nullptr) // no children and is a leaf
    return 0; 
  else {
    if (r->left == nullptr && r->right == nullptr) 
      return 1; 
    else 
      return (countLeaves(r->left) + countLeaves(r->right)); 
  }
}

int Tree::countFull() // public method 
{
  return countFull(root); 
}

int Tree::countFull(TreeNode* r) // private method
{
  if (r == nullptr)
    return 0; 
  else {
    if (r->left != nullptr && r->right != nullptr) 
      return (1 + countFull(r->left) + countFull(r->right));
    else 
      return (countFull(r->left) + countFull(r->right));
  }
}

int Tree::findHeight() // public method
{
  return findHeight(root); 
}

int Tree::findHeight(TreeNode* r) // private method
{
  if (r == nullptr) 
    return 0; 
  else {
    int leftH = findHeight(r->left); 
    int rightH = findHeight(r->right); 
    if (leftH > rightH)
      return (leftH + 1); 
    else 
      return (rightH + 1); 
  }
}
