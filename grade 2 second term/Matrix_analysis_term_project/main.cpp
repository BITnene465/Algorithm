#include<iostream>
#include <string>
#include <sstream>
#include<fstream>
#include<cstdlib>

#include "Matrix.h"
#include "MatrixDecomposer.h"

using namespace std;

void LUdemo(const Matrix &A)
{
    cout << "Original Matrix A:\n"
         << A << endl;
    // 进行LU分解
    try
    {
        pair<Matrix, Matrix> LU = MatrixDecomposer::luDecomposition(A);
        cout << "\nLower Triangular Matrix L:\n"
             << LU.first << endl;

        cout << "\nUpper Triangular Matrix U:\n"
             << LU.second << endl;

        cout << "\nLU = \n"
             << LU.first*LU.second << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
void QRdemo(const Matrix &A)
{
    cout << "Original Matrix A:\n"
         << A << endl;
    // 进行QR分解
    try
    {
        pair<Matrix, Matrix> QR = MatrixDecomposer::SchmidtQR(A);
        cout << "\nMatrix Q:\n"
             << QR.first << endl;

        cout << "\nMatrix R:\n"
             << QR.second << endl;

        cout << "\nQR =\n"
             << QR.first * QR.second << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
void HHdemo(const Matrix &A)
{
    cout << "Original Matrix A:\n"
         << A << endl;
    // 进行QR分解
    try
    {
        pair<Matrix, Matrix> QR = MatrixDecomposer::householderReduction(A);
        cout << "\nMatrix Q:\n"
             << QR.first << endl;

        cout << "\nMatrix R:\n"
             << QR.second << endl;

        cout << "\nQR =\n"
             << QR.first * QR.second << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
void Gdemo(const Matrix &A)
{
    cout << "Original Matrix A:\n"
         << A << endl;
    // 进行QR分解
    try
    {
        pair<Matrix, Matrix> QR = MatrixDecomposer::givensReduction(A);
        cout << "\nMatrix Q:\n"
             << QR.first << endl;

        cout << "\nMatrix R:\n"
             << QR.second << endl;

        cout << "\nQR =\n"
             << QR.first * QR.second << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

Matrix readMatrix() {
    cout << "(rows cols)=";
    int rows, cols;
    cin >> rows >> cols;
    cout << "请输入" << rows << "行" <<  cols <<"列的矩阵：" << endl;
    Matrix res(rows, cols);
    for(int i=1;i<=rows;++i){
        for(int j=1;j<=cols;++j)
            cin >> res(i, j);
    }
    return res;
}

Matrix readByFile(string filename){
    ifstream file(filename);
    if (!file.is_open())
    {
        string er = "无法打开文件 " + filename;
        throw runtime_error(er);
    }

    int rows, cols;
    file >> rows >> cols;

    Matrix res(rows, cols);
    for (int i = 1; i <= rows; ++i)
        for (int j = 1; j <= cols; ++j)
            file >> res(i, j);
    file.close();
    return res;
}

int main()
{
    // mainloop
    while(true){
        cout << "1.文件输入  2.键盘输入" << endl;
        int flag;
        cin >> flag;
        if(flag==1){
            int flag;
            cout << "输入文件:";
            string fn;
            cin >> fn;
            Matrix A = readByFile(fn);
            cout << "1.LU 2.QR(Gram-Schmidt) 3.QR(Householder) 4.QR(Givens)\n";
            cin >> flag;
            switch (flag)
            {
            case 1:LUdemo(A);break;
            case 2:QRdemo(A);break;
            case 3:HHdemo(A);break;
            case 4:Gdemo(A);break;
            }
        }
        else if(flag==2){
            int flag;
            Matrix A=readMatrix();
            cout << "1.LU 2.QR(Gram-Schmidt) 3.QR(Householder) 4.QR(Givens)\n";
            cin >> flag;
            switch(flag){
                case 1:LUdemo(A);break;
                case 2:QRdemo(A);break;
                case 3:HHdemo(A);break;
                case 4:Gdemo(A);break;
            }
        }
        else{cout << "无效输入" << endl;}

        cout << "enter 'q' to quit, else continue\n";
        string cmd;
        cin >> cmd;
        if (cmd[0] == 'q')
            break;
        system("cls");
    }

    return 0;
}