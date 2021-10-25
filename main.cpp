// ���� Tree.h ������������ ����� ����� �� ������ � ������� ��� �������� � ������ � �������� ������� ������.
// ���� main.cpp ������������ ��� ������������ � ������������ ������ ��������� � ����� Tree.h ������ � �������.

// ����������� ��������� � ������, ����������� ��� ���������� ������ ���������.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Tree.h"

int main() {
	// �������� ������.
	stree tree;
	int value = 0;
	// ���������� � ������ 7 ��������� (��� ����������� ������������� ������� �������� ���, ����� ������ ���������� ����������� "������", �.�. ������������ ����� ������� ��������).
	for (int i = 0; i < 7; i++) {
		std::cout << "\nInput value: ";
		std::cin >> value;
		tree.addNode(value);
	}
	// ����� ������ �� �����.
	std::cout << "\ntree: \n" << tree;
	int elem = 0;
	std::cout << "\nInput element to test 'find function': ";
	std::cin >> elem;
	// ������������ ������ ������� ���������� �������� � ������.
	std::cout << "\n" << elem << " is in the tree: " << tree.findNode(elem);
	// ������������ ������ ������� ���������� �������� ������.
	std::cout << "\nThe power of the tree is: " << tree.tpower();
	// �������� � ���������� ��������������� ������ ��� ������������ ������� � ����������, ������������ ��� ������.
	stree t;
	t.addNode(7);
	t.addNode(4);
	t.addNode(3);
	t.addNode(5);
	t.addNode(9);
	t.addNode(8);
	t.addNode(10);
	// ����� ������ �� �����.
	std::cout << "\nt: \n" << t;
	t += 6;
	std::cout << "\nt: \n" << t;
	// ������������ ������� ��������� �������� �� ���������� ��������.
	std::cout << "\nt is equal to tree: " << tree.eqaulT(t);
	t -= 6;
	// ����� ������ �� �����.
	std::cout << "\nt: \n" << t;
	// ������������ ���������� ��������� "+".
	tree = tree + t;
	std::cout << "\ntree after the merger with t: \n" << tree;
	stree tmp;
	tmp = t + tree;
	std::cout << "\ntmp after the merger t with tree: \n" << tmp;
	// ������������ ���������� ��������� "*".
	tree = tree * t;
	std::cout << "\ntree after the intersection with t: \n" << tree;
	if (tree.tpower() == 0) std::cout << "\nset, based on tree is equal to set, based on t";
	else std::cout << "\nset, based on tree is not equal to set, based on t";
	return 0;
}