#pragma once
#include <iostream>
#include <iomanip>

class Matrix {
private:
	typedef struct node {
		double data;
		int row;
		int col;
		node* next;

		node* copy() {
			if (this != nullptr) {
				node* temp = new node;

				temp->data = data;
				temp->row = this->row;
				temp->col = this->col;
				temp->next = this->next->copy();

				return temp;
			}

			return NULL;
		}
	} *nodePtr;

	nodePtr head;
	nodePtr end;

	int _row;
	int _col;

	double** values;

	double det(Matrix matrix, int size) const;

public:
	/// <summary>
	/// 
	/// Creates a Matrix with the given size, where the amount of rows and columns is equal to the size.
	/// 
	/// </summary>
	/// <param name="size">The given size of the matrix.</param>
	Matrix(int size) {
		head = NULL;
		end = NULL;

		this->_row = size;
		this->_col = size;

		this->values = new double*[_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = 0;
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}

				colValues[f] = 0;
			}

			values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the given size, and initializes all the values to the given value. 
	/// 
	/// </summary>
	/// <param name="size">The given size of the matrix.</param>
	/// <param name="value">The given value of the matrix.</param>
	Matrix(int size, double value) {
		head = NULL;
		end = NULL;

		this->_row = size;
		this->_col = size;
		this->values = new double* [_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = value;
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}

				colValues[f] = value;
			}

			values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the given size, and allocates the values in the 1d array to a spot in order within the matrix.
	/// 
	/// </summary>
	/// <param name="size">The given size of the matrix.</param>
	/// <param name="values">The given values of the matrix.</param>
	Matrix(int size, double values[]) {
		head = NULL;
		end = NULL;

		this->_row = size;
		this->_col = size;
		this->values = new double* [_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = values[count];
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}
				
				colValues[f] = values[count++];
			}

			this->values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the given row and column sizes
	/// 
	/// </summary>
	/// <param name="row">The given amount of rows</param>
	/// <param name="col">The given amount of columns</param>
	Matrix(int row, int col) {
		head = NULL;
		end = NULL;

		this->_row = row;
		this->_col = col;
		this->values = new double* [_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = 0;
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}
			
				colValues[f] = 0;
			}

			values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the given row and column sizes, and initializes all the values to the given value.
	/// 
	/// </summary>
	/// <param name="row">The given amount of rows.</param>
	/// <param name="col">The given amount of columns.</param>
	/// <param name="value">The given value of the matrix.</param>
	Matrix(int row, int col, double value) {
		head = NULL;
		end = NULL;

		this->_row = row;
		this->_col = col;
		this->values = new double* [_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = value;
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}

				colValues[f] = value;
			}

			values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the given row and column sizes, and allocates the values in the 1d array in order to a spot within the matrix.
	/// 
	/// </summary>
	/// <param name="row">The given amount of rows.</param>
	/// <param name="col">The given amount of columns.</param>
	/// <param name="values">The given values of the matrix.</param>
	Matrix(int row, int col, double values[]) {
		head = NULL;
		end = NULL;

		this->_row = row;
		this->_col = col;

		this->values = new double*[_row];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			double* colValues = new double[_col];
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;
				curr->data = values[count];
				curr->next = NULL;
				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}

