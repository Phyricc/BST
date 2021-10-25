// Файл Tree.h представляет собой набор из класса и функций для создания и работы с бинарным деревом поиска.
// Файл main.cpp предназначен для тестирования и демонстрации работы описанных в файле Tree.h класса и функций.

// Подключение библиотек и файлов, необходимых для корректной работы программы.
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Tree.h"

int main() {
	// Создание дерева.
	stree tree;
	int value = 0;
	// Добавление в дерево 7 элементов (Для наглядности рекомендуется вводить элементы так, чтобы дерево получилось максимально "ровным", т.е. представляло собой подобие пирамиды).
	for (int i = 0; i < 7; i++) {
		std::cout << "\nInput value: ";
		std::cin >> value;
		tree.addNode(value);
	}
	// Вывод дерева на экран.
	std::cout << "\ntree: \n" << tree;
	int elem = 0;
	std::cout << "\nInput element to test 'find function': ";
	std::cin >> elem;
	// Тестирование работы функции нахождения значения в дереве.
	std::cout << "\n" << elem << " is in the tree: " << tree.findNode(elem);
	// Тестирование работы функции вычисления мощности дерева.
	std::cout << "\nThe power of the tree is: " << tree.tpower();
	// Создание и заполнение дополнительного дерева для тестирования функций и операторов, использующих два дерева.
	stree t;
	t.addNode(7);
	t.addNode(4);
	t.addNode(3);
	t.addNode(5);
	t.addNode(9);
	t.addNode(8);
	t.addNode(10);
	// Вывод дерева на экран.
	std::cout << "\nt: \n" << t;
	t += 6;
	std::cout << "\nt: \n" << t;
	// Тестирование функции сравнения деревьев на абсолютное сходство.
	std::cout << "\nt is equal to tree: " << tree.eqaulT(t);
	t -= 6;
	// Вывод дерева на экран.
	std::cout << "\nt: \n" << t;
	// Тестирование перегрузки оператора "+".
	tree = tree + t;
	std::cout << "\ntree after the merger with t: \n" << tree;
	stree tmp;
	tmp = t + tree;
	std::cout << "\ntmp after the merger t with tree: \n" << tmp;
	// Тестирование перегрузки оператора "*".
	tree = tree * t;
	std::cout << "\ntree after the intersection with t: \n" << tree;
	if (tree.tpower() == 0) std::cout << "\nset, based on tree is equal to set, based on t";
	else std::cout << "\nset, based on tree is not equal to set, based on t";
	return 0;
}