// c++ program to illustrate the two dimensional array 
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

void addMatrix(int matrix1[10][10], int matrix2[10][10],int result[10][10],int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
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

void transposeMatrix(int matrix[10][10],int tranpose[10][10], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            tranpose[j][i] = matrix[i][j];
        }
    }
}


int main() { 

	int i1,j1,i2,j2; 
    int m1[10][10],m2[10][10],result[10][10],transposed[10][10];
    int choice;

    do{
        cout << "\nMenu:\n";
        cout << "1. Input first Matrix\n";
        cout << "2. Display first Matrix\n";
        cout << "3. Input second Matrix\n";
        cout << "4. Display second Matrix\n";
        cout << "5. Matrix Addition\n";
        cout << "6. Matrix Multiplication\n";
        cout << "7. Transpose of Matrix\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter number of rows and columns for first matrix: ";
                cin >> i1 >> j1;
                inputMatrix(m1, i1, j1, "first Matrix");
                break;
            case 2:
                displayMatrix(m1, i1, j1);
                break;
            case 3:
                cout << "Enter number of rows and columns for second matrix: ";
                cin >> i2 >> j2;
                inputMatrix(m2,i2,j2,"second Matrix");
                break;
            case 4:
                displayMatrix(m2,i2,j2);
                break;
            case 5:
                addMatrix(m1,m2,result,i1,j1);
                cout<<"Resultant Matrix : \n";
                displayMatrix(result,i1,j1);
                break;
            case 6:
                i2=j1;
                mulMatrix(m1,m2,result,i1,j2,j1);
                cout<<"Resultant Matrix : \n";
                displayMatrix(result,i1,j2);
                break;
            case 7:
                int t;
                cout<<"Enter the matrix you want to transpose m1 or m2 : ";
                cin>>t;
                if (t==1){
                    transposeMatrix(m1,transposed,i1,j1);
                    cout<<"Transposed Matrix : \n";
                    displayMatrix(transposed,i1,j1);
                    break;
                }
                else{
                    transposeMatrix(m2,transposed,i2,j2);
                    cout<<"Transposed Matrix : \n";
                    displayMatrix(transposed,i2,j2);
                    break;
                }
            case 8:
                cout<<"Exiting Program!\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }while(choice!=8);
	return 0; 
}
