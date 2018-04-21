# 340-spell-checker
Due: April 19

Objective

To gain experience using templates and binary search trees.

Task

A simple way of performing spell checking is to store the set of all valid words in some data structure. For each word we need to check, we’ll search the data structure to see if the word is stored. If it is, we will say that the word is spelled correctly. If not, we will say that the word is spelled incorrectly.

For this assignment, you will be writing a program that does spell checking with a binary search tree.

Your program will take a command-line parameter which will be the name of a dictionary file. This file will contain every word that your program should consider to be correctly spelled. If the user doesn’t specify the name of the dictionary file, or if the file doesn’t exist, your program should print an error message.

Here is a sample dictionary file. This file contains almost 100,000 English words.

Your program should open the dictionary file and insert the words, one by one, into a binary search tree. Then your program should take input from the user and report whether or not each word they enter is spelled correctly or not. The word “END” will signify the end of input.

The program’s efficiency will depend on how balanced the tree is, so you should print out the height of the tree after inserting all of the words from the dictionary. You do not need to balance the tree, you can just insert them in the order they are in the file. If you insert the file above using the insertion algorithm discussed in class, the height should be 42.

Here is a sample run of such a program:

$ spellcheck words.txt 
Loaded the words into a tree with height = 42
this is a test
Missisippi
Missisippi is spelled wrong!
Mississippi
here are some moar words 
moar is spelled wrong!
END     
Details

Your program will consist of a templated binary search tree class, and a main function which uses the binary search tree.
You can base your class on this example which includes insert and search functions. You will have to template this class so it can be used with any data type
Because character arrays don’t really behave properly for all of the operations the binary search tree class will need, such as using the comparison operators, you can’t directly create a BinarySearchTree<char*>. To get around this, you will need to use a String class that overloads these operators to behave correctly. For this assignment, you can use the String class that we built earlier in the semester.
In the main source file, create the binary search tree object to store the string objects.
Open the dictionary file and read all of the words from it, inserting them into the binary search tree as you go.
You will need to add a function to the binary search tree class that will compute the height of the tree. This function will be much easier to write with recursion.
Call the height function to print the height of the tree.
Read input from the user and, for each word they type, search for it in the tree to see if it’s spelled correctly.
When the user enters “END” the program should quit.
To be considered spelled correctly, the words must match exactly including case.
General Requirements

No global variables other than constants.
All member data of a class must be private.
Your source code should be readable and reasonably indented.
You must provide comments in your code.
Member functions that don’t change a classes member data should be marked as const.
