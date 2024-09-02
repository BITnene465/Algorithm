#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<iostream>
class Matrix{
private:

    int row, col;
    std::vector<std::vector<double>> mat;
public:
    Matrix(int rows, int cols);
    Matrix(const Matrix& A);  // copy constructor
    Matrix(std::initializer_list<std::initializer_list<double>> list);   // 初始化列表构造函数
    int nRow() const;
    int nCol() const;
    double& operator()(int i, int j);    // 返回引用
    double operator()(int i, int j) const;  // 返回值
    Matrix operator*(const Matrix& other) const;
    Matrix transpose() const;
    std::vector<double> getCol(int i);
    std::vector<double> getRow(int i);
    static double vec_dot(const std::vector<double>& v1, const std::vector<double>& v2);  // 向量内积
    static double vec_norm(const std::vector<double>& v);   // 向量的 2-范数

    // additional
    double norm() const;
    static Matrix UnitVector(int size, int idx);
    Matrix scalarMultiply(double scalar) const;
    Matrix subColvector(int col, int start, int end) const;
    Matrix subRowvector(int row, int start, int end) const;
    static Matrix HouseholderMatrix(const Matrix &v);
    static Matrix GivensMatrix(int n, int i, int j, double angle);
    static Matrix Identity(int row, int col);

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator-() const;

    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix); // 重构标准输出
};

#endif