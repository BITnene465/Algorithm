#ifndef MATRIXDECOMPOSER_H
#define MATRIXDECOMPOSER_H
// 一个功能类，实现各种矩阵分解
#include "Matrix.h"

class MatrixDecomposer
{
public:
    static std::pair<Matrix, Matrix> luDecomposition(const Matrix &A);
    static std::pair<Matrix, Matrix> SchmidtQR(const Matrix &A);
    static std::pair<Matrix, Matrix> householderReduction(const Matrix &A);
    static std::pair<Matrix, Matrix> givensReduction(const Matrix &A);
};

#endif