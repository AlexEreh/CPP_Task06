#include <gtest/gtest.h>

#include "matrix.hpp"

struct MatrixTest : testing::Test {
    std::unique_ptr<Matrix> m1;
    std::unique_ptr<Matrix> m1transposed;
    std::unique_ptr<Matrix> m2;

    void TearDown() override {
        delete m1;
        delete m2;
    }
    void SetUp() override {
        m1 = std::make_unique<Matrix>(3, 3);
        m1->operator()(0, 0) = 1;
        m1->operator()(0, 1) = 4;
        m1->operator()(0, 2) = 3;
        m1->operator()(1, 0) = 6;
        m1->operator()(1, 1) = 2;
        m1->operator()(1, 2) = 5;
        m1->operator()(2, 0) = 8;
        m1->operator()(2, 1) = 7;
        m1->operator()(2, 2) = 9;

        m1transposed = std::make_unique<Matrix>(3, 3);
        m1transposed->operator()(0, 0) = 1;
        m1transposed->operator()(0, 1) = 6;
        m1transposed->operator()(0, 2) = 8;
        m1transposed->operator()(1, 0) = 4;
        m1transposed->operator()(1, 1) = 2;
        m1transposed->operator()(1, 2) = 7;
        m1transposed->operator()(2, 0) = 3;
        m1transposed->operator()(2, 1) = 5;
        m1transposed->operator()(2, 2) = 9;

        m2 = std::make_unique<Matrix>(3, 3);
        m2->operator()(0, 0) = 1;
        m2->operator()(0, 1) = 4;
        m2->operator()(0, 2) = 3;
        m2->operator()(1, 0) = 6;
        m2->operator()(1, 1) = 2;
        m2->operator()(1, 2) = 5;
        m2->operator()(2, 0) = 8;
        m2->operator()(2, 1) = 7;
        m2->operator()(2, 2) = 9;
    }
};

TEST_F(MatrixTest, transposeEquals) {
    const Matrix actual = m1->transpose();
    ASSERT_EQ(*m1transposed, actual);
}