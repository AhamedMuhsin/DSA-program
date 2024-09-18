#include <iostream>
using namespace std;

void binarySearchinArray(int arr[],int n){
	int element;
	cout<<"Enter the element you want to search : ";
	cin>>element;
	bool found = false;
	int lb,ub,mid;
	lb = 0;
	ub = n-1;
	while(lb<=ub){
		mid=(lb+ub)/2;
		if(arr[mid]==element){
			cout<<"The Element was found at "<<mid<<endl;
			found = true;
			break;
		}
		if(arr[mid]<element){
			lb=mid+1;
		}
		else{
			ub=mid-1;
		}
	}
	if(!found){
		cout<<"The Element was not found."<<endl;
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
    binarySearchinArray(arr,n);
    cout<<"The Stored values in array is : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
