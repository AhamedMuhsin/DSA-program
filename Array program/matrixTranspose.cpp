#include <iostream> 
using namespace std; 

void inputMatrix(int matrix[10][10], int row, int col) {
    cout << "Enter elements of the "<<":\n";
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

void transposeMatrix(int matrix[10][10],int tranpose[10][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tranpose[j][i] = matrix[i][j];
        }
    }
}

int main(){
    int i1,j1,i2,j2; 
    int m1[10][10],m2[10][10],transposed[10][10];
    cout<<"Enter the number of rows and columns of matrix : ";
    cin>>i1>>j1;
    inputMatrix(m1, i1, j1);
    displayMatrix(m1,i1,j1);
    transposeMatrix(m1,transposed,i1,j1);
    cout<<"Transposed Matrix : \n";
    displayMatrix(transposed,i1,j1);
    return 0;
}