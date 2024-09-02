#include "MatrixDecomposer.h"
#include<iostream>
#include<cmath>

// 只关注方阵的LU分解
std::pair<Matrix, Matrix> MatrixDecomposer::luDecomposition(const Matrix &A)
{
    if (A.nRow() != A.nCol()){
        throw std::invalid_argument("非方阵无LU分解");
    }

    int n = A.nRow();
    Matrix L(n, n), U(A);
    // L对角线元素全为1
    for(int i=1;i<=n;++i)L(i, i) = 1.0;
    for(int j=1;j<=n;++j){
        if (U(j, j) == 0) throw std::invalid_argument("该方阵无LU分解");
        for(int i=j+1;i<=n;++i){
            L(i, j) = U(i, j) / U(j, j);  // 记录系数
            }
            // 对U进行 行变换
            for (int row = j + 1; row <= n; ++row)
            {
                for (int col = j; col <= n; ++col)
                {
                    U(row, col) -= U(j, col) * L(row, j);
                }
            }
    }
    return std::make_pair(L, U);
}

// 关注mxn且m>=n的矩阵的QR分解,   时间复杂度约为 O(n^3)， 此时Matrix类还未完善
std::pair<Matrix, Matrix> MatrixDecomposer::SchmidtQR(const Matrix& A){
    if(A.nRow() < A.nCol()){
        throw std::invalid_argument("非法输入");
    }
    int m = A.nRow(), n = A.nCol();

    Matrix Q(m, n), R(n, n);
    Matrix AA(A);   // 拷贝一份

    // 施密特正交化
    for(int i=1;i<=n;++i){
        R(i, i) = 1;
        for(int j=i-1;j>=1;--j){
            R(j, i) = Matrix::vec_dot(AA.getCol(i), Q.getCol(j)) / Matrix::vec_dot(Q.getCol(j), Q.getCol(j));
        }

        for(int j=1;j<=m;++j){
            double res = AA(j, i);
            for(int k=i-1;k>=1;--k){
                res -= R(k, i)*Q(j, k);    // 易错
            }
            Q(j, i) = res;
        }
    }

    // 标准化
    for(int j=1;j<=n;++j){
        double norm_j = Matrix::vec_norm(Q.getCol(j));
        for(int i=1;i<=m;++i){
            Q(i, j) /= norm_j;
        }
        for(int i=1;i<=n;++i){
            R(j, i) *= norm_j;
        }
    }

    return std::make_pair(Q, R);
}

std::pair<Matrix, Matrix> MatrixDecomposer::householderReduction(const Matrix &A)
{
    int m = A.nRow();
    int n = A.nCol();

    if (m < n)
    {
        throw std::invalid_argument("非法输入");
    }

    Matrix Q(Matrix::Identity(m, m)), R(A);
    for (int k = 1; k <= n; ++k)
    {
        Matrix x = R.subColvector(k, k, m);
        double norm_x = x.norm();
        Matrix v(Matrix::UnitVector(m - k + 1, 1));
        
        int sign_x1 = (x(1, 1) > 0)? 1: -1;
        if (x(1, 1) == 0) sign_x1 = 0;                  // 符号函数不要忘记0
        v = x + v.scalarMultiply(sign_x1 * norm_x);
        v = v.scalarMultiply(1.0 / v.norm());

        Matrix F = Matrix::HouseholderMatrix(v);
        // 拼装矩阵
        Matrix Q_k(m, m);
        for(int i=1;i<=k-1;++i) Q_k(i, i) = 1.0;
        for(int i=k;i<=m;++i)
            for(int j=k;j<=m;++j)
                Q_k(i, j) = F(i-k+1, j-k+1); 

        R = Q_k * R;             // 应用 Householder 变换到 R
        Q = Q * Q_k.transpose(); // 累积 Q 的转置

    }

    return std::make_pair(Q, R);
}

std::pair<Matrix, Matrix> MatrixDecomposer::givensReduction(const Matrix &A)
{
    int m = A.nRow();
    int n = A.nCol();

    if (m < n)
    {
        throw std::invalid_argument("非法输入");
    }

    Matrix Q(Matrix::Identity(m, m)), R(A);
    for (int j = 1; j <= n; ++j)
    {
        for (int i = m; i > j; --i)
        {
            if (R(i, j) != 0)
            {
                double angle = -std::atan2(R(i, j), R(j, j));
                Matrix G = Matrix::GivensMatrix(m, i, j, angle);

                R = G * R; // 应用 Givens 变换到 R
                Q = Q * G.transpose();             // 累积 Q
            }
        }
    }

    return std::make_pair(Q, R);
}
