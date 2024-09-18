#include <iostream> 
using namespace std; 

void inputMatrix(int matrix[10][10], int row, int col,const string &matrixName) {
    cout << "Enter elements of the "<<matrixName<<":\n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[10][10], int row, int col) {
    cout<<"The stored matrix is : \n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void mulMatrix(int matrix1[10][10], int matrix2[10][10],int result[10][10],int row, int col1,int col2) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col2; ++j) {
            result[i][j]=0;
            for(int k=0;k<col1;++k){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main(){
    int i1,j1,i2,j2; 
    int m1[10][10],m2[10][10],result[10][10];
    cout<<"Enter the number of rows and columns for the first matrix : ";
    cin>>i1>>j1;
    inputMatrix(m1, i1, j1, "first Matrix");
    displayMatrix(m1,i1,j1);
    cout<<"Enter the number of rows and columns for the second matrix : ";
    cin>>i2>>j2;
    inputMatrix(m2, i2, j2, "second Matrix");
    displayMatrix(m2,i2,j2);
    i2=j1;
    mulMatrix(m1,m2,result,i1,j2,j1);
    cout<<"Resultant Matrix after multiplying first matrix and second matrix : \n";
    displayMatrix(result,i1,j2);
    return 0;
}