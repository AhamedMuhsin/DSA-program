#include <iostream>
using namespace std;

void merge_sorted_arrays(int a1[], int m, int a2[], int n, int a3[]){
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) {
        if (a1[i] < a2[j]) {
            a3[k] = a1[i];
            i++;
        } else {
            a3[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < m) {
        a3[k] = a1[i];
        i++;
        k++;
    }
    while (j < n) {
        a3[k] = a2[j];
        j++;
        k++;
    }
    cout<<"merge Sorted\n";
}

void input(int arr[],int &n,const string &arrayName){
    cout << "Enter the number of element " << arrayName << ": \n";
    cin >> n;
    cout << "Enter the elements of " << arrayName << ": \n";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
}

void display(int arr[],int n){
    cout << "The stored array is: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
// Example usage:
int main() {
    const int MAX_SIZE = 100;
    int a1[MAX_SIZE],a2[MAX_SIZE];;
    int m = sizeof(a1) / sizeof(a1[0]);
    int n = sizeof(a2) / sizeof(a2[0]);
    int a3[m+n],choice;
    do{
        cout << "\nMenu:\n";
        cout << "1. Input first array\n";
        cout << "2. Display second array\n";
        cout << "3. Input second array\n";
        cout << "4. Display second array\n";
        cout << "5. Merge Sort array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                input(a1,m,"first array");
                break;
            case 2:
                display(a1,m);
                break;
            case 3:
                input(a2,n,"second array");
                break;
            case 4:
                display(a2,n);
                break;
            case 5:
                merge_sorted_arrays(a1,m,a2,n,a3);
                display(a3,m+n);
                break;
            case 6:
                cout<<"Exiting Program\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    }while(choice!=6);
    return 0;
}