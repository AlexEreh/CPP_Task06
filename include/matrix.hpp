#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector, std::sort;

class Matrix {
    int** data;
    int rows;
    int cols;
public:
    // Конструктор по умолчанию
    Matrix(): data(nullptr), rows(0), cols(0) {
    }

    // Конструктор с указанием размеров
    Matrix(int rows, int cols);

    // Конструктор копирования
    Matrix(const Matrix&other);

    // Деструктор
    ~Matrix();

    // Метод для получения количества строк
    [[nodiscard]] int getRows() const;

    // Метод для получения количества столбцов
    [[nodiscard]] int getCols() const;

    // Метод для доступа к элементу матрицы
    int& operator()(int row, int col) const;

    // Метод для транспонирования матрицы
    [[nodiscard]] Matrix transpose() const;

    // Метод для сравнения матриц
    bool operator==(const Matrix&other) const;

    // Метод для сортировки элементов по строкам
    void sortByRows() const;

    // Метод для сортировки элементов по столбцам
    void sortByCols() const;

    static void bubbleSort(int* arr, int size);

    // Дружественная функция для отображения матрицы
    friend std::ostream& operator<<(std::ostream&os, const Matrix&matrix);
};