				colValues[f] = values[count++];
			}

			this->values[i] = colValues;
		}
	}

	/// <summary>
	/// 
	/// Creates a Matrix with the same attributes of the other matrix.
	/// 
	/// --Copy Constructor--
	/// 
	/// </summary>
	/// <param name="owner">Other Matrix with initialized values.</param>
	Matrix(const Matrix& owner) {
		head = owner.head;
		end = owner.end;

		_row = owner._row;
		_col = owner._col;

		values = owner.values;
	}

	/// <summary>
	/// 
	///  Creates a Matrix with the same attributes of the other matrix.
	/// 
	/// --Copy Constructor--
	/// 
	/// </summary>
	/// <param name="owner">Other Matrix with initialized values.</param>
	Matrix(Matrix& owner) {
		head = owner.head;
		end = owner.end;

		_row = owner._row;
		_col = owner._col;

		values = owner.values;
	}

	/// <summary>
	/// 
	/// Makes a random Matrix with the given row and column sizes, and generates random values for the matrix.
	/// 
	/// </summary>
	/// <param name="row">Given amount of rows.</param>
	/// <param name="col">Given amount of columns.</param>
	/// <param name="range">Given range of the values.</param>
	/// <returns>Returns the Matrix.</returns>
	static Matrix& random(int row, int col, int range) {
		int size = row * col;
		double* values = new double[size];

		for (int i = 0; i != size; i++) {
			values[i] = rand() % range;
		}

		Matrix final(row, col, values);
		return final;
	}

	/// <summary>
	/// 
	/// Makes a identity matrix with the given size.
	/// 
	/// --Changes the matrix used on--
	/// 
	/// </summary>
	/// <param name="size">Given size of the matrix.</param>
	/// <returns>Returns the identity matrix.</returns>
	Matrix& identity(int size) {
		head = NULL;
		end = NULL;

		this->_row = size;
		this->_col = size;
		values[_row][_col];

		int count = 0;
		for (int i = 0; i != _row; i++) {
			for (int f = 0; f != _col; f++) {
				nodePtr curr = new node;

				if (f == i) {
					curr->data = 1;
					values[i][f] = 1;
				}

				else {
					curr->data = 0;
					values[i][f] = 0;
				}

				curr->row = i;
				curr->col = f;

				if (head == NULL) {
					head = curr;
					end = head;
				}

				else {
					end->next = curr;
					end = end->next;
				}

				curr = curr->next;
			}
		}

		return *this;
	}

	/// <summary>
	/// 
	/// Transposes the matrix.
	/// 
	/// --Changes the matrix used on--
	/// 
	/// </summary>
	/// <returns>Returns the transposed matrix.</returns>
	Matrix& transpose() {
		Matrix temp = Matrix(this->_col, this->_row);

		for (int i = 0; i != _row; i++) {
			for (int f = 0; f != _col; f++) {
				temp.set(f, i, get(i, f));
			}
		}

		*this = temp;

		return *this;
	}

	/// <summary>
	/// 
	/// Creates a new Matrix from the rows and columns that were not skipped.
	/// 
	/// </summary>
	/// <param name="values">Values of the Matrix.</param>
	/// <param name="size">The size of the given values array. (rows * columns)</param>
	/// <param name="p">Column to skip</param>
	/// <param name="q">Row to skip</param>
	/// <returns>Returns a sub-Matrix without the given row and column.</returns>
	Matrix& cof(double** values, int size, int p, int q) const {
		Matrix temp(size - 1);
		int j = 0;
		for (int i = 0; i != size; i++) {
			if (i == q) {
				continue;
			}

			int k = 0;
			for (int f = 0; f != size; f++) {
				if (f == p) {
					continue;
				}

				temp.set(j, k++, get(i, f));
			}

			j++;
		}

		return temp;
	}

	/// <summary>
	/// 
	/// Creates the adjointed Matrix.
	/// 
	/// --Changes the matrix used on--
	/// 
	/// </summary>
	/// <returns>Returns the adjointed matrix.</returns>
	Matrix& adj() {
		if (this->_row != this->_col) {
			throw "Incompatable Matrix";
		}

		if (_row == 1) {
			this->set(0, 0, 1);
			return *this;
		}

		Matrix adj(this->_row);

		int sign = 1;
		for (int i = 0; i != _row; i++) {
			for (int f = 0; f != _col; f++) {
				Matrix co = cof(values, _row, i, f);
				double data = sign * det(co, _row - 1);
				adj.set(f, i, data);
				sign = -sign;
			}
		}
		
		adj.transpose();
		*this = adj;

		return *this;
	}

	/// <summary>
	/// 
	/// Creates the Inverse.
	/// 
	/// --Changes the matrix used on--
	/// 
	/// </summary>
	/// <returns>Returns the inverse of the matrix.</returns>
	Matrix& inverse() {
		if (this->_row != this->_col) {
			throw "Incompatable Matrix";
		}

		double scale = det();

		if (scale == 0) {
			throw "Not Ivertable";
		}

		Matrix inv = adj();
		inv /= scale;

		*this = inv;

		return *this;
	}

	/// <summary>
	/// 
	/// WIP
	/// 
	/// </summary>
	/// <param name="other">WIP</param>
	/// <returns>WIP</returns>
	Matrix& solve(Matrix& other) {
		
	}

	/// <summary>
	/// 
	/// Sets the given row and column to the given value.
	/// 
	/// --Changes the matrix used on--
	/// 
	/// </summary>
	/// <param name="row">Given row to change.</param>
	/// <param name="col">Given column to change.</param>
	/// <param name="value">Given value to change to.</param>
	void set(int row, int col, double value);

	/// <summary>
	/// 
	/// Returns the value at the given row and column.
	/// 
	/// </summary>
	/// <param name="row">Given row to return from.</param>
	/// <param name="col">Given column to return from.</param>
	/// <returns>Returns the value at the given row and column.</returns>
	double get(int row, int col) const;

	/// <summary>
	/// 
	/// Gets the determinant of the matrix.
	/// 
	/// </summary>
	/// <returns></returns>
	double det() const;

	/// <summary>
	/// 
	/// Returns the amount of rows that make up the matrix.
	/// 
	/// </summary>
	/// <returns>Return the amount of rows.</returns>
	int row() const;

	/// <summary>
	/// 
	/// Returns the amount of colums that make up the matrix.
	/// 
	/// </summary>
	/// <returns>Return the amount of columns.</returns>
	int col() const;

	Matrix& operator=(const Matrix& owner) {
		head = owner.head;
		end = owner.end;

		_row = owner._row;
		_col = owner._col;

		values = owner.values;

		return *this;
	}

