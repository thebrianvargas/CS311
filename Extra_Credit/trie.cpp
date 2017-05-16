//===============================================
// Extra Credit Program - Final Exam
// Name: Brian Vargas
// Compiler: g++
// File type: implementation file trie.cpp
//===============================================

#include "trie.h"

using namespace std;

//Node constructor - initializes end to false and children to null
Node::Node()
{
  bisEnd = false;
  *children = NULL;
} //end: Node

//Trie constructor - creates a blank root node for us to work with
Trie::Trie()
{
  root = new Node();
} //end: Trie

//PURPOSE: Inserts a word into the trie
//PARAMETER: Word to be inserted
void Trie::add(string word)
{
  //begin at root node; will traverse through children
  Node *current = root;
  //move through each character in the word
  for(int i=0; i<word.length(); i++)
  {
    //extract ith character of word
    int letter = word[i]-'a';
    //check if prefix tree already uses that letter; if not, create a new node to expand tree further
    if(current->children[letter] == NULL)
      current->children[letter] = new Node();
    //move deeper within the tree by going into that letter
    current = current->children[letter];
  } //end for(i)
  //once for loop is finished, we have completed insert. alert system this last node completes a word
  current->bisEnd = true;
} //end: add

//PURPOSE: Determines whether the word is in the trie (as a whole)
//PARAMETER: Word to be checked for
bool Trie::contains(string pat)
{
  //begin at root node; will traverse through children
  Node *current = root;
  //move through each character in the inputted string
  for(int i=0; i<pat.length(); i++)
  {
    //extract ith character of inputted string
    int letter = pat[i]-'a';
    //check if prefix tree already uses the letter; if not, the word doesn't exist in trie
    if(current->children[letter] == NULL)
      return false;
    //move deeper within the tree by going into that letter
    current = current->children[letter];
  } //end for(i)
  //once for loop is finished, we have run out of characters to check
  //determine if we have arrived at the end of the word in the trie
  return current->bisEnd;
} //end: contains

//PURPOSE: Determines whether the string is a prefix in the trie
//PARAMETER: String to be checked for
bool Trie::isPrefix(string pat)
{
  //begin at root node; will traverse through children
  Node *current = root;
  //move through each character in the inputted string
  for(int i=0; i<pat.length(); i++)
  {
    //extract ith character of inputted string
    int letter = pat[i]-'a';
    //check if prefix tree already uses the letter; if not, the prefix doesn't exist in trie
    if(current->children[letter] == NULL)
      return false;
    //move deeper within the tree by going into that letter
    current = current->children[letter];
  } 
  //once for loop is finished, we have run out of characters to check
  //that means all of the letters in the inputted string were present in the trie,
  // which is the definition of being a prefix: that other words use the inputted string
  // to form other words. Note that a word itself is also a predix of itself.
  return true;
} //end: isPrefix

//PURPOSE: Finds the longest prefix for a word that is also a word within the trie
//PARAMETER: Word to be checked for
string Trie::longestPrefix(string word)
{
  //create an empty string to hold the output
  string out = "";
  //pre will contain a substring of the inputted string to check if it's a prefix word
  string pre;
  //move through each character in the inputted string; we will form a substring up to that character
  for(int i=0; i<word.length(); i++)
  {
    //form a substring up to the ith letter to check if it's a prefix word
    pre = word.substr(0,i);
    //if the substring is within the trie, it's a prefix word
    if(contains(pre))
      //update output string and keep iterating in case there's a larger prefix word
      out = pre;
  }
  //once for loop is finished, out contains the largest prefix word
  return out;
} //end: longestPrefix
