#include "matrix.hpp"

Matrix::Matrix(const int rows, const int cols) {
    this->rows = rows;
    this->cols = cols;
    this->data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new int[cols];
    }
    for (int i = 0; i < rows; ++i) {
        const auto rowPtr = this->data[i];
        for (int j = 0; j < cols; ++j) {
            rowPtr[j] = 0;
        }
    }
}

Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    data = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other(i, j);
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;
    rows = 0;
    cols = 0;
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    if (rows == 0) {
        return 0;
    }
    return cols;
}

int& Matrix::operator()(const int row, const int col) const {
    if (row < 0 || row >= getRows() || col < 0 || col >= getCols()) {
        throw std::out_of_range("Invalid matrix index!");
    }
    return data[row][col];
}

Matrix Matrix::transpose() const {
    Matrix transposed(getCols(), getRows());
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            transposed.data[j][i] = data[i][j];
        }
    }
    return transposed;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows) return false;
    if (cols != other.cols) return false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            const int thisElement = data[i][j];
            const int otherElement = other.data[i][j];
            if (thisElement != otherElement) return false;
        }
    }
    return true;
}

void Matrix::sortByRows() const {
    for (int i = 0; i < getRows(); i++) {
        int* row = new int[cols];
        for (int j = 0; j < cols; ++j) {
            row[j] = data[i][j];
        }
        bubbleSort(row, cols);
        for (int j = 0; j < cols; ++j) {
            data[i][j] = row[j];
        }
        delete[] row;
    }
}

void Matrix::sortByCols() const {
    for (int j = 0; j < getCols(); j++) {
        int* column = new int[rows];

        for (int i = 0; i < getRows(); i++) {
            column[i] = data[i][j];
        }
        bubbleSort(column, rows);
        for (int i = 0; i < getRows(); i++) {
            data[i][j] = column[i];
        }
        delete[] column;
    }
}

void Matrix::bubbleSort(int* arr, const int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swapping elements
                const int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0; i < matrix.getRows(); i++) {
        for (int j = 0; j < matrix.getCols(); j++) {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
