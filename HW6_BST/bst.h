//===============================================
// HW#: HW6P1 bst
// Name: Brian Vargas
// Compiler: g++
// File type: header file (bst.h)
//===============================================


//Node class for representing the nodes of the binary search tree
//holds information for the left child, right child, and value
class Node {
  //public attributes so we can access it within BST
  public:
    int key; //value associated with node			
    Node* left;	//pointer to left child
    Node* right; //pointer to right child
    //node constructor - initialize with a value and no children
    Node(int data)
    {
      key = data; 
      left = NULL; 
      right = NULL; 
    }
};


//binary search tree class - makes use of node class above
class BST {
  public:
   BST();	//empty constructor to create a BST object
   ~BST();	//destructor to destroy all nodes - called at end automatically
  
   //PURPOSE: Inserts data into the binary search tree
   //PARAMETER: The data value to be inserted
   void insert(int data);
  
   //PURPOSE: Inserts data value into correct node slot recursively
   //PARAMETERS: The root node of the current subtree we are on, 
   // and the value we are inserting 
   Node* insert(Node* node, int data);

   //PURPOSE: Searches for particular key in the binary search tree
   //PARAMETER: The value to be searched for
   Node* search(int key);

   //PURPOSE: Searches for particular key in the current subtree
   //PARAMETERS: The root node of the current subtree we are on,
   // and the value we are searching for in the current subtree
   Node* search(Node* node, int key);

   //PURPOSE: Removes the node with a particular value
   //PARAMETER: The value to be removed
   void remove(int key);

   //PURPOSE: Removes particular key in the current subtree
   //PARAMETER: The root node of the current subtree we are on,
   // and the value we are removing in the current subtree
   Node* remove(Node* node, int key);

   //PURPOSE: returns leftmost node of the current subtree
   //PARAMETER: The root node of the current subtree we are on
   Node* leftmostNode(Node* node);

   //PURPOSE: traveral through binary search tree in order
   // least to greatest
   void inorder();

   //PURPOSE: traverse through current subtree in order - printing
   // in least to greatest
   //PARAMETER: The root node of the current subtree we are on
   void inorder(Node* node);

  private:
   Node* root; //root node of the overall binary search tree
};


