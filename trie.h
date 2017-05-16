#ifndef TRIE_H
#define TRIE_H

#define MAX_CHAR 256

class Node
{
private:
    Node *children[MAX_CHAR];
    bool bisEnd;
public:
    Node();
    bool isEnd();
    void insert(string suffix);
    Node* search(string pat);
};

class Trie
{
private:
    Node root;
public:
    void add(string word);
    bool contains(string pat);
    bool isPrefix(string pat);
};
#endif