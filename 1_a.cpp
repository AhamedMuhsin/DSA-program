#include <iostream>
using namespace std;

void inputArray(int arr[], int &n) {
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
	cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void searchElement(int arr[], int n){
	int element;
	cout<<"Enter the element you want to search : ";
	cin>>element;
	bool found = false;
	for (int i = 0; i < n; i++){
	    if(arr[i]==element){
	        cout<<"The Element was found at "<<i<<endl;
	        found = true;
	        break;
	    }
	}
    if(!found){
        cout<<"Element not found."<<endl;
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
    cout << "Array Sorted." << endl;
}

void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Array Reversed." << endl;
}

int main() {
    int arr[100],n = 0,choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Input array\n";
        cout << "2. Display array\n";
        cout << "3. Search element\n";
        cout << "4. Sort array\n";
        cout << "5. Reverse array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                inputArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                searchElement(arr, n);
                break;
            case 4:
                sortArray(arr, n);
                displayArray(arr, n);
                break;
            case 5:
                reverseArray(arr, n);
                displayArray(arr, n);
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

