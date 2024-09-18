#include <iostream>
using namespace std;

void deletioninArray(int arr[],int n){
	int index;
	cout<<"Enter the index which you want to delete : ";
	cin>>index;
	for(int i=index;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	cout<<"Deletion done Successfully\n";
}

int main(){
    int arr[100],n=0;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    deletioninArray(arr,n);
    n -=1;
    cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}