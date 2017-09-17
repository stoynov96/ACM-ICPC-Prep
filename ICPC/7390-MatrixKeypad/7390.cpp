#include <iostream>
#include <vector>

template <class arrType>
void init2DArr(short x, short y, arrType ** &arr);
template <class arrType>
void disp2DArr(short x, short y, arrType ** &arr);

void getFirstOneCoords(char** chr, short r, short c, short &oneRow, short &oneCol);
bool checkIfPossible(char** chr, short r, short c, short oneRow);

void solution () {
	// Variable declaration
	short r,c;
	char ** chr;

	std::vector <short> usedRows;
	std::vector <short> usedCols;

	short oneRow = 0, oneCol = 0;

	// Input collection
	std::cin >> r >> c;

	// Initialization
	init2DArr(r,c,chr);	

	for (short i = 0; i < r; i++)
		for (short j = 0; j < c; j++) {
			std::cin >> chr[i][j];
		}
	getFirstOneCoords(chr,r,c,oneRow,oneCol);
	// Check if impossible
	if (!checkIfPossible(chr,r,c,oneRow)) { std::cout << "impossible\n----------\n"; return; }
	// Altering array
	for (short i = oneRow; i < r; i++) {
		if (chr[i][oneCol] == '1') {
			usedRows.push_back(i);
		}
	}
	for (short i = oneCol; i < c; i++) {
		if (chr[oneRow][i] == '1') {
			usedCols.push_back(i);
		}
	}

	// Change all array values to 'N'
	for (short i = 0; i < r; i++)
		for (short j = 0; j < c; j++)
			chr[i][j] = 'N';
	// Change appropriate array values to 'I' or 'P'
	char repChar = (usedRows.size() <= 1 || usedCols.size() <= 1) ? 'P' : 'I';
	for (short i = 0; i < usedRows.size(); i++)
		for (short j = 0; j < usedCols.size(); j++)
			chr[usedRows[i]][usedCols[j]] = repChar;

	// Display
	disp2DArr(r,c,chr);
	std::cout << "----------\n";

}

int main() {
	short t;
	std::cin >> t;
	for (short i = 0; i < t; i++) solution();
}

template <class arrType>
void init2DArr(short r, short c, arrType ** &arr) {
	arr = new arrType* [r];
	for (short i = 0; i < r; i++) {
		arr[i] = new arrType [c];
	}
}
template <class arrType>
void disp2DArr(short r, short c, arrType ** &arr) {
	for (short i = 0; i < r; i++) {
		for (short j = 0; j < c; j++) {
			std::cout << arr[i][j];
		}
		std::cout << '\n';
	}
}

void getFirstOneCoords(char** chr, short r, short c, short &oneRow, short &oneCol) {
	for (short i = 0; i < r; i++)
		for (short j = 0; j < c; j++)
			if (chr[i][j] == '1') {
				oneRow = i; oneCol = j; return;
			}
}

bool checkIfPossible(char** chr, short r, short c, short oneRow) {
	short zeroCount = 0;
	bool flag = false;
	for (short i = oneRow+1; i < r; i++) {
		zeroCount = 0;
		flag = false;
		for (short j = 0; j < c; j++) {
			if (chr[i][j] == '0') zeroCount ++;
			if (chr[i][j] != chr[oneRow][j]) flag = true;
		}
		if (flag && zeroCount != c) return false;
	}
	return true;
}
