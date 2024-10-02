#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int a[],int n){
    int i,j,key;
    for(i=1;i<=n-1;i++){
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

int main(){
    int arr[100];
    int n=0;
    cout<<"enter number of element : ";
    cin >> n;
    cout<<"enter the element want to insert in array : ";
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    printArray(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}