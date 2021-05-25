// lab6_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdlib.h>
using namespace std;

int get_elem();

struct Tree 
{
	Tree* p_left;
	Tree* p_mid;
	Tree* p_right;
	int n;
};

Tree* MakeElements(int N) 
{
	if (N == 0) 
	{
		return NULL;
	}
	Tree* p_mid = new Tree;
	p_mid->n = 1;
	N--;
	p_mid->p_mid = NULL;
	if (N == 0) 
	{
		p_mid->p_left = NULL;
		p_mid->p_right = NULL;
	}
	else 
	{
		Tree* p_left = p_mid->p_left = new Tree;
		p_left->n = 2;
		p_left->p_left = NULL;
		p_left->p_right = NULL;
		N--;
		if (N == 0) 
		{
			p_left->p_mid = NULL;
			p_mid->p_right = NULL;
		}
		else 
		{
			Tree* p_right = p_mid->p_right = new Tree;
			p_right->n = 3;
			p_right->p_left = NULL;
			p_right->p_right = NULL;
			N--;
			if (N == 0) 
			{
				p_right->p_mid = NULL;
			}
			else 
			{
				p_left->p_mid = p_right->p_mid = MakeElements(N);
			}
		}
	}
	return p_mid;
}


void PrintTree(Tree* root);

int main()
{
	const int count_elements = get_elem();
	Tree* root = MakeElements(count_elements);
	PrintTree(root);
	return 0;
}

void PrintTree(Tree* p_mid)
{
	if (p_mid != NULL) 
	{
		cout << "          " << p_mid->n << endl;

		if (p_mid->p_left != NULL) 
		{
			Tree* p_left = p_mid->p_left;
			cout << "     " << p_left->n;
		}
		if (p_mid->p_right != NULL) 
		{
			Tree* p_right = p_mid->p_right;
			cout << "         " << p_right->n << endl;
			if (p_right->p_mid != NULL) 
			{
				PrintTree(p_right->p_mid);
			}
		}
	}
}

int get_elem()
{
	int elem = 0;
	while (true)
	{
		cout << "How many elements u need in tree?\n";
		cin >> elem;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "It's not correct, please write again" << endl;
		}
		else
		{
			return elem;
			break;
		}
	}
}