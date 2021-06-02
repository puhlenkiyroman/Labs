// lab8_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class Tree
{
private:

    Tree* p_left;
    Tree* p_right;
    Tree* p_mid;
    int n;

    Tree* addElem(Tree* root, int value)
    {
        if (root == NULL)
        {
            Tree* root = new Tree(value);
            return root;
        }
        else
        {
            if (value < root->n)
            {
                root->p_left = addElem(root->p_left, value);
                return root->p_left;
            }
            if (value > root->n)
            {
                root->p_right = addElem(root->p_right, value);
                return root->p_right;
            }
            else
            {
                root->p_mid = addElem(root->p_mid, value);
                return root->p_mid;
            }
        }
    }

    void printSpace(int c)
    {
        for (int i = 0; i < c; i++)
        {
            printf(" ");
        }
    }

    int indent(Tree* root)
    {
        static int c = 0;
        if (c < 0) { c = 0; }

        if (root->p_left != NULL)
        {
            c++;
            indent(root->p_left);
        }
        else if (root->p_mid != NULL)
        {
            indent(root->p_mid);
        }
        else if (root->p_right != NULL)
        {
            c--;
            indent(root->p_right);
        }

        return c;
    }

public:

    Tree(int n) {
        this->p_right = NULL;
        this->p_left = NULL;
        this->p_mid = NULL;
        this->n = n;
    }

    void addElems(Tree* root, int c)
    {
        for (int i = 0; i < c; i++)
        {
            root = root->addElem(root, rand() % 10);
        }
    }

    void printTree(Tree* root)
    {
        static int c = indent(root);
        if (root->p_left != NULL)
        {
            printSpace(c);
            c--;
            printf(" %d\n", root->n);
            c++;
            printSpace(c);
            c--;
            printf("/\n");
            c--;
            printTree(root->p_left);
        }
        else if (root->p_mid != NULL)
        {
            c++;
            printSpace(c);
            printf("%d\n", root->n);
            printSpace(c);
            printf("|\n");
            c--;
            printTree(root->p_mid);
        }
        else if (root->p_right != NULL)
        {
            c++;
            printSpace(c);
            printf("%d \n", root->n);
            c++;
            printSpace(c);
            printf("\\\n");
            printTree(root->p_right);
        }
        else if (root != NULL)
        {
            c++;
            printSpace(c);
            printf("%d\n", root->n);
        }
    }

};

int getElem()
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
            return elem - 1;
            break;
        }
    }
}

int main(void)
{
    Tree* root = new Tree(rand() % 10);
    root->addElems(root, getElem());
    root->printTree(root);

    return 0;
}
