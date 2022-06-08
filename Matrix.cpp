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