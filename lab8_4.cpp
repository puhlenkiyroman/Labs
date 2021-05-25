// lab8_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

class Tree
{
private:
	Tree* one;
	Tree* two;
	Tree* three;
	int n;
public:
	Tree(int n)
	{
		this->one = NULL;
		this->two = NULL;
		this->three = NULL;
		this->n = n;
	}

	Tree* AddElem(Tree* root, int n)
	{
		if (root == NULL)
		{
			Tree* root = new Tree(n);
			return root;
		}

		else
		{

			if (n < root->n)
			{
				root->one = AddElem(root->one, n);
			}

			if (n == root->n)
			{
				root->two = AddElem(root->two, n);
			}

			if (n > root->n)
			{
				root->three = AddElem(root->three, n);
			}

			return root;

		}

	}

	void PrintTree() 
	{

		if (this->one != NULL)
		{
			this->one->PrintTree();
		}

		if (this->two != NULL)
		{
			this->two->PrintTree();
		}

		cout << this->n << " ";

		if (this->three != NULL)
		{
			this->three->PrintTree();
		}
	}

};

int main()
{
	Tree* root = new Tree(rand() % 10);
	for (int i = 0; i < 35; i++)
	{
		(*root).AddElem(root, rand() % 10);
	}
	root->PrintTree();
	return 0;
}