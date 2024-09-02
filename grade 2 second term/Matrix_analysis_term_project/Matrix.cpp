#include "Matrix.h"
#include<iostream>
#include<iomanip>
#include<cmath>

Matrix::Matrix(int rows, int cols): row(rows), col(cols), mat(row, std::vector<double>(col)) {};
Matrix::Matrix(const Matrix &A)
{
    row = A.nRow();
    col = A.nCol();
    mat = std::vector<std::vector<double>>(row, std::vector<double>(col));
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            mat[i][j] = A.mat[i][j];
        }
    }
}
Matrix::Matrix(std::initializer_list<std::initializer_list<double>> list) {
    // 获取行数和列数
    row = list.size();
    col = list.begin()->size();

    // 分配内存
    mat = std::vector<std::vector<double>>(row, std::vector<double>(col));

    // 从初始化列表中复制元素到矩阵中
    int i = 0;
    for (const auto& row_list : list) {
        // 检查每行的元素数量是否与第一行相同
        if (row_list.size() != col) {
            throw std::invalid_argument("Each row must have the same number of elements.");
        }

        int j = 0;
        for (const auto& val : row_list) {
            mat[i][j++] = val;
        }
        ++i;
    }
}

int Matrix::nRow() const {return row;}
int Matrix::nCol() const {return col;}
double& Matrix::operator()(int i, int j){return mat[i-1][j-1];}
double Matrix::operator()(int i, int j) const {return mat[i-1][j-1];}
Matrix Matrix::operator*(const Matrix &other) const
{
    int m = row, n = col, p = other.nCol();
    if (n != other.nRow())
    {
        throw std::invalid_argument("矩阵尺寸不匹配，无法进行乘法运算。");
    }

    Matrix result(m, p);
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= p; ++j)
        {
            double sum = 0.0;
            for (int k = 1; k <= n; ++k)
            {
                sum += (*this)(i, k) * other(k, j);
            }
            result(i, j) = sum;
        }
    }
    return result;
}
Matrix Matrix::transpose() const{
    Matrix res(col, row);
    for(int i=1;i<=row;i++)
        for(int j=1;j<=col;j++)
            res(j, i) = mat[i-1][j-1];
    return res;
}
std::vector<double> Matrix::getCol(int i){
    std::vector<double> res(row);
    for(int j=0;j<row;++j){
        res[j] = mat[j][i-1]; 
    }
    return res;
}
std::vector<double> Matrix::getRow(int i){
    std::vector<double> res(col);
    for(int j=0;j<col;++j){
        res[j] = mat[i-1][j];
    }
    return res;
}
double Matrix::vec_dot(const std::vector<double>& v1, const std::vector<double>& v2){
    double res = 0.0;
    for(int i=0;i<v1.size();++i){
        res += v1[i] * v2[i];
    }
    return res;
}
double Matrix::vec_norm(const std::vector<double>& v){
    double res = 0.0;
    for(double x:v){
        res += x*x;
    }
    return std::sqrt(res);
}

std::ostream &operator<<(std::ostream &os, const Matrix &matrix)
{
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2);
    for (int i = 1; i <= matrix.nRow(); ++i)
    {
        for (int j = 1; j <= matrix.nCol(); ++j)
        {
            ss << matrix(i, j) << " ";
        }
        ss << std::endl;
    }
    os << ss.str();
    return os;
}


// additional
double Matrix::norm() const
{
    double norm_squared = 0.0;
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            norm_squared += mat[i - 1][j - 1] * mat[i - 1][j - 1];
        }
    }
    return std::sqrt(norm_squared);
}

Matrix Matrix::UnitVector(int size, int idx)
{
    Matrix unitVector(size, 1);
    unitVector(idx, 1) = 1.0;
    return unitVector;
}

Matrix Matrix::scalarMultiply(double scalar) const
{
    Matrix result(row, col);
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            result(i, j) = mat[i - 1][j - 1] * scalar;
        }
    }
    return result;
}

Matrix Matrix::subColvector(int col, int start, int end) const
{
    Matrix subVec(end - start + 1, 1);
    for (int i = start; i <= end; ++i)
    {
        subVec(i - start + 1, 1) = (*this)(i, col);
    }
    return subVec;
}
Matrix Matrix::subRowvector(int row, int start, int end) const
{
    Matrix subVec(end - start + 1, 1);
    for(int i=start;i<=end;++i){
        subVec(i-start+1, 1) = (*this)(row, i); 
    }
    return subVec;
}


Matrix Matrix::HouseholderMatrix(const Matrix &v) 
{
    Matrix identity(Matrix::Identity(v.nRow(), v.nRow()));
    Matrix vvT = v * v.transpose();
    Matrix Householder = identity - vvT.scalarMultiply(2.0);
    return Householder;
}

Matrix Matrix::GivensMatrix(int n, int i, int j, double angle)
{
    Matrix G = Matrix::Identity(n, n);
    double c = std::cos(angle);
    double s = std::sin(angle);
    G(i, i) = c;
    G(j, j) = c;
    G(i, j) = s;
    G(j, i) = -s;
    return G;
}

Matrix Matrix::Identity(int row, int col){
    int n = (row < col) ? row:col;
    Matrix res(row, col);
    for(int i=1;i<=n;++i) res(i, i) = 1.0;
    return res;
}


// 重载加法运算符
Matrix Matrix::operator+(const Matrix &other) const
{
    if (row != other.row || col != other.col)
    {
        throw std::invalid_argument("矩阵尺寸不匹配，无法进行加法运算。");
    }

    Matrix result(row, col);
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            result(i, j) = (*this)(i, j) + other(i, j);
        }
    }
    return result;
}

// 重载减法运算符
Matrix Matrix::operator-(const Matrix &other) const
{
    if (row != other.row || col != other.col)
    {
        throw std::invalid_argument("矩阵尺寸不匹配，无法进行减法运算。");
    }

    Matrix result(row, col);
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            result(i, j) = (*this)(i, j) - other(i, j);
        }
    }
    return result;
}

// 重载相反数运算符
Matrix Matrix::operator-() const
{
    Matrix result(row, col);
    for (int i = 1; i <= row; ++i)
    {
        for (int j = 1; j <= col; ++j)
        {
            result(i, j) = -(*this)(i, j);
        }
    }
    return result;
}