private:
	friend Matrix& operator+(Matrix& ls, Matrix& rs) {
		if (ls._row != rs._row && ls._col != rs._col) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i, f) + rs.get(i, f);

				array[count++] = value;
			}
		}

		Matrix final(ls._row, rs._col, array);
		return final;
	}

	friend Matrix& operator+=(Matrix& ls, Matrix& rs) {
		if (ls._row != rs._row && ls._col != rs._col) {
			throw "Incompatable Matricies";
		}

		if (ls._row != rs._row && ls._col != rs._col) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i % ls._row, f % ls._col) + rs.get(i % rs._row, f % rs._col);

				array[count++] = value;
			}
		}

		ls = Matrix(ls._row, ls._col, array);
		return ls;
	}

	friend Matrix& operator-(Matrix& ls, Matrix& rs) {
		if (ls._row != rs._row && ls._col != rs._col) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i, f) - rs.get(i, f);

				array[count++] = value;
			}
		}

		Matrix final(ls._row, rs._col, array);
		return final;
	}

	friend Matrix& operator-=(Matrix& ls, Matrix& rs) {
		if (ls._row != rs._row && ls._col != rs._col) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i, f) - rs.get(i % rs._row, f % rs._col);

				array[count++] = value;
			}
		}

		ls = Matrix(ls._row, ls._col, array);
		return ls;
	}

	friend Matrix& operator*(Matrix& ls, Matrix& rs) {
		if (ls._col != rs._row) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != rs._col; f++) {
				double sum = 0;
				for (int j = 0; j != rs._row; j++) {
					sum += ls.get(i, j) * rs.get(j, f);
				}

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}
	
		Matrix final(ls._row, rs._col, array);
		return final;
	}

	friend Matrix& operator*(Matrix& ls, double rs) {
		int size = ls._row * ls._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double sum = 0;
				sum += ls.get(i, f) * rs;

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}

		Matrix final(ls._row, ls._col, array);
		return final;
	}

	friend Matrix& operator*(double ls, Matrix& rs) {
		int size = rs._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != rs._row; i++) {
			for (int f = 0; f != rs._col; f++) {
				double sum = 0;
				sum += rs.get(i, f) * ls;

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}

		Matrix final(rs._row, rs._col, array);
		return final;
	}

	friend Matrix& operator*=(Matrix& ls, Matrix& rs) {
		if (ls._col != rs._row) {
			throw "Incompatable Matricies";
		}

		int size = ls._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != rs._col; f++) {
				double sum = 0;
				for (int j = 0; j != rs._row; j++) {
					sum += ls.get(i, j) * rs.get(j, f);
				}

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}

		ls = Matrix (ls._row, rs._col, array);
		return ls;
	}

	friend Matrix& operator*=(Matrix& ls, double rs) {
		int size = ls._row * ls._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double sum = 0;
				sum += ls.get(i, f) * rs;

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}

		ls = Matrix(ls._row, ls._col, array);
		return ls;
	}

	friend Matrix& operator*=(double ls, Matrix& rs) {
		int size = rs._row * rs._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != rs._row; i++) {
			for (int f = 0; f != rs._col; f++) {
				double sum = 0;
				sum += rs.get(i, f) * ls;

				if (sum < 0.0000001) {
					sum = 0;
				}

				array[count++] = sum;
			}
		}

		rs = Matrix(rs._row, rs._col, array);
		return rs;
	}

	friend Matrix& operator/(Matrix& ls, double rs) {
		if (rs == 0) {
			throw "Unusable divisor";
		}

		int size = ls._row * ls._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i, f) / rs;
				array[count++] = value;
			}
		}

		Matrix final(ls._row, ls._col, array);
		return final;
	}

	friend Matrix& operator/=(Matrix& ls, double rs) {
		if (rs == 0) {
			throw "Unusable divisor";
		}

		int size = ls._row * ls._col;
		double* array = new double[size];

		int count = 0;
		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				double value = ls.get(i, f) / rs;
				array[count++] = value;
			}
		}

		ls = Matrix(ls._row, ls._col, array);
		return ls;
	}

	friend bool operator==(Matrix& ls, Matrix& rs) {
		if (ls._row != rs._row || ls._col != rs._col) {
			return false;
		}

		for (int i = 0; i != ls._row; i++) {
			for (int f = 0; f != ls._col; f++) {
				if (ls.get(i, f) != rs.get(i, f)) {
					return false;
				}
			}
		}

		return true;
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
		os << "\n\n";
		nodePtr curr = matrix.head;

		double largest = 0;
		for (int i = 0; i != matrix._row * matrix._col; i++) {
			if (abs(curr->data) > largest) {
				largest = curr->data;
			}

			curr = curr->next;
		}

		curr = matrix.head;
		for (int i = 0; i != matrix._row && curr != NULL; i++) {
			for (int f = 0; f != matrix._col && curr != NULL; f++) {
				if (curr->data == 0) {
					curr->data = 0;
				}

				int scale;
				if (largest == 0) {
					scale = 2;
				}

				else if (largest < 1 && largest > -1) {
					scale = 6;
				}

				else {
					scale = log10(largest) + 2;
				}

				os << std::setw(scale) << (ceil(curr->data * pow(10, 3)) / pow(10, 3));

				if (f != matrix._col - 1) {
					os << ",  ";
				}

				curr = curr->next;
			}
			os << "\n";
		}

		return os;
	}
};