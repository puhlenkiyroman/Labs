// lab6_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

int Count = 0;

struct Tree {
	Tree* p_left;
	Tree* p_mid;
	Tree* p_right;
	int n;
};

Tree* MakeTree(int N) {
	if (N == 0) {
		return NULL;
	}
	Tree* p_mid = new Tree;
	p_mid->n = 1;
	N--;
	p_mid->p_mid = NULL;
	if (N == 0) {
		p_mid->p_left = NULL;
		p_mid->p_right = NULL;
	}
	else {
		Tree* left = p_mid->p_left = new Tree;
		left->n = 2;
		left->p_left = NULL;
		left->p_right = NULL;
		N--;
		if (N == 0) {
			left->p_mid = NULL;
			p_mid->p_right = NULL;
		}
		else {
			Tree* right = p_mid->p_right = new Tree;
			right->n = 3;
			right->p_left = NULL;
			right->p_right = NULL;
			N--;
			if (N == 0) {
				right->p_mid = NULL;
			}
			else {
				left->p_mid = right->p_mid = MakeTree(N);
			}
		}
	}
	return p_mid;
}

int main()
{
	Tree* q;
	q = MakeTree(4);
	cout << "Elements in tree: " << Count << endl;
	cout << q->n << endl;
	cout << q->p_left->n << endl;
	cout << q->p_right->n << endl;
	cout << q->p_left->p_mid->n << endl;
	cout << q->p_right->p_mid-> n << endl;
	return 0;
}
