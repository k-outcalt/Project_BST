// Katherine Outcalt
// tree.h
// 2.12.2020

/* tree.h is the header file for the Binary Search Tree (BST) classs. The BST
*  stores data/keys as integers, organized from left to right in ascending
*  order. Some public methods include inserting a value, finding a key,
*  various printing methods of the nodes (preorder, postorder, and inorder),
*  and counting all of nodes in the tree. Tree.h includes the STL Stack to help
*  with the inorder() printing method. 
*/
 
#ifndef TREE_H
#define TREE_H

#include <stack>
#include <iostream>
using namespace std;

class Tree
{
 public:
  Tree();
  // default constructor
  Tree(const Tree& orig);
  // copy constructor
  Tree& operator=(const Tree& orig);
  // overloaded assignment operator
  ~Tree();
  // destructor
  void insert(int k);
  // insert inserts a new key in the tree, if not a duplicate
  // post: Tree instance may not be empty
  bool findKey(int k);
  // findKey returns a boolean value if the key "k" is present in the tree
  void printAnc(int k);
  // printAnc prints the ancestors on the way to finding the key "k"
  // post: may not print anything if key "k" is not found
  int findHeight();
  // findHeight returns an integer of the height of the tree, meaning it counts
  // all of the levels of the tree
  void postorder();
  // postorder prints all of the key values of the tree, starting from the
  // leaves and finishing at the root of the tree
  void inorder();
  // inorder prints the key values of the tree in ascending numerical order
  int countLeaves();
  // returns an integer of the number of leaves in the tree-- meaning the
  // number of nodes without children
  int countFull();
  // returns an integer of the number of full nodes in the tree-- full meaning
  // that each node has two children



 private:
  struct TreeNode {
    int key; // the value to be stored in each node
    TreeNode* left; // Tree pointer to the node to the left
    TreeNode* right; // Tree pointer to the node to the left
  };
  TreeNode* root; // root of the tree, all nodes accessed from here

  bool isEmpty() const;
  // returns a boolean whether or not tree is empty
  void deleteAll(TreeNode* &r);
  // deletes all of the nodes in the tree
  TreeNode* makeCopy(TreeNode* r); 
  // copy function used in CC and OAO 
  void insert(TreeNode* &r, int k);
  // helper function for insert
  void inorder(TreeNode* r); 
  // helper function for inorder
  void postorder(TreeNode* r);
  // helper function for postorder
  bool findKey(TreeNode* r, int k);
  // helper function for findKey
  int findHeight(TreeNode* r);
  // helper function
  void printAnc(TreeNode* r, int k, bool& done); 
  // helper function for printAnc
  int countLeaves(TreeNode* r); 
  // helper function for countLeaves
  int countFull(TreeNode* r); 
  // helper function for countFull 

};

#endif
