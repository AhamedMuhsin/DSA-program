#include <iostream>
using namespace std;

void linearSearchinArray(int arr[], int n){
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

int main(){
    int arr[100],n=0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    linearSearchinArray(arr,n);
    cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}