//===============================================
// Extra Credit Program - Final Exam
// Name: Brian Vargas
// Compiler: g++
// File Type: client file client1.cpp
//===============================================

#include <iostream>
#include "trie.h"

using namespace std;

//client file to test if vocab trie works: add, search word, search prefix
int main()
{
    //create a trie object
    Trie vocabulary;
    //output and input menu options
    cout << "Type '0'--quit;   '1'--add a word;   '2'--search a word;   '3'--search prefix: ";
    int choice;
    cin >> choice;
    //infinite loop that keeps going until quit is provided for menu choice
    while(choice) {
        //add an inputted word to the vocab trie
        if(choice == 1) {
            cout << "Add to the vocabulary this word: ";
            string word;
            cin >> word;
            vocabulary.add(word);
        //search for an inputted word in the vocab trie; report results
        } else if(choice == 2) {
            cout << "Search this word: ";
            string key;
            cin >> key;
            if(vocabulary.contains(key))
                cout << key << " exists!" << endl;
            else
                cout << key << " does not exist." << endl;
	//search for an inputted prefix in the vocab trie; report esults
        } else if(choice == 3) {
            cout << "Search this prefix: ";
            string key;
            cin >> key;
            if(vocabulary.isPrefix(key))
                cout << key << " is a prefix." << endl;
            else
                cout << key << " is not a prefix." << endl;
	//impromper input; loop back
        } else {
            cout << "Input incorrect. Try again." << endl;
        }
        cout << "Type '0'--quit;   '1'--add a word;   '2'--search a word;   '3'--search prefix: ";
        cin >> choice;
    }
    return 0;
}
