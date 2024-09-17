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

void traverseArray(int arr[], int n) {
	cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countArray(int arr[],int n){
    cout<<"count of array is : "<<n<<endl;
}

void sumofArray(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    cout<<"sum of array is : "<<sum<<endl;
}

void avgofArray(int arr[],int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    float avg = (float)sum / n;
    cout<<"avg of array is : "<<avg<<endl;
}

void maxofArray(int arr[],int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    cout<<"max of array is : "<<max<<endl;
}

void minofArray(int arr[],int n){
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    cout<<"min of array is : "<<min<<endl;
}

int main(){
    int arr[100],n = 0;
    inputArray(arr, n);
    traverseArray(arr, n);
    countArray(arr,n);
    sumofArray(arr,n);
    avgofArray(arr,n);
    maxofArray(arr,n);
    minofArray(arr,n);
    return 0;
}