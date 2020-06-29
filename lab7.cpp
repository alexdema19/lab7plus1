#include <iostream>
#include <clocale>
#include <math.h>
#include <stdlib.h>
#define n 5
using namespace std;

// Функция ручного ввода
void inmatr(int A[n][n]) {
	cout << "Введите элементы массива:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}
} 
//Чтение с файла

void inmatr_f(int A[n][n]) {
	FILE* fl;
	fopen_s(&fl, "File.txt", "r");
	if (fl)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				fscanf_s(fl, "%d", &A[i][j]);
		fclose(fl);
	}
	else cout << "Ошибка открытия файла. \n";
}

// Функция заполнения одномерного массива Х
void mas_x(int A[n][n], int X[]) {
	int j = 4;
	for (int i = 0; i < 5; i++) {
		if (A[i][i] > A[i][j]) {
			X[i] = 1;
		}
		else {
			X[i] = -1;
		}
	}

}

int rec_y( int A[n][n], int i, int y ) {
	if (i == 5) {
		return y;
	}
	if ((A[i][0] % 2) == 0) {}
	else {
		y = y + 1;
	}
	i++;
	return rec_y(A, i, y);
}

int main() {
	setlocale(LC_CTYPE, "Russian");
	int i, y, j, A[n][n], X[n],v;
	cout <<"Ввод элементов массива:\n С клавиатуры(1)\n С файла(2)" << endl;
	cin >> v;
	// Выбор действия
	switch (v) {
	case 1: inmatr(A); break;
	case 2: inmatr_f(A); break;
	default: cout << "Выбор не сделан!" << endl; break;
	}
	mas_x(A, X);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] <<" ";
		}
		cout << endl;
	}
	cout << endl << "X:";
	for (int i = 0; i < n; i++) {
		cout << X[i]<< " ";}
y = rec_y(A, 0, 0);
	cout << endl << "Количество нечётных чисел в первом столбце Y= " << y << endl;
	FILE* fl;
	fopen_s(&fl, "outtt.txt", "w");
	if (fl)
	{
		cout << "\n";
		fprintf(fl, "Матрица A(5x5):\n");
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
				fprintf(fl, "%3d", A[i][j]);
			fprintf(fl, "\n");
		}
		fprintf(fl, "Маccив X:\n");
		for (i = 0; i < n; i++)
			fprintf(fl, "%3d", X[i]);
		fprintf(fl, "\n");
		fprintf(fl, "Количество нечётных чисел в первом столбце Y= ");
		fprintf(fl, "%d", y);
		fclose(fl);
	}
	return 0;
}
