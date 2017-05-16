//===============================================
// Extra Credit Program - Final Exam
// Name: Brian Vargas
// Compiler: g++
// File type: header file trie.h
//===============================================

#ifndef TRIE_H
#define TRIE_H

#include<string>

using namespace std;

#define MAX_CHAR 256

//node class to hold information of prefixes - made public to ease implementation
class Node
{
public:
    //node array - tells us when a certain letter appears by having a node following index
    Node *children[MAX_CHAR];
    //boolean that tells us if we have reached the end of a word
    bool bisEnd;
    //empty constructor; begins the children at null and boolean at false
    Node();
};

//trie class - prefix tree
class Trie
{
private:
    //root node of the tree
    Node* root;
public:
    //empty constructor - initializes a brand new root node that is empty
    Trie();

    //PURPOSE: Inserts a word into the trie
    //PARAMETER: Word to be inserted
    void add(string word);

    //PURPOSE: Determines whether the word is in the trie (as a whole)
    //PARAMETER: Word to be checked for
    bool contains(string pat);

    //PURPOSE: Determines whether the string is a prefix in the trie
    //PARAMETER: String to be checked for
    bool isPrefix(string pat);

    //PURPOSE: Finds the longest prefix for a word that is also a word within the trie
    //PARAMETER: Word to be checked for
    string longestPrefix(string word);
};
#endif
