## Project_BST
 Binary Search Tree in C++ 

About the project
-----------------
I programmed a Binary Search Tree (BST) class and driver to store and retrieve data with dynamic memory. I used a .h header file and .cpp implementation file for reusability and encapsulation. 

What is a BST?
--------------
A BST is used to store data, often integers, in an organized fashion. Every BST has one root node with a particular value, and nodes with greater values are placed on the right and nodes with lesser values are placed on the left. For example, if 6 was the value of my root node, then new nodes with values of 2 and 8 would then be stored on the left and right, respectively. As more nodes are added, they are also placed appropriately by going to the right or left of their prior root, or "parent" node. BSTs are used because it allows for faster searching compared to an array or list where you must start at the beginning; with a BST you can start in the relative middle (the root) and eliminate search space. (The image below shows the BST for this program.)

Details
-------
The class uses dynamically allocated nodes with pointers to the left and right children for storage flexibility. In the driver program, I generated random unsigned integers on a .txt file so I could test expected results from printing functions (preorder, postorder, inorder, ancestors, etc.). The main() function reads in these values and inserts them to the BST object, and the rest of the program tests the functions. 

How to run the project
----------------------
* If you have an IDE (like Visual Studio Code, CLion, etc.) that can compile .cpp files, then:
* Download the tree.h, tree.cpp, bst_project.cpp, and bst_nums.txt to the same folder on your device
* Open up the folder in the IDE and run, or
* Go to the terminal and change directory until you get to the folder 
 * Type `cd "folder_name"` to navigate terminal
* Compile and run the files from there
 * To compile, type: `g++ bst_project.cpp tree.cpp`
 * Once compile, type: `./a.out` to see what was printed on the console
 
 ![Image of the BST]
 (https://raw.githubusercontent.com/k-outcalt/Project_BST/blob/master/bst_visual.pdf)
 
