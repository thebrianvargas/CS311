//===============================================
// Extra Credit Program - Final Exam            
// Name: Brian Vargas
// Compiler: g++
// File Type: client file client2.cpp
//===============================================

#include <iostream>
#include "trie.h"

using namespace std;

//client file to test of longest prefix is working properly
int main()
{
    //create a trie object for vocab
    Trie vocabulary;
    cout << "Type a word ('q' for quit): ";
    string word;
    cin >> word;
    //continue to loop until the inserted word is q - indicating it to quit
    while(word != "q") {
	//add the inputted word to the vocab trie
	vocabulary.add(word);
	//then find the longest prefix associated to that word
        cout << "The longest prefix is: " << vocabulary.longestPrefix(word) << endl; 
	//reloop until quit is specified
        cout << "Type a word ('q' for quit): ";
        cin >> word;
    }
    return 0;
}

