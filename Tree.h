#pragma once
#include <iostream>
#include <vector>

// Бинарное дерево поиска, основанное на множестве.
class stree {
private:
	// Основные типы данных для использования.
	struct node;
	typedef node* node_ptr;

	// Значение узла (int); указатели на левое и правое поддеревья (node_ptr); значение узла по умолчанию.
	struct node {
		int data;
		node_ptr lt, rt;
		node(int val, node_ptr l = nullptr, node_ptr r = nullptr) :
			data(val), lt(l), rt(r) {}
	};

	// Создание корня дерева.
	node_ptr root;

	// Внутренние функции (у пользователя нет к ним прямого доступа).

	// Удаление узла дерева.
	void delete_tree(node_ptr t) {
		if (t != nullptr) {
			delete_tree(t->lt);
			delete_tree(t->rt);
			delete t;
		}
	}

	// Добавление узла дерева.
	void add(node_ptr& t, int a) {
		if (t == nullptr) { t = new node(a); }
		else if (t->data == a) return void();
		else if (t->data > a) add(t->lt, a);
		else add(t->rt, a);
	}

	// Вывод дерева на экран.
	void print(const node_ptr& t, std::ostream& os, int level) const {
		if (t) {
			print(t->rt, os, level + 2);
			for (int i = 0; i < level; i++) os << "  ";
			os << t->data << "\n ";
			print(t->lt, os, level + 2);
		}
	}

	// Копирование дерева в другое дерево.
	void copy(node_ptr t, node_ptr& newT) const {
		if (t != nullptr) {
			newT = new node(t->data);
			copy(t->lt, newT->lt);
			copy(t->rt, newT->rt);
		}
		else {
			newT = nullptr;
		}
	}

	// Поиск конкретного значения в дереве.
	bool find(const node_ptr& t, int a) {
		if (t) {
			if (t->data == a) return true;
			if (a < t->data) {
				if (t->lt != nullptr) return find(t->lt, a);
				else return false;
			}
			else {
				if (t->rt != nullptr) return find(t->rt, a);
				else return false;
			}
		}
		return false;
	}

	// Мощность дерева.
	int spower(const node_ptr& t) const {
		if (t) {
			if (t->lt == nullptr && t->rt == nullptr) {
				return 1;
			}
			int left, right;
			if (t->lt != nullptr) {
				left = spower(t->lt);
			}
			else {
				left = 0;
			}
			if (t->rt != nullptr) {
				right = spower(t->rt);
			}
			else {
				right = 0;
			}
			return left + 1 + right;
		}
		else return 0;
	}

	// функци сравнивает деревья на асболютное сходство (совпадение значений узлов и положений этих узлов в деревьях).
	bool equal(const node_ptr& t1, const node_ptr& t2) {
		if (t1->data != t2->data) { return false; }
		else return true;
		if (!(t1) && !(t2)) { return true; }
		if ((!(t1) && t2) || (t1 && !(t2))) { return false; }
		else { return equal(t1->lt, t2->lt) && equal(t1->rt, t2->rt); }
	}

	// Поиск минимального значения в дереве.
	int minimum(const node_ptr& t) {
		if (t->lt == nullptr) return t->data;
		return minimum(t->lt);
	}

	// Удаление узла дерева.
	void remove(node_ptr& t, int a) {
		if (t == nullptr) {
			return void();
		}
		if (a < t->data) {
			remove(t->lt, a);
		}
		else if (a > t->data) {
			remove(t->rt, a);
		}
		else if (t->lt != nullptr && t->rt != nullptr) {
			t->data = minimum(t->rt);
			remove(t->rt, t->data);
		}
		else {
			if (t->lt != nullptr) {
				t = t->lt;
			}
			else if (t->rt != nullptr) {
				t = t->rt;
			}
			else {
				t = nullptr;
			}
		}
	}

	// Прямой обход дерева.
	void bst_preorder_vect(const node_ptr& t, std::vector<int>& a) {
		if (t) {
			a.push_back(t->data);
			if (t->lt) bst_preorder_vect(t->lt, a);
			if (t->rt) bst_preorder_vect(t->rt, a);
		}
	}

// Функции, доступные пользователю.
public:
	// Создание пустого дерева (конструктор).
	stree() { root = nullptr; }
	// Создание дерева по заданному дереву (конструктор).
	stree(const stree& t) { root = t.root; }
	// Деструктор
	~stree() { delete_tree(root); }
	// Добавление узла в дерево.
	void addNode(int a) { add(root, a); }
	// Удаление узла из дерева.
	void delNode(int a) { remove(root, a); }
	// Поиск значения в дереве.
	bool findNode(int a) { return find(this->root, a); }
	// Мощность дерева.
	int tpower() const { return spower(root); }
	// Проверка деревьев на полное сходство.
	bool eqaulT(const stree& t) { return this->equal(root, t.root); }
	// вывод элементов массива.
	void print_arr(int* a, size_t size) {
		for (int i = 0; i < size; i++) {
			std::cout << "\na[" << i << "]: " << a[i];
		}
	}
	// Перегрузка оператора "+=" для дерева, выполняющего добавление узла в дерево.
	stree& operator+=(int a) {
		this->addNode(a);
		return *this;
	}
	// Перегрузка оператора "-=" для дерева, , выполняющего удаление узла из дерева.
	stree& operator-=(int a) {
		this->delNode(a);
		return *this;
	}
	// Перегрузка оператора "=" для дерева, выполняющего присваивание значений одного дерева другому.
	stree& operator=(const stree& t) {
		this->copy(t.root, this->root);
		return *this;
	}
	// Перегрузка оператора "+" для дерева, выполняющего слияние деревьев.
	// Комментарии внутри кода предназначены для трассировки функции
	stree& operator+(const stree& t) {
		std::vector<int> tmp1, tmp2;
		bst_preorder_vect(this->root, tmp1);
		bst_preorder_vect(t.root, tmp2);
		tmp1.insert(tmp1.end(), tmp2.begin(), tmp2.end());
		/*for (int i : tmp1) {
			std::cout << " " << i << " ";
		}*/
		stree tmp;
		for (int i : tmp1) {
			tmp.addNode(i);
		}
		//std::cout << "\ntmp: \n" << tmp;
		*this = tmp;
		return *this;
	}
	// Перегрузка оператора "*" для дерева, выполняющего пересечение деревьев.
	stree& operator*(const stree& t) {
		std::vector<int> tmp1, tmp2;
		bst_preorder_vect(this->root, tmp1);
		bst_preorder_vect(t.root, tmp2);
		stree tmp;
		for (int i : tmp1) {
			tmp.addNode(i);
		}
		for (int i : tmp2) {
			if (find(tmp.root, i)) tmp -= i;
		}
		*this = tmp;
		return *this;
	}
	// Перегрузка оператора вывода для дерева.
	friend std::ostream& operator<<(std::ostream& os, const stree& t) {
		t.print(t.root, os, 0);
		return os;
	}
};