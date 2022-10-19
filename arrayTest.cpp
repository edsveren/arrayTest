#include <iomanip>
#include <iostream>
//#include <math.h>
using namespace std;

void fill2DArray(int row, int col, int *pArr) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			while (!(cin >> *(pArr + i * col + j))) {
				cout << "error" << endl;
				cin.clear();
				cin.ignore();
			}
		}
	}
}

void fill1DArray(int row, int col, int *pArr, int *pArr1) {
	int smallest;
	if (col > 0) {
		for (int i = 0; i < col; i++) {
			smallest = *(pArr + 0 * col + i);
			pArr1[i] = smallest;
			for (int j = 0; j < row; j++) {
				int current = *(pArr + j * col + i);
				if (smallest > current) {
					smallest = current;
					pArr1[i] = smallest;
				}
			}
		}
	}
}

void print2DArray(int row, int col, int *pArr) {
	for (int i = 0; i < row; i++) {
		cout << '\n';
		for (int j = 0; j < col; j++) {
			cout << *(pArr + i * col + j) << " ";
		}
	}
}

void print1DArray(int col, int *pArr1) {
	for (int i = 0; i < col; i++) {
		cout << pArr1[i] << " ";
	}
}

int main() {
	int row;
	int col;
	cout << "Eduards Verenkovs" << endl;
	cout << "rows=";
	while (!(cin >> row)) {
		cout << "error" << endl;
		cin.clear();
		cin.ignore();
	}

	cout << "column=";
	while (!(cin >> col)) {
		cout << "error" << endl;
		cin.clear();
		cin.ignore();
	}

	int *pArr = new int[row * col];
	int *pArr1 = new int[col];

	fill2DArray(row, col, (int *)pArr);

	fill1DArray(row, col, (int *)pArr, (int *)pArr1);

	cout << "result: ";

	// print2DArray(row, col, (int *)pArr);
	print1DArray(col, (int *)pArr1);

	delete[] pArr;
	delete[] pArr1;
	return 0;
}