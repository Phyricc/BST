// File Tree.h is a class and function combination, which is made to create and work with BST.
// File main.cpp is made for test and demonstrate work of described at Tree.h file class and functions.

// Here we include all necessary libraries and files.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Tree.h"

int main() {
	// Creating BST.
	stree tree;
	int value = 0;
	// Adding 7 elemtns to the tree (For clarity, it is recommended to introduce elements so that the tree turns out to be as "smooth" as possible, i.e. it looks like a pyramid).
	for (int i = 0; i < 7; i++) {
		std::cout << "\nInput value: ";
		std::cin >> value;
		tree.addNode(value);
	}
	// Printing our BST.
	std::cout << "\ntree: \n" << tree;
	int elem = 0;
	std::cout << "\nInput element to test 'find function': ";
	std::cin >> elem;
	// Testing "find" function.
	std::cout << "\n" << elem << " is in the tree: " << tree.findNode(elem);
	// Testing function, which calculates power of the BST.
	std::cout << "\nThe power of the tree is: " << tree.tpower();
	// Creating and filling an extra BST for testing functions and	operators, using two BST's.
	stree t;
	t.addNode(7);
	t.addNode(4);
	t.addNode(3);
	t.addNode(5);
	t.addNode(9);
	t.addNode(8);
	t.addNode(10);
	// Printing our BST.
	std::cout << "\nt: \n" << t;
	t += 6;
	std::cout << "\nt: \n" << t;
	// Testing BST's comparsion function.
	std::cout << "\nt is equal to tree: " << tree.eqaulT(t);
	t -= 6;
	// Printing our BST.
	std::cout << "\nt: \n" << t;
	// Testing "+" operator overload.
	tree = tree + t;
	std::cout << "\ntree after the merger with t: \n" << tree;
	stree tmp;
	tmp = t + tree;
	std::cout << "\ntmp after the merger t with tree: \n" << tmp;
	// Testing "*" operator overload.
	tree = tree * t;
	std::cout << "\ntree after the intersection with t: \n" << tree;
	if (tree.tpower() == 0) std::cout << "\nset, based on tree is equal to set, based on t";
	else std::cout << "\nset, based on tree is not equal to set, based on t";
	return 0;
}