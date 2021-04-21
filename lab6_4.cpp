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
	Tree* p;
	p = new Tree;
	Tree* p0 = p->p_mid = new Tree;
	p->n = Count++;
	Tree* p1 = p->p_left = new Tree;
	Tree* p2 = p->p_right = new Tree;

	p1->p_right = p2;
	p2->p_left = p1;
	p1->n = Count++;
	p2->n = Count++;
	p1->p_left = p2->p_right = MakeTree(N - 2);

	return p;
}
int main()
{
	Tree* q;
	q = MakeTree(4);
	cout << "Elements in tree: " << Count << endl;
	cout << q->n << endl;
	return 0;
}