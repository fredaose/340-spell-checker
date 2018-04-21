//Freda Osei
//main.cpp
#include <iostream>
using namespace std;
#include "bst.cpp"
#include "String.cpp"
#include <fstream>
#include <cstring>

int main(int argc, char*argv[]){
	fstream fin (argv[1]);

	//A bst to hold words
	BinarySearchTree<String> tree;
	char copy[20];
	String s;
	
	//check to see if file is open
	if(fin.is_open()){
		while (!fin.eof()){
			fin >> copy;
			s=String(copy);
			tree.insert(s);
		}

	//get the height of the bst
	int tall = tree.getheight();
	cout << "Loaded the words into a tree with height = " << tall << "\n";
	bool end = false;

	//loop to read each word and search the provided file name if it contains that word
	while(end != true){
		char word[20];
		String w;
		cin >> word;
		w = String(word);
		
		
		if(tree.search(w) != true){
			cout <<word << " is spelled wrong!\n";
		}

		//terminates the program
		if(strcmp(word, "END")==0){
			cout << "BYE\n";
			end = true;
			return 1;
		}
	}

	}else{
		cout << "Could not open file \n";
		return 1;

	}
	return 0;
}
