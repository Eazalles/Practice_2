#include <iostream>
#include <windows.h>
#include <string>
#include <cstdlib>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
};

struct Record
{
	char author[20];
	char title[20];
	int year;
	char group;
	struct Date date;
};


void myCentr(string s, int wLine) {

	int w = s.length();
	int delta = (wLine - w) / 2;
	cout << left;
	cout.width(delta); cout << " ";
	cout << s;
	cout.width(delta + 1); cout << " ";

}

void printDate(unsigned short day, unsigned short month, unsigned short year, int wLine) {
	int w = 10;
	int delta = (wLine - w) / 2 - 1;
	cout << left;
	cout.width(delta); cout << " ";
	if (day > 9) {
		cout << day;
	}
	else {
		cout << "0" << day;
	}
	cout << ".";
	if (month > 9) {
		cout << month;
	}
	else {
		cout << "0" << month;
	}
	cout << ".";
	cout << year;
	cout.width(delta); cout << " ";
}

void printWhithZero(int num, int width) {
	if (num > 999 and num < 10000) {
		cout.width(width + 1);
		cout << right << "00" << num;
	}
	if (num > 9999 and num < 100000) {
		cout.width(width);
		cout << right << "0" << num;
	}
}

void Draw(struct Record* records, int elementCount) {
	int width = 78 + 9;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Каталог библиотеки"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|     Автор книги    ";
	cout << left << "|     Название   ";
	cout << left << "| Год выпуска";
	cout << left << "| Группа";
	cout << left << " | Дата подписания рукописи ";
	cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	for (int i = 0; i < elementCount; i++) {
		cout << left << "|"; cout.width(20); cout << left << records[i].author;
		cout << left << "|"; cout.width(16); cout << left << records[i].title;
		cout << left << "|"; cout.width(12); cout << left << records[i].year;
		cout << left << "|"; cout.width(8); cout << left << records[i].group;
		cout << left << "|";
		printDate(records[i].date.day, records[i].date.month, records[i].date.year, 28);
		cout << "|" << endl;
	}

	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Х – худож. лит-ра; У - учебная лит-ра; С - справочная лит-ра. "; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

void insertMaximumRecord(struct Record* Table, int* currentElementCount, int maximumElementCount) {
	if (*currentElementCount < maximumElementCount) {
		*currentElementCount = *currentElementCount + 1;
		Table[*currentElementCount - 1] = { "BRUH", "BRUH",  9999, 'B', {12,12,9999} };
	}
	else {
		cout << "Недостаточно места" << endl;
	}
}

void drawArray(Record* array, int currentElementCount) {
	int width = 78 + 9;
	cout << endl;	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Каталог библиотеки"; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');
	cout << left << "|     Автор книги    ";
	cout << left << "|     Название   ";
	cout << left << "| Год выпуска";
	cout << left << "| Группа";
	cout << left << " | Дата подписания рукописи ";
	cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' ');

	for (int i = 0; i < currentElementCount; i++) {
		cout << left << "|"; cout.width(20); cout << left << array[i].author;
		cout << left << "|"; cout.width(16); cout << left << array[i].title;
		cout << left << "|"; cout.width(12); cout << left << array[i].year;
		cout << left << "|"; cout.width(8); cout << left << array[i].group;
		cout << left << "|";
		printDate(array[i].date.day, array[i].date.month, array[i].date.year, 28);
		cout << "|" << endl;
	}

	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
	cout.fill(' '); cout.width(width);  cout << left << "|Примечание: Х – худож. лит-ра; У - учебная лит-ра; С - справочная лит-ра. "; cout << "|" << endl;
	cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int maximumElementCount = 10;
	int currentElementCount = 3;

	Record Table[10];
	Table[0] = { "Сенкевич", "Потоп", 1978, 'Х', {11,11,2020} };
	Table[1] = { "Ландау", "Механика", 1989, 'У', {11,11,2020} };
	Table[2] = { "Дойль", "Сумчатые",  1990, 'C', {12,12,2010} };

	cout << endl << "Практическая № 2 (Динамические массивы):" << endl;
	
	Record* A;
	int n = 3;
	A = (Record*) malloc(n * sizeof(Record));
	for (int i = 0; i < n; i++) {
		strcpy_s(A[i].author, Table[i].author);
		strcpy_s(A[i].title, Table[i].title);
	}

	Record** B;
	B = (Record**) new Record * [10];
	for (int i = 0; i < 10; i++) {
		B[i] = (Record*) new Record;
		*(B[i]) = Table[i];
	}

	A = (Record*) realloc(A, 10 * sizeof(Record));

	//адрес а[i], значение a[i]->строковое_поле, адрес в[i], значение в[i]->строковое_поле.
	for (int i = 0; i < 10; i++) {
		cout << endl << "адрес A[i]: " << &A[i] << " A[i]->author: " << A[i].author << " A[i]->title: " << A[i].title;
		cout << endl << "адрес B[i]: " << &B[i] << " B[i]->author: " << B[i]->author << " B[i]->title: " << B[i]->title;
	}

	for (int i = 0; i < 10; i++) {
		delete B[i];
	}
	delete[] B;
	free(A);
}