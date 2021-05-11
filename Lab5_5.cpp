#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define ROWS 7
#define COLS 100

using namespace std;

char search_string(char(&poem)[ROWS][COLS], char string[], int number_row, int count);
void decode(int count, int number_word, char* string);
int get_x();

int main()
{	
	int index = 0;
	char poem[ROWS][COLS] = {
	"Its not always easy to keep yourself bus",
	"The homework is done its fun !",
	"The book is readand is given to Fred",
	"The cat is fed but why is it sad",
	"The dishes are washed",
	"All films are watched",
	"Its not always easy to keep yourself busy"
	};

	int value_x = get_x();

	for (int i = 0; i <= value_x; i++)
	{
		int number_row = 0;
		cout << "\nEnter the row number: ";
		scanf_s("%d", &number_row);
		number_row--;

		int number_word = 0;
		cout << "Enter the word number: ";
		scanf_s("%d", &number_word);

		int count_characters = strlen(&poem[number_row][COLS]);
		char string[COLS];
		search_string(poem, string, number_row, count_characters);
		decode(count_characters, number_word, string);
	}
}

int get_x()
{
	int x = 0;
	while (true)
	{
		cout << "How many words u want to decode?\n";
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "It's not correct, please write again" << endl;
		}
		else
		{
			return x-1;
			break;
		}
	}
}

char search_string(char(&poem)[ROWS][COLS], char string[], int number_row, int count)
{

	for (int index = 0; index < count; index++)
	{
		string[index] = poem[number_row][index];
		cout << string[index];
	}
	cout << endl;
	return string[COLS];
}

void decode(int count, int number_word, char* string)
{
	int count_words = 0;
	char* word;
	word = new char[COLS];
	int beginning = 0;

	for (int index = 0; index < count; index++)
	{

		if ((string[index] != ' '))
		{
			word[index] = string[index];
		}

		else
		{
			count_words++;

			if (count_words == number_word)
			{
				if (number_word > 1)
				{
					for (int i = beginning; i < index; i++)
						cout << word[i];	
					break;
				}
				else
				{
					for (int i = 0; i < index; i++)
						cout << word[i];
					break;
				}
			}
			else
			{
				beginning = index + 1;
				delete[]word;
				word = new char[COLS];
			}
		}
	}
}
