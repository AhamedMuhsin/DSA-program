#include <iostream>
using namespace std;

void inputArray(int arr[], int &n,const string &arrayName) {
    cout << "Enter the number of elements for " << arrayName << ": ";
    cin >> n;
    cout << "Enter the elements of " << arrayName << ": ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void mergeArrays(int arr1[], int n1,int arr2[], int n2, int mergedArr[], int &nMerged) {
    nMerged = n1 + n2;
    for (int i = 0; i < n1; i++) {
        mergedArr[i] = arr1[i];
    }
    for (int i = 0; i < n2; i++) {
        mergedArr[n1 + i] = arr2[i];
    }
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr1[100], arr2[100], mergedArr[200];
    int n1 = 0, n2 = 0, nMerged = 0;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input first array\n";
        cout << "2. Input second array\n";
        cout << "3. Display first array\n";
        cout << "4. Display second array\n";
        cout << "5. Merge and display sorted array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                inputArray(arr1, n1, "first array");
                break;
            case 2:
                inputArray(arr2, n2, "second array");
                break;
            case 3:
                cout << "First array: ";
                displayArray(arr1, n1);
                break;
            case 4:
                cout << "Second array: ";
                displayArray(arr2, n2);
                break;
            case 5:
                mergeArrays(arr1, n1, arr2, n2, mergedArr, nMerged);
                sortArray(mergedArr, nMerged);
                cout << "Merged and sorted array: ";
                displayArray(mergedArr, nMerged);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}

