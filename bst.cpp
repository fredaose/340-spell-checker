// bst.cpp
//Freda Osei
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename type>
class BinarySearchTree {
    private:
        struct Node {
            type data;
            Node* left;
            Node* right;
        };

        Node* root;

        // recursive function to insert at a particular node
        void insertAt(type number, Node*& node) {
            if(node == NULL) {
                node = new Node;
                node->data = number;
                node->left = NULL;
                node->right = NULL;
            } else if(node->data < number) {
                insertAt(number, node->right);
            } else {
                insertAt(number, node->left);
            }
        }

        // recursive function to search starting at a particular node it
        // returns a pointer to the node or NULL for not found
        Node*& searchAt(type number, Node*& node) {
            if(node == NULL) {
                return node;
            } else if(node->data == number) {
                return node;
            } else if(node->data < number) {
                return searchAt(number, node->right);
            } else {
                return searchAt(number, node->left);
            }
        }

        // find smallest node in a tree
        Node*& min(Node*& node) {
            // if the tree is empty there is no min
            if(node == NULL) {
                return node;
            }

            // if there are none to the left, return this one
            else if(node->left == NULL) {
                return node;
            }

            // if there are some to the left, smallest is there
            else {
                return min(node->left);
            }
        }

        // remove a particular node
        void removeNode(Node*& node) {
            // if the node we are removing has no children, just delete it!
            if((node->left == NULL) && (node->right == NULL)) {
                delete node;
                node = NULL;
            }

            // if the node has one child, just skip over it!
            else if((node->left == NULL) && (node->right != NULL)) {
                Node* rest = node->right;
                delete node;
                node = rest;
            }
            else if((node->left != NULL) && (node->right == NULL)) {
                Node* rest = node->left;
                delete node;
                node = rest;
            }

            // if the node has 2 children, find the smallest in the right subtree
            // swap it, and delete smallest in right subtree
            else {
                Node*& least = min(node->right);
                type temp = least->data;
                least->data = node->data;
                node->data = temp;
                removeNode(least);
            }
        }

        // an in-order tree traversal
        void inorder(Node* node) const {
            if(node != NULL) {
                inorder(node->left);
                cout << node->data << endl;
                inorder(node->right);
            }
        }

    public:
        // set the whole tree to NULL
        BinarySearchTree() {
            root = NULL;
        }

        // insert a number calls recursive function to insert at the root
        void insert(type number) {
            insertAt(number, root);
        }

        // search for a word in the tree
        bool search(type word) {
            Node* target = searchAt(word, root);
            if(target == NULL) {
                return false;
            } else {
                return true;
            }
        }

        // remove a particular data item from the tree
        void remove(type number) {
            Node*& to_remove = searchAt(number, root);
            if(to_remove != NULL) {
                removeNode(to_remove);
            }
        }

        // print the nodes inorder
        void print() const {
            inorder(root);
        }

	    //recursive helper method to get the height of the tree
		int height(Node* node){
			if (!node) return 0;
			return 1 + max(height(node->left), height(node->right));
		}

		//returns the height of a bst
		int getheight(){
			return height(root);
		}
};

