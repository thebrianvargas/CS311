//===============================================
// HW#: HW6P1 bst
// Name: Brian Vargas
// Compiler: g++
// File type: implementation file bst.cpp
//===============================================

#include <iostream>
#include "bst.h"

//This binary search tree implementation is heavily based on recusrion
// it does everything in terms of subtrees via this recursion

using namespace std;

//PURPOSE: construct the class with proper initialization
BST::BST() 
{
  root = NULL;   //start the root off at null without creating new nodes
} //end constructor

//PURPOSE: Removes all nodes of binary search tree to destruct it
// Continues to remove root values until the root is null (meaning empty)
BST::~BST() 
{
  while(root != NULL){
    remove(root->key);
  } //end while
} //end destructor
        
//PURPOSE: Inserts data into the binary search tree
//PARAMETER: The data value to be inserted
void BST::insert(int data) 
{
  //calls recursive insert to place into appropriate slot anchored at root
  root = insert(root, data);
} //end insert

//PURPOSE: Inserts data value into correct node slot - recursive!
//PARAMETER: The root node of the current subtree we are on,
// and the value we are inserting
Node* BST::insert(Node* node, int data) 
{
  //empty case - there is nothing in this subtree; make it the new node
  if(node == NULL)
    node = new Node(data);
  //data to be inserted is smaller than the node's value, insert left subtree
  else if(data < node->key)
    node->left = insert(node->left, data); //recursive insert left
  //data to be inserted is larger than the node's value, insert right subtree
  else if(data > node->key)
    node->right = insert(node->right, data); //recursive insert right
  return node; //return root of current subtree
} //end recursive insert

//PURPOSE: Searches for particular key in the binary search tree
//PARAMETER: The value to be searched for
Node* BST::search(int key) 
{
  //calls recursive search to go through the appropriate subtrees
  return search(root, key);
} //end search

//PURPOSE: Searches for particular key in the current subtree
//PARAMETERS: The root node of the current subtree we are on,
// and the value we are searching for in the current subtree
Node* BST::search(Node* node, int key) 
{
  //if the node we are on is null or we found the value, we are done
  if(node == NULL || node->key == key)
    //return the node with the value or indicate to stop searchig this
    //current subtree because we have reached the end of it
    return node;
  //if the value we are searching for is larger than the current node's value
  //then we continue to search by looking to the right subtree
  else if(key > node->key)
    return search(node->right, key); //recursive search right
  //if none of these conditions were met then that is because the value we
  //are searching for is smaller than the current node's value
  //thus we continue to search by looking to the left subtree
  return search(node->left, key); //recursive search left
} //end recursive search

//PURPOSE: traversal through binary search tree in order (least to greatest)
void BST::inorder() 
{
  //calls the recursive inorder traversal to move around different subtrees
  //and print out the values as it traverses
  inorder(root);
  //after we are done printing out or entire binary search tree,
  //space it out with an endline so the display looks nice in the end
  cout << endl;
} //end inorder traversal

//PURPOSE: traverse through current subtree in order (least to greatest)
//PARAMETER: The root node of the current subtree we are on
void BST::inorder(Node* node) 
{
  //as long as the node we are on is not null, we go left, display, then right
  if(node != NULL){
    inorder(node->left); //traverse through left subtree
    cout << node->key << " "; //display value in current node
    inorder(node->right); //traverse through right subtree
  } //end if
} //end recursive inorder traversal
		
//PURPOSE: Removes the node with a particular value
//PARAMETER: The value to be removed
void BST::remove(int key)
{
  //goes through all the subtrees in the binary search tree and removes value
  //it reassigns the root in case if the root was the one being removed
  root = remove(root, key);
} //end remove

//PURPOSE: removes particular key in the current subtree
//PARAMETERS: The root node of the current subtree we are on,
// and the value we are removing in the current subtree
Node* BST::remove(Node* node, int key)
{
  //if the node we are on is null, we are done traversing in
  if(node == NULL)
    //return the node to indicate to stop searching this current subtree
    return node;
  //if the value we are removing is smaller than the current node's value
  //then we continue by trying to remove it from the left subtree
  else if(key < node->key)
    node->left = remove(node->left, key); //recursive remove left
  //if the value we are removing is larger than the current node's value
  //then we continue by trying to remove it from the right subtree
  else if(key > node->key)
    node->right = remove(node->right, key); //recursive remove right
  //else clause represents the actual deletion step of the recursion
  else{
    //consider the cases where the current root node has 1 or 0 children
    //no left child case
    if(node->left == NULL){
      //temporary node for moving appropriately
      Node *temp = node->right;
      delete node;
      return temp;
    }
    //no right child case
    else if(node->right == NULL){
      //temporary node for moving appropriately
      Node *temp = node->left;
      delete node;
      return temp;
    }
    //consider the case where current node has 2 children
    //temporary node to get leftmost node
    Node *temp = leftmostNode(node->left);
    node->key = temp->key; //transfer and move appropriately
    node->left = remove(node->left, temp->key);
  }
  //return current root node as default
  return node;
} //end remove
    
//PURPOSE: returns leftmost node of the current subtree
//PARAMETER: The root node of the current subtree we are on
Node* BST::leftmostNode(Node* node)
{
  //create node for traversing beginning at the root
  Node *current = node;
  //leftmost means the largest value in the subtree
  //loop by always going right to the next node until you hit null
  //this way, you end up with the largest value in this subtree
  while(current->right != NULL)
    current = current->right;
  //return leftmost node after we find it
  return current;
}

