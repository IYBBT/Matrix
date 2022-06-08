#include "Matrix.h"
#include <iostream>

void Matrix::set(int row, int col, double value) {
	if (row > this->_row || col > this->_col) {
		throw "Out bounds";
	}

	nodePtr curr = head;
	while (curr->row != row || curr->col != col) {
		curr = curr->next;
	}

	values[row][col] = value;
	curr->data = value;
}

double Matrix::get(int row, int col) const {
	if (row > this->_row || col > this->_col) {
		throw "Out bounds";
	}

	return values[row][col];
}

double Matrix::det() const {
	if (_row != _col) {
		throw "Incompatable Matrix";
	}

	Matrix temp = *this;

	return det(temp, _row);
}

double Matrix::det(Matrix matrix, int size) const {
	if (size == 1) {
		return values[0][0];
	}

	if (size == 2) {
		return matrix.values[0][0] * matrix.values[1][1] - matrix.values[1][0] * matrix.values[0][1];
	}

	double D = 0;

	for (int i = 0; i != size; i++) {
		D += (i % 2 == 0 ? 1 : -1) * matrix.values[0][i] * det(matrix.cof(matrix.values, size, i, 0), size - 1);
	}

	return D;
}

int Matrix::row() const {
	return _row;
}

int Matrix::col() const {
	return _col;
}

int main() {
	double values[12]{ 1, 2, 3,
						4, 5, 6,
						7, 8, 9,
						10, 11, 12};

	
	double values2[9]{ 1, 2, 3,
						4, 5, 6, 
						7, 8, 9 };

	Matrix matrix(3, 4, values);
	Matrix matrix2(4, 3, values);
	Matrix adding(3, 4, values);
	Matrix matrix3(3, 3, values2);
	Matrix matrix4(1, 12, values);
	Matrix matrix5(12, 1, values);

	std::cout << "Matrix 1: " << matrix << std::endl;
	std::cout << "Matrix 2: " << matrix2 << std::endl;
	std::cout << "Matrix 4: " << matrix4 << std::endl;
	std::cout << "Matrix 5: " << matrix5 << std::endl;

	Matrix add = (matrix + matrix);
	adding += matrix;
	Matrix sub = (matrix - matrix);
	Matrix mult = (matrix4 * matrix5);

	std::cout << "Add 1 & 1: " << add << std::endl;
	std::cout << "Add 1 & adding: " << adding << std::endl;
	std::cout << "Subtract 1 & 1: " << sub << std::endl;
	std::cout << "Multiply 4 & 5: " << mult << std::endl;

	std::cout << "Matrix 3: " << matrix3 << std::endl;

	std::cout << "Matrix 2: " << matrix2 << std::endl;
	matrix2.identity(3);
	std::cout << "Matrix 2: " << matrix2 << std::endl;

	matrix2 = Matrix(4, 3, values);
	std::cout << "Get(2, 2) 2: " << matrix2.get(2, 2) << std::endl;

	std::cout << "Matrix 4: " << matrix4 << std::endl;
	matrix4.transpose();
	std::cout << "Transpose 4: " << matrix4 << std::endl;

	bool check1 = matrix == matrix2;

	std::cout << "Matrix 1: " << matrix << std::endl;
	matrix.transpose();
	std::cout << "Matrix 1: " << matrix << std::endl;
	bool check2 = matrix == matrix2;

	std::cout << "Matrix 3: " << matrix3 << std::endl;
	double determinante = matrix3.det();
	std::cout << "Determinante 3: " << determinante << std::endl;

	Matrix random = Matrix::random(3, 3, 50);
	Matrix copyRandom = random;
	std::cout << "Random: " << random << std::endl;
	determinante = random.det();
	std::cout << "Determinante Random: " << determinante << std::endl;

	Matrix iRandom = random;
	iRandom.inverse();

	Matrix mInverse = random * iRandom;
	std::cout << "Random: " << random << std::endl;
	std::cout << "Inverse Random: " << iRandom << std::endl;
	std::cout << "Multiply Random & IRandom: " << mInverse << std::endl;

	random.adj();
	std::cout << "Adjoint Random: " << random << std::endl;

	copyRandom = random;
	random.inverse();
	std::cout << "Inverse Random: " << random << std::endl;
	std::cout << "Copy Random: " << copyRandom << std::endl;

	mInverse = random * copyRandom;
	std::cout << "Multiply Random & CopyRandom: " << mInverse << std::endl;

	return 0;
}