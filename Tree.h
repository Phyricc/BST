#pragma once
#include <iostream>
#include <vector>

// BST based on set.
class stree {
private:
	// Main data types, that we create and use to make BST.
	struct node;
	typedef node* node_ptr;

	// Node value (int); left and right subBST's pointers (node_ptr); Default node value.
	struct node {
		int data;
		node_ptr lt, rt;
		node(int val, node_ptr l = nullptr, node_ptr r = nullptr) :
			data(val), lt(l), rt(r) {}
	};

	// BST root.
	node_ptr root;

	// Inner functions (the user does not have access to them).

	// Deleting node.
	void delete_tree(node_ptr t) {
		if (t != nullptr) {
			delete_tree(t->lt);
			delete_tree(t->rt);
			delete t;
		}
	}

	// Adding node.
	void add(node_ptr& t, int a) {
		if (t == nullptr) { t = new node(a); }
		else if (t->data == a) return void();
		else if (t->data > a) add(t->lt, a);
		else add(t->rt, a);
	}

	// Printing BST.
	void print(const node_ptr& t, std::ostream& os, int level) const {
		if (t) {
			print(t->rt, os, level + 2);
			for (int i = 0; i < level; i++) os << "  ";
			os << t->data << "\n ";
			print(t->lt, os, level + 2);
		}
	}

	// Copying one BST to another.
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

	// Searching for a certain BST value.
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

	// BST power.
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

	// BST's absolute comparsion function (it looks for the coincidence of the values of nodes and the positions of these nodes in trees).
	bool equal(const node_ptr& t1, const node_ptr& t2) {
		if (t1->data != t2->data) { return false; }
		else return true;
		if (!(t1) && !(t2)) { return true; }
		if ((!(t1) && t2) || (t1 && !(t2))) { return false; }
		else { return equal(t1->lt, t2->lt) && equal(t1->rt, t2->rt); }
	}

	// Searching for minimum BST value.
	int minimum(const node_ptr& t) {
		if (t->lt == nullptr) return t->data;
		return minimum(t->lt);
	}

	// Removing BST node.
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

	// Preorder BST traversal.
	void bst_preorder_vect(const node_ptr& t, std::vector<int>& a) {
		if (t) {
			a.push_back(t->data);
			if (t->lt) bst_preorder_vect(t->lt, a);
			if (t->rt) bst_preorder_vect(t->rt, a);
		}
	}

// Functions, which user can use.
public:
	// Creating an empty BST (builder).
	stree() { root = nullptr; }
	// Creating BST by a given BST (builder).
	stree(const stree& t) { root = t.root; }
	// Destructor.
	~stree() { delete_tree(root); }
	// Adding node to the BST.
	void addNode(int a) { add(root, a); }
	// Deleting node from the BST.
	void delNode(int a) { remove(root, a); }
	// Searching for a certain BST value.
	bool findNode(int a) { return find(this->root, a); }
	// BST power.
	int tpower() const { return spower(root); }
	// Absolute BST's similarity check.
	bool eqaulT(const stree& t) { return this->equal(root, t.root); }
	// Displaying array elements on the screen .
	void print_arr(int* a, size_t size) {
		for (int i = 0; i < size; i++) {
			std::cout << "\na[" << i << "]: " << a[i];
		}
	}
	// "+=" operator overload, which adds node to the BST.
	stree& operator+=(int a) {
		this->addNode(a);
		return *this;
	}
	// "-=" operator overload, which removes node from the BST.
	stree& operator-=(int a) {
		this->delNode(a);
		return *this;
	}
	// "=" operator overload, performing assignment of values from one BST to another.
	stree& operator=(const stree& t) {
		this->copy(t.root, this->root);
		return *this;
	}
	// "+" operator overload, which merges two BST's.
	// Comments inside the code are intended to trace the function
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
	// "*" operator overload, which does two BST's intersection.
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
	// "<<" operator overload.
	friend std::ostream& operator<<(std::ostream& os, const stree& t) {
		t.print(t.root, os, 0);
		return os;
	}
};