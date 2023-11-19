#include <iostream>

#include "matrix.hpp"

int main() {
    const Matrix matrix1(3, 3);

    // Заполнение матрицы
    matrix1(0, 0) = 1;
    matrix1(0, 1) = 4;
    matrix1(0, 2) = 3;
    matrix1(1, 0) = 6;
    matrix1(1, 1) = 2;
    matrix1(1, 2) = 5;
    matrix1(2, 0) = 8;
    matrix1(2, 1) = 7;
    matrix1(2, 2) = 9;

    // Вывод исходной матрицы
    std::cout << "Исходная матрица:" << std::endl;
    std::cout << matrix1 << std::endl;

    // Транспонирование матрицы
    const Matrix transposed = matrix1.transpose();
    std::cout << "Транспонированная матрица:" << std::endl;
    std::cout << transposed << std::endl;



    const Matrix matrix2(3, 3);

    // Заполнение матрицы
    matrix2(0, 0) = 1;
    matrix2(0, 1) = 4;
    matrix2(0, 2) = 3;
    matrix2(1, 0) = 6;
    matrix2(1, 1) = 2;
    matrix2(1, 2) = 5;
    matrix2(2, 0) = 8;
    matrix2(2, 1) = 7;
    matrix2(2, 2) = 9;


    // Сравнение матриц
    if (matrix2 == matrix1) {
        std::cout << "Матрицы равны." << std::endl;
    }

    // Сортировка элементов по строкам
    matrix1.sortByRows();
    std::cout << "Матрица после сортировки элементов по строкам:" << std::endl;
    std::cout << matrix1 << std::endl;

    // Сортировка элементов по столбцам
    matrix1.sortByCols();
    std::cout << "Матрица после сортировки элементов по столбцам:" << std::endl;
    std::cout << matrix1 << std::endl;
    return 0;
}
