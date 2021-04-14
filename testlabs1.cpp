// testlabs1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void getWord(char *s1, char *s2, int n)
{
	setlocale(LC_ALL, "Russian");
	int i = 0, j = 0;
	int s = 1;
	while (s < n) {
		if (s1 [i] == ' ') {
			s++;}
		i++;
	}
	for (; (s1[i] != '\0') && (s1[i] != ' ') && (s1[i] != ',') && (s1[i] != '.') && (s1[i] != '!') && (s1[i] != '?');
		i++, j++)
		s2[j] = s1[i];
		s2[j] = '\0';
}

int countWords(char *s)
{
	setlocale(LC_ALL, "Russian");
	int i, res = 1;
	for (i = 0; s[i]; i++)	
		if (s[i] == ' ')
			res++;
	return res;
}

int findWord(char *s1, char *s2)	
{
	setlocale(LC_ALL, "Russian");
	int i, n;
	char s[30];
	n = countWords(s1);
	for (i = 1; i <= n; i++){
		getWord(s1, s, i);
		if (strcmp(s2, s) == 0)
			return i;
	}
	return 0;
}
	
void endcoding (char s1[4][100],char *s2, int *p, int n)
{
	setlocale(LC_ALL, "Russian");
	int pos;
	char s[50];
	int i, j;
	for (i = 1; i <= n/2; i++) {
		getWord(s2, s, i);
		for (j = 0; j < 4; j++) {
			pos = findWord(s1[j], s);
			if (pos) {
				p[(2*i) - 2] = j + 1;
				p[(2*i) - 2] = pos;
				break;
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, i;
	int *p;
	char s1[4][100] = {"Зачем копить добро в пустыне бытия?",
		"Кто вечно жил средь нас? Таких не видел я!",
		"Ведь жизнь нам в долг дана, и то на срок не долгий, ",
		"А то, что в долг дано - не собственность твоя!"};
	char s2[1];
	n = 2 * countWords(s2);
	p = new int[n];
	endcoding(s1, s2, p, n);
	for (i = 0; i < n; i++)
		cout << p[i] << " ";
	cout << endl;
	delete [] p;
	cout << s2 << endl;
	return 0;
}