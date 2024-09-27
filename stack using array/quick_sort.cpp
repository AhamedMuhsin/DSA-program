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

void display(int arr[],int n) {
    cout << "Elements of the array: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;
    
    do{
        while (arr[i] <= pivot) {
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<j){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;
}

void quickSort(int arr[],int low,int high){
    int partionindex;
    if(low<high){
        partionindex = partition(arr, low, high);
        display(arr,10);
        quickSort(arr, low, partionindex-1);
        quickSort(arr, partionindex+1, high);
    }
}

int main(){
    int arr[100],n=0;
    inputArray(arr,n);
    display(arr,n);
    quickSort(arr,0,n-1);
    display(arr,n);
    return 0;
}