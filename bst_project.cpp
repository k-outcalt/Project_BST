// Katherine Outcalt
// bst_project.cpp
// Version 1.5 8/25/2020

/* BST project: bst_project.cpp is the driver program for my Binary Search 
*  Tree project, which creates a Binary Search Tree (BST) 
*  and tests its methods with integer values. The tree stores an
*  integer as its data and its key. The keys are sorted on the tree from 
*  smallest to largest, and left to right. The program stores 25 random 
*  integers to the Tree and tests every public method, printing the results
*  to the console. The random numbers come from randomly generated numbers in
*  the infile called "bst_nums.txt"
*/

#include "tree.h"
#include <iostream>
#include <stack> 
#include <fstream>
using namespace std; 

int ARRAY_SIZE = 28; // size of the array, 28

int main()
{
  Tree myTree; 
  int treeArray[ARRAY_SIZE]; 
  ifstream fileHandle; 

  fileHandle.open("bst_nums.txt"); 

  if (fileHandle.fail()) {
    cout << "File failed to open." << endl; 
    return 0; 
  }

  for (int i = 0; i < (ARRAY_SIZE); i++) {
    fileHandle >> treeArray[i];
  }
  fileHandle.close(); 

  for (int i = 0; i < (ARRAY_SIZE); i++) {
    myTree.insert(treeArray[i]); 
  }

  cout << endl << "Welcome to the Binary Search Tree Project. " << endl; 
  cout << "Creating a Tree object called \"myTree\"..." << endl << endl; 

  cout << "Adding 28 random numbers to the tree, inserting 11 twice to test ";
  cout << endl << "duplicates. The tree should not add any duplicate numbers. "; 
  cout << endl;

  myTree.insert(11); // testing for duplicates 
  myTree.insert(11); 

  cout << "Printing postorder: " << endl; 
  myTree.postorder(); 
  cout << endl << endl; 

  cout << "Testing copy constructor with new Tree object called \"newTree\".";
  cout << endl << "myTree's data should be copied over to newTree." << endl;
  Tree newTree = myTree; 
  newTree.insert(55); 
  newTree.insert(56); 
  newTree.insert(57); 
  cout << "Adding 55, 56, and 57 to newTree..." << endl;
  cout << "Printing newTree "; 
  cout << "and myTree. newTree should have the three new values. " << endl; 
  cout << endl; 
  cout << "myTree (inorder): " << endl; 
  myTree.inorder(); 
  cout << endl << "newTree (inorder): " << endl; 
  newTree.inorder(); 
  cout << endl << endl; 

  cout << "Testing member function findKey(). Is 55 in myTree? "; 
  if (myTree.findKey(55)) 
    cout << "Yes. "; 
  else 
    cout << "Nope. "; 
  cout << endl << endl; 

  cout << "What about in newTree? "; 
  if (newTree.findKey(55)) 
    cout << "Yes. "; 
  else 
    cout << "Nope. "; 
  cout << endl << endl; 

  cout << "Testing printAnc... what are the ancestors for key 34? " << endl;
  cout << "The ancestors of printAnc should be 33, 21, 36, 14, and 47:\n";
  myTree.printAnc(34); 

  cout << "\nTesting to printAnc for a value that isn't on tree, 99."; 
  cout << endl << "Should not print anything:" << endl; 
  myTree.printAnc(99); 

  cout << endl << "Testing methods that return an integer... \n";
  cout << "myTree should have a height of 6, 8 leaves, and 7 full nodes.\n";
  cout << "Height: " << myTree.findHeight() << endl; 
  cout << "Leaves: " << myTree.countLeaves() << endl;
  cout << "Full nodes: " << myTree.countFull() << endl << endl; 

  cout << "newTree should have a height of 7, 9 leaves, and 8 full nodes.\n"; 
 cout << "Height: " << newTree.findHeight() << endl; 
  cout << "Leaves: " << newTree.countLeaves() << endl;
  cout << "Full nodes: " << newTree.countFull() << endl << endl; 

  cout << "Lastly, testing the overloaded assignment operator by assigning\n"; 
  cout << "newTree to myTree. myTree should have all of the same values as ";
  cout << "newTree." << endl << endl; 
  myTree = newTree; 
  cout << "Printing postorder. " << endl; 
  cout << "MyTree: " << endl; 
  myTree.postorder(); 
  cout << endl << "newTree: " << endl; 
  newTree.postorder(); 

  cout << endl << endl << "End of BST project. Goodbye!" << endl << endl; 

  return 0;
}
